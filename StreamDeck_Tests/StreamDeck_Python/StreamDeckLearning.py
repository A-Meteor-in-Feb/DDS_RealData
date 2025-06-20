import threading
import time
import keyboard as kb
import os
from keyboard import add_hotkey
from PIL import Image, ImageDraw, ImageFont
from StreamDeck.DeviceManager import DeviceManager
from StreamDeck.ImageHelpers import PILHelper

import rti.connextdds as dds
from data import statistic_data
from data import streamdeck_buttons_data
from data import partition_data

# Folder location of image assets used by this program
ASSETS_PATH = os.path.join(os.path.dirname(__file__), "images")

# Define gear button mappings with priority based on order (P > N > D > R)
GEAR_BUTTONS = {
    6: 'P',
    5: 'N',
    10: 'D',
    0: 'R'
}

# Define image file mappings
IMAGE_FILES = {
    'P_select': 'images/P_select.png',
    'P_unselect': 'images/P_unselect.png',
    'R_select': 'images/R_select.png',
    'R_unselect': 'images/R_unselect.png',
    'N_select': 'images/N_select.png',
    'N_unselect': 'images/N_unselect.png',
    'D_select': 'images/D_select.png',
    'D_unselect': 'images/D_unselect.png',
    'auto': 'images/auto.png',
    'manual': 'images/manual.png'
}

# Initialize the current gear to "Park"
current_gear = 'P'

# Flags for main loop updates
gear_update_needed = False
selected_gear = current_gear

# Desired serial number
DESIRED_SERIAL_NUMBER = "A00SA3462OG542"

# Initialize button states as a 16-bit integer
button_states = 64

control_partition_name = ""

count_sentMsg = 0
count_recvMsg = 0

exit_flag = False

def read_streamdeck():

    streamdecks = DeviceManager().enumerate()

    print("Found {} StreamDeck(s).\n".format(len(streamdecks)))

    if len(streamdecks) == 0:
        print("No StreamDecks detected.")
        return None

    for streamdeck in streamdecks:
        streamdeck.open()
        if streamdeck.get_serial_number() == DESIRED_SERIAL_NUMBER:
            streamdeck.reset()
            streamdeck.set_brightness(100)
            return streamdeck
        streamdeck.close()

    print("No StreamDeck found with the serial number.")
    return None


def show_text(deck, button, text, font_size, centered=False):
    image = Image.new('RGB', (72, 72), color='black')
    draw = ImageDraw.Draw(image)
    font_path = os.path.join(ASSETS_PATH, "arial.ttf")
    font = ImageFont.truetype(font_path, font_size)
    text_position = (image.width / 2, image.height / 2 + font_size / 4) if centered else (image.width / 2, image.height / 2 - font_size / 4)
    draw.text(text_position, text=text, font=font, anchor="ms", spacing=font_size / 2, align="center", fill="white")
    image = image.rotate(-90, expand=True)
    native_image = PILHelper.to_native_key_format(deck, image)
    deck.set_key_image(button, native_image)


def set_button_image(deck, button, state):
    icon_path = IMAGE_FILES[GEAR_BUTTONS[button]+'_'+state]
    icon = Image.open(icon_path).rotate(-90, expand=True)
    image = PILHelper.create_scaled_key_image(deck, icon)
    native_image = PILHelper.to_native_key_format(deck, image)
    deck.set_key_image(button, native_image)


def update_button_state(button, pressed):
    global button_states
    if pressed:
        button_states |= (1 << button)
    else:
        button_states &= ~(1 << button)


def set_mode_image(deck, button, mode):
    icon_path = IMAGE_FILES[mode]
    icon = Image.open(icon_path).rotate(-90, expand=True)
    image = PILHelper.create_scaled_key_image(deck, icon)
    native_image = PILHelper.to_native_key_format(deck, image)
    deck.set_key_image(button, native_image)


def update_gear(deck, selected_gear):
    global current_gear
    if current_gear != selected_gear:
        set_button_image(deck, list(GEAR_BUTTONS.keys())[list(GEAR_BUTTONS.values()).index(current_gear)], 'unselect')
        current_gear = selected_gear
        set_button_image(deck, list(GEAR_BUTTONS.keys())[list(GEAR_BUTTONS.values()).index(current_gear)], 'select')
        return True
    return False


def exit_program(deck):
    global exit_flag
    print("Exiting program.")
    if deck:
        deck.set_brightness(40)
        deck.reset()
        deck.close()
    exit_flag = True
    os._exit(0)


def hotkey_listener(streamdeck):
    add_hotkey('q', lambda: exit_program(streamdeck))
    while not exit_flag:
        time.sleep(0.1)


def main(participant, control_partition_name, streamdeck):
    global gear_update_needed, selected_gear, count_sentMsg, count_recvMsg

    initialize = False

    publisher_qos = dds.PublisherQos(participant.default_publisher_qos)
    publisher_qos.partition.name = [control_partition_name]
    publisher = dds.Publisher(participant, publisher_qos)
    topic = dds.Topic(participant, "streamdeck_buttons_data", streamdeck_buttons_data)
    writer = dds.DataWriter(publisher, topic)
    button_data = streamdeck_buttons_data()
    button_data.buttons = button_states
    print("Writing streamdeck_buttons_data")
    writer.write(button_data)

    timestamp_s = time.time()
    formatted_time_s = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(timestamp_s))
    file_name_s = "send_msg.txt"
    with open(file_name_s, "a") as file:
        file.write(f"Timestamp: {timestamp_s}, Formatted: {formatted_time_s}\n")
    count_sentMsg += 1

    show_text(streamdeck, 8, "Connecting", 14, centered=True)

    message = [0, 0, 0]
    last_received_time = time.time()
    height = None
    depth = None
    auto_flag = None
    last_height = height
    last_depth = depth
    last_mode = auto_flag

    @streamdeck.set_key_callback
    def key_callback(deck, key, state):
        print("deck", deck, "key", key, "state", state)
        global button_states, gear_update_needed, selected_gear
        previous_button_states = button_states
        if key in GEAR_BUTTONS:
            if state:
                selected_gear = GEAR_BUTTONS[key]
                gear_update_needed = True
                update_button_state(key, True)
                for other_key in GEAR_BUTTONS:
                    if other_key != key:
                        update_button_state(other_key, False)
        else:
            update_button_state(key, state)

        if button_states != previous_button_states:
            button_data.buttons = button_states
            print("Writing streamdeck_buttons_data")
            writer.write(button_data)

            timestamp_s = time.time()
            formatted_time_s = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(timestamp_s))
            file_name_s = "send_msg.txt"
            with open(file_name_s, "a") as file:
                file.write(f"Timestamp: {timestamp_s}, Formatted: {formatted_time_s}\n")
            count_sentMsg += 1


    try:

        subscriber_qos = dds.SubscriberQos(participant.default_subscriber_qos)
        subscriber_qos.partition.name = [control_partition_name]
        subscriber = dds.Subscriber(participant, subscriber_qos)
        statistic_topic = dds.Topic(participant, "statistic_data", statistic_data)
        reader = dds.DataReader(subscriber, statistic_topic)

        while not exit_flag:
            current_time = time.time()

            samples = reader.take()

            if len(samples) > 0:
                timestamp_r = time.time()
                formatted_time_r = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(timestamp_r))
                file_name_r = "receive_msg.txt"
                with open(file_name_r, "a") as file:
                    file.write(f"Timestamp: {timestamp_r}, Formatted: {formatted_time_r}\n")
                count_recvMsg += 1

                for sample in samples:
                    message[0] = sample.__dict__['height']
                    message[1] = sample.__dict__['depth']
                    message[2] = sample.__dict__['auto_flag']
                    print("Received message: ")
                    print(sample)


            if not initialize:
                for button in GEAR_BUTTONS:
                    set_button_image(streamdeck, button, 'unselect')

                set_button_image(streamdeck, list(GEAR_BUTTONS.keys())[list(GEAR_BUTTONS.values()).index(current_gear)], 'select')
                show_text(streamdeck, 8, "", 22)
                update_button_state(list(GEAR_BUTTONS.keys())[list(GEAR_BUTTONS.values()).index(current_gear)], True)
                initialize = True

            height = message[0]
            depth = message[1]
            auto_flag = message[2]
            last_received_time = current_time


            if gear_update_needed:
                update_gear(streamdeck, selected_gear)
                gear_update_needed = False
            
            if height != last_height:
                show_text(streamdeck, 9, "Height:\n"+f"{float(height):.2f}"+"m", 22)
                last_height = height
            if depth != last_depth:
                show_text(streamdeck, 14, "Depth:\n"+f"{float(depth):.2f}"+"m", 22)
                last_depth = depth
            if auto_flag != last_mode:
                set_mode_image(streamdeck, 4, 'auto' if str(auto_flag) == '1' else 'manual')
                last_mode = auto_flag
            
            if current_time - last_received_time > 0.5:
                if height is not None or depth is not None or auto_flag is not None:
                    height, depth, auto_flag, last_height, last_depth, last_mode = None, None, None, None, None, None
                    show_text(streamdeck, 9, "Height:\nN/A", 22)
                    show_text(streamdeck, 14, "Depth:\nN/A", 22)
                    show_text(streamdeck, 4, "NA", 22, centered=True)
                    print("Cleared height and depth due to timeout")


    except KeyboardInterrupt:
        print("Totally sent buttons data: ", count_sentMsg)
        print("Totally received data: ", count_recvMsg)
        exit_program(streamdeck)
    except Exception:
        print("Exception in main loop")
    finally:
        print("Totally sent buttons data: ", count_sentMsg)
        print("Totally received data: ", count_recvMsg)
        exit_program(streamdeck)



if __name__ == "__main__":
    print(ASSETS_PATH)

    streamdeck = read_streamdeck()
    if not streamdeck:
        exit(0)

    listener_thread = threading.Thread(target=lambda: hotkey_listener(streamdeck))
    listener_thread.start()

    tele_id = int(input("What's the corresponding teleop id: "))
    streamdeck_name = "streamdeck_tele" + str(tele_id)

    domain_id = 1
    participant = dds.DomainParticipant(domain_id)
    sub_qos = dds.SubscriberQos(participant.default_subscriber_qos)
    sub_qos.partition.name = [streamdeck_name]
    subscriber = dds.Subscriber(participant, sub_qos)
    partition_topic = dds.Topic(participant, "partition_data", partition_data)
    reader = dds.DataReader(subscriber, partition_topic)
    while control_partition_name == "" and not exit_flag:
        samples = reader.take()
        if len(samples) > 0:
            for sample in samples:
                control_partition_name = sample.__dict__['name']

    print(control_partition_name)
    main(participant, control_partition_name, streamdeck)
import time
import keyboard as kb
import os
from PIL import Image, ImageDraw, ImageFont
from StreamDeck.DeviceManager import DeviceManager
from StreamDeck.ImageHelpers import PILHelper

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
DESIRED_SERIAL_NUMBER = "DL41L2A41032"

# Initialize button states as a 16-bit integer
button_states = 64


def read_streamdeck():

    ''' DeviceManager().enumerate():

        Detect attached StreamDeck devices.
        Return type: list(StreamDeck)
        Returns: list of StreamDeck instances, one for each detected device.
    '''
    streamdecks = DeviceManager().enumerate()

    print("Found {} StreamDeck(s).\n".format(len(streamdecks)))

    if len(streamdecks) == 0:
        print("No StreamDecks detected.")
        return None

    for streamdeck in streamdecks:
        streamdeck.open()
        if streamdeck.get_serial_number() == DESIRED_SERIAL_NUMBER:
            print("Success :)")
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


def main():
    global gear_update_needed, selected_gear

    streamdeck = read_streamdeck()
    if not streamdeck:
        return

    initialize = False

    ####################################### TO-DO ###################################################
    #send the initial button value  ----->>>> str(button_states)
    #send_initial_button_states(pair_socket) 
    '''
        This function is to utilize socket to send initial button states. 
        However, why do we need to send the initial button states and --- MAYBE this question is unimportant...
        Do we need to use DDS to send initial button states to ... who or which device. --- obviously, to the controller side, that is, the teleoperation side.
    '''
    ##################################################################################################

    show_text(streamdeck, 8, "Connecting", 14, centered=True)

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
        
        ########################################## TO-DO ########################################
        #This place, I think you need to transmit data to controller side via DDS 
        #if button_states != previous_button_states:
            #pair_socket.send_string(str(button_states))
            #send the updated button state
        ##########################################################################################
    
    kb.add_hotkey('q', lambda: exit_program(streamdeck))
    
    def exit_program(deck):
        print("Exiting program.")
        if deck:
            deck.set_brightness(40)
            deck.reset()
            deck.close()
        os._exit(0)


    try: 
        while True:
            current_time = time.time()
            
            try:

                #message = reciever in DDS to receive message
                message = "0.22"
                print("Received message ", message)

                if not initialize:
                    for button in GEAR_BUTTONS:
                        set_button_image(streamdeck, button, 'unselect')

                    set_button_image(streamdeck, list(GEAR_BUTTONS.keys())[list(GEAR_BUTTONS.values()).index(current_gear)], 'select')
                    show_text(streamdeck, 8, "", 22)
                    update_button_state(list(GEAR_BUTTONS.keys())[list(GEAR_BUTTONS.values()).index(current_gear)], True)
                    initialize = True

                height = message #keep the first two decimal numbers. then convert it into string
                depth = message  #keep the first two deciaml numbers. then convert it into string
                auto_flag = '1'
                last_received_time = current_time
            except Exception as e:
                print("Exception", e)

            if gear_update_needed:
                update_gear(streamdeck, selected_gear)
                gear_update_needed = False
            
            if height != last_height:
                show_text(streamdeck, 9, "Height:\n"+height+"m", 22)
                last_height = height
            if depth != last_depth:
                show_text(streamdeck, 14, "Depth:\n"+depth+"m", 22)
                last_depth = depth
            if auto_flag != last_mode:
                set_mode_image(streamdeck, 4, 'auto' if auto_flag == '1' else 'manual')
                last_mode = auto_flag
            
            if current_time - last_received_time > 0.5:
                if height is not None or depth is not None or auto_flag is not None:
                    height, depth, auto_flag, last_height, last_depth, last_mode = None, None, None, None, None, None
                    show_text(streamdeck, 9, "Height:\nN/A", 22)
                    show_text(streamdeck, 14, "Depth:\nN/A", 22)
                    show_text(streamdeck, 4, "NA", 22, centered=True)
                    print("Cleared height and depth due to timeout")


            time.sleep(0.01)

    except KeyboardInterrupt:
        pass
    except Exception:
        print("Exception in main loop")
    finally:
        exit_program(streamdeck)



if __name__ == "__main__":
    print(ASSETS_PATH)
    main()
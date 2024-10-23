
# WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

# This file was generated from data.idl
# using RTI Code Generator (rtiddsgen) version 4.3.0.
# The rtiddsgen tool is part of the RTI Connext DDS distribution.
# For more information, type 'rtiddsgen -help' at a command shell
# or consult the Code Generator User's Manual.

from dataclasses import field
from typing import Union, Sequence, Optional
import rti.idl as idl
from enum import IntEnum
import sys
import os


@idl.struct(
    member_annotations = {
        'tin': [idl.bound(255)],
    }
)
class steeringWheel_data:
    tin: str = ""
    lX: idl.int32 = 0
    lY: idl.int32 = 0
    lRz: idl.int32 = 0
    rglSlider_0: idl.int32 = 0
    buttons: idl.uint32 = 0

@idl.struct(
    member_annotations = {
        'tin': [idl.bound(255)],
        'rglSlider': [idl.bound(2)],
    }
)
class joyStick_data:
    tin: str = ""
    lX: idl.int32 = 0
    lY: idl.int32 = 0
    lZ: idl.int32 = 0
    lRx: idl.int32 = 0
    lRy: idl.int32 = 0
    lRz: idl.int32 = 0
    buttons: idl.uint32 = 0
    rglSlider: Sequence[idl.int32] = field(default_factory = idl.array_factory(idl.int32))

@idl.struct
class streamdeck_buttons_data:
    buttons: idl.int16 = 0

@idl.struct
class statistic_data:
    height: float = 0.0
    depth: float = 0.0
    auto_flag: idl.int16 = 0

@idl.struct(
    member_annotations = {
        'vin': [idl.bound(255)],
        'acc': [idl.bound(3)],
        'gyro': [idl.bound(3)],
        'angle': [idl.bound(3)],
        'mag': [idl.bound(3)],
    }
)
class IMU_data:
    vin: str = ""
    acc: Sequence[float] = field(default_factory = idl.array_factory(float))
    gyro: Sequence[float] = field(default_factory = idl.array_factory(float))
    angle: Sequence[float] = field(default_factory = idl.array_factory(float))
    mag: Sequence[float] = field(default_factory = idl.array_factory(float))

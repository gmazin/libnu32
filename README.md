libnu32
===================

An abstraction library for the PIC32-based NU32 microcontroller.
--------------------

In an effort to make the NU32 more "Arduino-like" and easier to use for those who may not necessarily want to deal with the internals of the NU32 (such as Design Competition students) I have started this project which aims to add simple functions for common components.

In order to use:
- Download MPLAB X and the XC32 compiler and install.
- Download this code, and add it as a project in MPLAB X.
- Open main.c and add some code! Be sure to include header files for components you are using.

Currently supported components:
- Servo
- PWM motors  (bidirection and single directional)
- Various NU32 functions, such as serial input and output
- Ultrasonic sensors
- Digital input/output for any such device (LED, relays, etc)
- Analog input (read potentiometer value, IR detector...)

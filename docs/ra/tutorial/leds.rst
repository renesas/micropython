Turning on LEDs and basic Python concepts
=========================================

The easiest thing to do on the raboard is to turn on the LEDs attached to the board. Connect the board, and log in as described in tutorial 1. We will start by turning and LED on in the interpreter, type the following ::

    >>> myled = pyb.LED(1)
    >>> myled.on()
    >>> myled.off()

These commands turn the LED on and off.

This is all very well but we would like this process to be automated. Open the file MAIN.PY on the raboard in your favourite text editor. Write or paste the following lines into the file. If you are new to python, then make sure you get the indentation correct since this matters! ::

    led = pyb.LED(2)
    while True:
        led.toggle()
        pyb.delay(1000)

When you save, the red light on the raboard should turn on for about a second. To run the script, do a soft reset (CTRL-D). The raboard will then restart and you should see a green light continuously flashing on and off. Success, the first step on your path to building an army of evil robots! When you are bored of the annoying flashing light then press CTRL-C at your terminal to stop it running.

So what does this code do? First we need some terminology. Python is an object-oriented language, almost everything in python is a *class* and when you create an instance of a class you get an *object*. Classes have *methods* associated to them. A method (also called a member function) is used to interact with or control the object.

The first line of code creates an LED object which we have then called led. When we create the object, it takes a single parameter which must be between 1 and 4, corresponding to the 4 LEDs on the board. The pyb.LED class has three important member functions that we will use: on(), off() and toggle(). The other function that we use is pyb.delay() this simply waits for a given time in milliseconds. Once we have created the LED object, the statement while True: creates an infinite loop which toggles the led between on and off and waits for 1 second.

**Exercise: Try changing the time between toggling the led and turning on a different LED.**

**Exercise: Connect to the raboard directly, create a pyb.LED object and turn it on using the on() method.**

LED On/Off
----------

So far we have only used a single LED but the raboard has 4 available. Let's start by creating an object for each LED so we can control each of them. We do that by creating a list of LEDS with a list comprehension. ::

    leds = [pyb.LED(i) for i in range(1,3)] for EK-RA6M2

    leds = [pyb.LED(i) for i in range(1,2)] for RA4M1 Clicker

If you call pyb.LED() with a number that isn't 1,2,3,4 you will get an error message.
Next we will set up an infinite loop that cycles through each of the LEDs turning them on and off. ::

    [EK-RA6M2]
    n = 0
    while True:
        n = (n + 1) % 2
        leds[n].toggle()
        pyb.delay(50)

    [RA4M1 Clicker]
    import time

    while True:
        leds[1].toggle()
        time.sleep_ms(50)

Here, n keeps track of the current LED and every time the loop is executed we cycle to the next n (the % sign is a modulus operator that keeps n between 0 and 3.) Then we access the nth LED and toggle it. If you run this you should see each of the LEDs turning on then all turning off again in sequence.


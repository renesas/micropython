MicroPython port to Renesas RA MCUs
===================================

This directory contains the port of MicroPython to Renesas's line of RA
microcontrollers.  Supported MCU series are: RA4M1 and RA6M2.
Some codes for RA4W1 and RA6M1 are included, but not tested. 
Parts of Reneasa FSP library are used as git submodule.

The officially supported boards are the line of pyboards: 

    RA4M1 Clicker board
    (https://www.mikroe.com/ra4m1-clicker)

    EK-RA6M2 board
    (https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra6m2-ra6m2-mcu-group-evaluation-board)

See the boards/ subdirectory, which contains the configuration files used
to build each individual board.

Build instructions
------------------

Before building the firmware for a given board the MicroPython cross-compiler
must be built; it will be used to pre-compile some of the built-in scripts to
bytecode.  The cross-compiler is built and run on the host machine, using:
```bash
$ make -C mpy-cross
```
This command should be executed from the root directory of this repository.
All other commands below should be executed from the ports/stm32/ directory.

An ARM compiler is required for the build, along with the associated binary
utilities.  The default compiler is `arm-none-eabi-gcc`, which is available for
Arch Linux via the package `arm-none-eabi-gcc`, for Ubuntu via instructions
[here](https://launchpad.net/~team-gcc-arm-embedded/+archive/ubuntu/ppa), or
see [here](https://launchpad.net/gcc-arm-embedded) for the main GCC ARM
Embedded page.  The compiler can be changed using the `CROSS_COMPILE` variable
when invoking `make`.

First the submodules must be obtained using:

    $ make submodules

Then to build for a given board, run:

    $ make BOARD=RA6M2_EK

The default board is RA6M2_EK but any of the names of the subdirectories in the
`boards/` directory can be passed as the argument to `BOARD=`.  The above command
should produce binary images in the `build-RA6M2_EK/` subdirectory (or the
equivalent directory for the board specified).


### Flashing the Firmware with J-Link OB

The above boards have a builtin programmer called J-Link OB. With
these boards. Using the J-Link OB, you can flash the firmware on 
those boards.

Accessing the board
-------------------

Once built and deployed, access the MicroPython REPL (the Python prompt) via USB
serial or UART, depending on the board.  You can try:

    $ picocom /dev/ttyACM0

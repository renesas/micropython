Introduction to the RA port
===========================

The boards for RA MCU are called as "raboards" in the document.
The document for "raboards" partly comes from the document from "pyboard".

To get the most out of your RA MCU port, there are a few basic things to
understand about how it works.

How to program firmware on a target board
-----------------------------------------

The following steps show how to program firmware on a target board.

* Download J-Link Software and Documentation pack and install it.
* Execute J-Flash-Lite program
* Select a target device and program firmware hex file.

   * RA4M1 clicker: R7FA4M1AB
   * EK-RA6M2: R7FA6M2AF
   * EK-RA4M1: R7FA4M1AB
   * EK-RA6M1: R7FA6M1AD
   * EK-RA4W1: R7FA4W1AD

* Program Device

Connecting your raboards
------------------------

Two cables need to connect.
The power should be provided via USB cable. 
The communication between the board and PC is via USB-Serial converter cable.

Connect your raboards to your PC (Windows, Mac or Linux) via USB-Serial convertor
cable.

* EK-RA6M2 board

   .. image:: img/ek_ra6m2_how_to_connect.jpg

* RA4M1 Clicker board

   .. image:: img/ra4m1_clicker_how_to_connect.jpg

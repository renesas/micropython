.. _ra_general:

General information about RA port
=================================

.. contents::

Overview
--------

The flexible Renesas Advanced (RA) 32-bit microcontrollers (MCUs) are 
industry-leading 32-bit MCUs with the Arm® Cortex®-M33, -M23 and -M4 
processor cores and PSA certification. 

The ported functionality is part of the implementation (pyboard) for STM32. 

* "rab" module is defined as alias of "pyb" module.
* However, Hardware Timer, PWM (Servo), USB, CAN, WDT… are not implemented yet.
* The parameters of some modules of Pyboard may not be implemented.
* The specification of the modules is different from other MicroPython implementations for MCUs.

The following boards are officially supported.

* EK-RA4M1 Clicker board

   .. image:: img/ra4m1_clicker_board.jpg
      :alt: RA4M1 Clicker Board
      :width: 240px

   Please refer to the web page: `EK-RA4M1 Clicker <https://www.mikroe.com/ra4m1-clicker>`_

* EK-RA6M2 board

   .. image:: img/ek_ra6m2_board.jpg
      :alt: EK-RA6M2 Board
      :width: 360px

   Please refer to the web page: `EK-RA6M2 <https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra6m2-ra6m2-mcu-group-evaluation-board>`_ 

The following boards are unofficially supported.

* EK-RA4M1 board

   .. image:: img/ek_ra4m1_board.jpg
      :alt: EK-RA4M1 Board
      :width: 360px

   Please refer to the web page: `EK-RA4M1 <https://www.renesas.com/jp/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra4m1-ra4m1-mcu-group-evaluation-board>`_

* EK-RA4W1 board

   .. image:: img/ek_ra4w1_board.jpg
      :alt: EK-RA4W1 Board
      :width: 360px

   Please refer to the web page: `EK-RA4W1 <https://www.renesas.com/jp/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra4w1-ra4w1-mcu-group-evaluation-board>`_

* EK-RA6M1 board

   .. image:: img/ek_ra6m1_board.jpg
      :alt: EK-RA6M1 Board
      :width: 360px

   Please refer to the web page: `EK-RA6M1 <https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra6m1-ra6m1-mcu-group-evaluation-board>`_


EK-RA4M1 Clicker board
----------------------

* Please refer to the web page: `RA4M1 Clicker <https://www.mikroe.com/ra4m1-clicker>`_

   .. image:: img/ra4m1_clicker_board.jpg
      :alt: RA4M1 Clicker Board
      :width: 240px

   Pin Information

   .. image:: img/ra4m1_clicker_pins.jpg
      :alt: RA4M1 Clicker Board Pin information
      :width: 360px

   Peripheral Information

   .. image:: img/ra4m1_clicker_peripheral_assignment.jpg
      :alt: RA4M1 Clicker Board peripheral information
      :width: 540px

EK-RA6M2 board
--------------

* Please refer to the web page: `EK-RA6M2 <https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra6m2-ra6m2-mcu-group-evaluation-board>`_

   .. image:: img/ek_ra6m2_board.jpg
      :alt: EK-RA6M2 Board
      :width: 360px

   Pin Information - J1 header

   .. image:: img/ek_ra6m2_j1_pins.jpg
      :alt: EK-RA6M2 Board J1 header pin information
      :width: 360px

   Pin Information - J2 header

   .. image:: img/ek_ra6m2_j2_pins.jpg
      :alt: EK-RA6M2 Board J2 header pin information
      :width: 360px

   Pin Information - J3 header

   .. image:: img/ek_ra6m2_j3_pins.jpg
      :alt: EK-RA6M2 Board J3 header pin information
      :width: 360px

   Pin Information - J4 header

   .. image:: img/ek_ra6m2_j4_pins.jpg
      :alt: EK-RA6M2 Board J4 header pin information
      :width: 360px

   Peripheral Information

   .. image:: img/ek_ra6m2_peripheral_1.jpg
      :alt: RA4M1 Clicker Board Peripheral 1
      :width: 540px

   .. image:: img/ek_ra6m2_peripheral_2.jpg
      :alt: RA4M1 Clicker Board Peripheral 2
      :width: 540px

   .. image:: img/ek_ra6m2_peripheral_3.jpg
      :alt: RA4M1 Clicker Board Peripheral 3
      :width: 540px

   .. image:: img/ek_ra6m2_peripheral_4.jpg
      :alt: RA4M1 Clicker Board Peripheral 4
      :width: 540px

   .. image:: img/ek_ra6m2_peripheral_5.jpg
      :alt: RA4M1 Clicker Board Peripheral 5
      :width: 540px

Technical specifications and SoC datasheets
-------------------------------------------

The datasheets and other reference material for Reneasa RA MCU are available
from the vendor site: https://www.renesas.com/jp/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus
They are the primary reference for the chip technical specifications, 
capabilities, operating modes, internal functioning, etc.

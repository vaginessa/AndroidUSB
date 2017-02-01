/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: io-11-definitions.s
*
* Type: DEFINITIONS
*
* Title: Input/output related definitions
*
* Version: 1.1
*
* Purpose: The dsPIC33E being used to develop this project is
*          mounted on a starter kit board. This board has three
*          LEDs and three switches which are hardwired to port D of
*          the microprocessor. This file contains the line numbers
*          for reference in other source files.
*
* Date first created: 11th October 2015
* Date last modified: 25th January 2017
*
* Author: John Scott
*
* Used by: io-11.inc
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.include "p33EP512MU810.inc"    
    
; ========================== DEFINITIONS =============================


; Port D line map for input/output
.equiv  red,    0
.equiv  amber,  1
.equiv  green,  2

.equiv  SW1,    6
.equiv  SW2,    7
.equiv  SW3,    13


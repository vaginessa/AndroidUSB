/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-windows.inc
*
* Type: SOURCE
*
* Title: Windows Callable Functions
*
* Version: 2.1
*
* Purpose: These routines may be called by sending a control
*          windows_command request to the device.
*
*
* Date first created: 11th October 2015
* Date last modified: 25th January 2017
*
* Author: John Scott
*
* Used by: usb-21.inc
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.text
; ============================== CODE ================================


; --------------------------------------------------------------------
; Windows Function 1
; --------------------------------------------------------------------
USB.SUB.WIN.WF1:
; Function used to test the real time interrupt transfer processing
; for passing data from the device to the computer.
;
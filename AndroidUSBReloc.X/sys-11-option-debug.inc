/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: sys-11-option-debug.inc
*
* Type: OPTION
*
* Title: System debugging options
*
* Version: 1.1
*
* Purpose: Contains debugging options for the system routines.
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: sys-11.inc
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

; --------------------------------------------------------------------
; Call Counter
; --------------------------------------------------------------------
; The code can count the number of times the application changes the
; program execution. Uncomment the statement below to switch on the
; counter. The program will break when the routine reaches the counter
; limit (defined below).
; --------------------------- STATEMENT ------------------------------
.global SYS.OPTION.DEBUG.SwitchOnCounter
.equiv  SYS.OPTION.DEBUG.EventCounterLimit, 3
; --------------------------------------------------------------------




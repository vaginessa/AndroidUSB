/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: io-11-reg.s
*
* Type: DATA
*
* Title: IO Registers
*
* Version: 2.1
*
* Purpose: 
*
* Date first created: 26th January 2017
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: io-11
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.include "p33EP512MU810.inc"
;.include "extern-11.inc"
    
; ===================== REGISTER DECLARATIONS ========================
    
.global IO.REG.button_state
    
; --------------------------------------------------------------------
; Push button state
; --------------------------------------------------------------------
.section IO.REG.BUTTON_STATE, data, near
IO.REG.button_state:        .word 0x0000
; Stores the current push button state





/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: io-11-extern.inc
*
* Type: External Declartion
*
* Title: Subroutine and register declarations 
*
* Version: 1.1
*
* Purpose: To be included with all source files
*
* Date first created: 26th January 2017
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: io-11.s
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

; =================== SUBROUTINE DECLARATIONS ==========================

.extern IO.SUB.CONFIG
    
.extern IO.SUB.green_on
.extern IO.SUB.green_off
.extern IO.SUB.amber_on
.extern IO.SUB.amber_off
.extern IO.SUB.red_on
.extern IO.SUB.red_o    
    
.extern IO.SUB.green_flash
.extern IO.SUB.amber_flash
.extern IO.SUB.red_flash
.extern IO.SUB.amber_and_green_flash
    
.extern IO.SUB.UPDATE_BUTTON_STATE 
    
; ===================== REGISTER DECLARATIONS ========================
    
.extern IO.REG.button_state



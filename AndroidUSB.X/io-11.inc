/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: io-11.inc
*
* Type: SOURCE
*
* Title: Input/Output Configuration
*
* Version: 1.1
*
* Purpose:
*
*
* Date first created: 11th October 2015
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: <main application>.s
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

; =========================== INCLUDE FILES ==========================
.include    "io-11-definitions.inc"


.text
; =============================== CODE ===============================

; --------------------------------------------------------------------
; IO Configuration
; --------------------------------------------------------------------
; The following routine sets up the relevant lines on port D to
; accept input from the push buttons and control the LEDs on the
; USB starter kit.
; --------------------------------------------------------------------

IO.SUB.CONFIG:

    ; Choose Port D as a digital port
    CLR     ANSELD
    ; Choose LED lines as outputs
    BCLR    TRISD, #red
    BCLR    TRISD, #amber
    BCLR    TRISD, #green
    ; Choose push button lines are inputs
    BSET    TRISD, #SW1
    BSET    TRISD, #SW2
    BSET    TRISD, #SW3
    ; Return to caller
    RETURN

                                                      ; End of routine
; --------------------------------------------------------------------



; --------------------------------------------------------------------
; Windows Command Notification
; --------------------------------------------------------------------
; Each time Windows successfully executes a command the following
; signal can be given to indicate to the user that the operation
; was a success. Routine flashes the green LED three times
; --------------------------------------------------------------------

IO.SUB.green_flash:

    ; Routine to blink green LED three times
    DO      #2, 0f
    BSET    LATD, #green
    DO      #1000, 1f
    REPEAT  #3000
    NOP
1:  NOP
    BCLR    LATD, #green
    DO      #3000, 1f
    REPEAT  #3000
    NOP
1:  NOP
0:  NOP

    ; Return to caller
    RETURN

IO.SUB.amber_flash:

    ; Routine to blink green LED three times
    DO      #2, 0f
    BSET    LATD, #amber
    DO      #1000, 1f
    REPEAT  #3000
    NOP
1:  NOP
    BCLR    LATD, #amber
    DO      #3000, 1f
    REPEAT  #3000
    NOP
1:  NOP
0:  NOP

    ; Return to caller
    RETURN

IO.SUB.red_flash:

    ; Routine to blink green LED three times
    DO      #2, 0f
    BSET    LATD, #red
    DO      #1000, 1f
    REPEAT  #3000
    NOP
1:  NOP
    BCLR    LATD, #red
    DO      #3000, 1f
    REPEAT  #3000
    NOP
1:  NOP
0:  NOP

    ; Return to caller
    RETURN

IO.SUB.amber_and_green_flash:

    ; Routine to blink amber and green LEDs three times
    DO      #2, 0f
    BSET    LATD, #amber
    BSET    LATD, #green
    DO      #1000, 1f
    REPEAT  #3000
    NOP
1:  NOP
    BCLR    LATD, #amber
    BCLR    LATD, #green
    DO      #3000, 1f
    REPEAT  #3000
    NOP
1:  NOP
0:  NOP

    ; Return to caller
    RETURN


                                                      ; End of routine
; --------------------------------------------------------------------



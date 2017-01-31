/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-bdt.inc
*
* Type: DATA
*
* Title: USB Module Buffer Descriptor Table Initialisation
*
* Version: 2.1
*
* Purpose: This file contains the buffer descriptor table which is
*          used by the CPU to control the USB Module transaction
*          properties.
*
*          USB communication conceptually takes place through channels
*          called pipes. Each pipe has an IN and an  OUT channel and
*          terminates at the device side at an endpoint. USB devices
*          may use up to 16 endpoints.
*
*          In the implementation of the hardware protocol by
*          Microchip, each endpoint has a control register to enable
*          and configure it. Each also has four buffers in RAM to
*          store data that has been received from the host or data to
*          be sent to the host. Two of them are receive buffers (RX)
*          and the other two are transmit buffers (TX) - there are two
*          of each to support ping-pong buffering. To store the
*          address of these buffers and also to hold other properties
*          of the transactions taking place, each endpoint buffer has
*          a buffer descriptor in RAM which is four words long.
*
*          The buffer descriptors are stored together in a buffer
*          descriptor table (BDT), which is initialised in this file.
*          The total length of the BDT is 512 bytes.
*
* Date first created: 11th October 2015
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: usb-21.inc
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

; ========================= DECLARATIONS =============================

.global USB.BDT

; ====================== DATA INITIALISATION =========================

.ifdef BDTAddress
    .section USB.BDT, data, near, address(BDTAddress)
.else
    .section USB.BDT, data, near, align(512)
.endif

; ENDPOINT 0 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2000
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2040

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0 ; application must set
                    /* ADDRESS   */     .long 0 ; application must set
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0 ; application must set
                    /* ADDRESS   */     .long 0 ; application must set

USB.BDT.EP1:
; ENDPOINT 1 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 8
                    /* ADDRESS   */     .long .startof.(USB.REG.IT.RX.BUFFER)
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 8
                    /* ADDRESS   */     .long .startof.(USB.REG.IT.RX.BUFFER)

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 8
                    /* ADDRESS   */     .long .startof.(USB.REG.IT.TX.BUFFER)
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 8 
                    /* ADDRESS   */     .long .startof.(USB.REG.IT.TX.BUFFER)

USB.BDT.EP2:
; ENDPOINT 2 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
        EP2.WORD0:  /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long .startof.(USB.REG.BT.RX.BUFFER)
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long .startof.(USB.REG.BT.RX.BUFFER)

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long .startof.(USB.REG.BT.TX.BUFFER)
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long .startof.(USB.REG.BT.TX.BUFFER)

; ENDPOINT 3 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2300
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2340

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2380
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x23C0

; ENDPOINT 4 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2400
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2440

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2480
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x24C0

; ENDPOINT 5 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2500
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2540

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2580
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x25C0

; ENDPOINT 6 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2600
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2640

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2680
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x26C0

; ENDPOINT 7 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2700
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2740

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2780
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x27C0

; ENDPOINT 8 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2800
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2840

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2880
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x28C0

; ENDPOINT 9 ---------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2900
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2940

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2980
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x29C0

; ENDPOINT 10 --------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2A00
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2A40

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2A80
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2AC0

; ENDPOINT 11 --------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2B00
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2B40

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2B80
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2BC0

; ENDPOINT 12 --------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2C00
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2C40

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2C80
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2CC0

; ENDPOINT 13 --------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2D00
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2D40

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2D80
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2DC0

; ENDPOINT 14 --------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2E00
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2E40

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2E80
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2EC0

; ENDPOINT 15 --------------------------------------------------------

        ; Receive Buffer Descriptors (RX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2F00
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0080
                    /* BYTECOUNT */     .word 64
                    /* ADDRESS   */     .long 0x2F40

         ; Transmit Buffer Descriptors (TX)

                ; EVEN -----------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2F80
                ; ODD -------------------------------
                    /* WORD0     */     .word 0x0000
                    /* BYTECOUNT */     .word 0
                    /* ADDRESS   */     .long 0x2FC0

; --------------------------------------------------------- End of BDT


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-option-config.inc
*
* Type: OPTION
*
* Title: USB Firmware Configuration Options
*
* Version: 2.1
*
* Purpose: Allows the user to set the configuration of the USB Module
*          and other USB behavior. Configuration options are set by
*          declaring symbols in this file. These symbols then control
*          conditional compilation of some blocks of assembly code in
*          other source files. Further details on each option are
*          described below.
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: usb-21.s
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    
; --------------------------------------------------------------------
; Allow USB Transfer Handling Framework to configure clocks
; --------------------------------------------------------------------
; This option is used to decide whether or not the USB Transfer
; Handling Framework should configure the dsPIC33E instruction rate.
; If the decalration is commented out then the user application must
; configure the instruction rate. If the declaration is present then
; the USB Transfer Handling Framework will perform a clock switch to
; the Primary Oscillator with PLL to give an instruction rate of
; 60 MHz. Note that for this to succeed, the configuration bits of
; microcontroller must be set up correctly, and an external primary
; oscillator must be present.
; --------------------------- STATEMENT ------------------------------
.global USB.OPTION.CONFIG.PerformClockSetup
; --------------------------------------------------------------------

; --------------------------------------------------------------------
; Fix the address of the buffer descriptor table (BDT)
; --------------------------------------------------------------------
; The BDT is used by the CPU to control the USB transactions that
; take place after the USB Module has been enabled. The BDT must be
; aligned to a 512 byte boundary. It is useful for debugging
; purposes to know for sure where the BDT is stored. On the other
; hand it is better for efficient use of memory to allow the linker
; to allocate memory for the BDT. The definition below can be used to
; decide which approach is adopted. If the statement is commented out
; then the linker will allocate memory. Alternatively, specify the
; desired BDT start address. The address should be a multiple of
; 512. Make sure the address is in a legitimate location for the
; type of chip. 
; Note: Do not choose an address greater than 0xFE00.
; --------------------------- STATEMENT ------------------------------
;.equiv  BDTAddress, /* Put address here ---> */ 0x8000 /* <--- */
; --------------------------------------------------------------------

; --------------------------------------------------------------------
; Perform Data Toggle Synchronisation Checks
; --------------------------------------------------------------------
; The USB Module has a feature that allows the CPU to check that the
; USB protocol is being implemented correctly. When multiple data
; packets are sent between the host and device, they alternate
; between DATA0 and DATA1 versions so a lost packet can be detected.
; Uncomment the option below in order to implement the data toggle
; checks for incoming data packets
; --------------------------- STATEMENT ------------------------------
;.global USB.OPTION.CONFIG.UseDataToggleSynchronisation
; --------------------------------------------------------------------

; --------------------------------------------------------------------
; Select USB Endpoint Buffer Size
; --------------------------------------------------------------------
; Full speed USB devices must use a packet size of 64 bytes.
; --------------------------- STATEMENT ------------------------------
.equiv  USB.OPTION.CONFIG.EPBufferSize, 64      ; Size = 64 bytes
; --------------------------------------------------------------------

; --------------------------------------------------------------------
; Select Endpoint Usage
; --------------------------------------------------------------------
; The following is used to define the endpoint characteristics of the
; device. A USB device has at most 16 endpoints, each with an OUT
; and an IN channel. Endpoints can be configured for control,
; interrupt, bulk or isochronous transfers. Endpoint 0 is called the
; default endpoint and must be configured as a control endpoint.
; Use the statements below to set the properties of the endpoints
; used be the device. Comment out all but the relavent endpoint type
; If the endpoint is not used, comment out all the options.
; --------------------------- STATEMENT ------------------------------

; Endpoint 0 -------------------------------
.global  USB.OPTION.CONFIG.EP0.control
;.global  USB.OPTION.CONFIG.EP0.interrupt
;.global  USB.OPTION.CONFIG.EP0.bulk
;.global  USB.OPTION.CONFIG.EP0.isochronous

; Endpoint 1 -------------------------------
;.global  USB.OPTION.CONFIG.EP1.control
.global  USB.OPTION.CONFIG.EP1.interrupt
;.global  USB.OPTION.CONFIG.EP1.bulk
;.global  USB.OPTION.CONFIG.EP1.isochronous

; --------------------------------------------------------------------




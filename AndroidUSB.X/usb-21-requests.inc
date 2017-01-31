/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-requests.inc
*
* Type: SOURCE
*
* Title: USB Request Routines
*
* Version: 2.1
*
* Purpose: A control transfer can carry a command called a request.
*          Some of the requests are USB 2.0 defined and others are
*          defined by the operating system that is running on the
*          host computer. A USB device must be able to respond
*          correctly to certain requests in order for it to
*          successfully enumerate. This file contains the routines
*          to correctly process all expected requests.
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

.text
; ============================= CODE =================================

; --------------------------------------------------------------------
; USB Request Routines
; --------------------------------------------------------------------
; The following section contains code that processes each individual
; request type. The control transfer routine directs exectution to the
; relevant point (setup, data or status). The routines set up the
; next required USB transaction and monitor the progress of each
; request.

; --------------------------------------------------------- GET_STATUS
USB.SUB.REQ.GET_STATUS.setup:
    ; Log Get Status event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.GetStatusSetup, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties
    ;   - There is a data stage
    ;   - Next packet is DATA1
    MOV     [w5+CTword], w0
    BSET    w0, #NDT
    BSET    w0, #CTDAT
    MOV     w0, [w5+CTword]
    ; Load the address of the general status word into the BD
    MOV     #USB.REG.STAT.General, w1
    ; Store the start address of the data to send
    MOV     w1, USB.REG.CT.NextBufferAddress
    MOV     #2, w4
    ; Store the length of the data to send
    MOV     w4, USB.REG.CT.NextTransferLength
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.setup

USB.SUB.REQ.GET_STATUS.data:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetStatusData, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.data

USB.SUB.REQ.GET_STATUS.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetStatusStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.status

; ------------------------------------------------------ CLEAR_FEATURE
USB.SUB.REQ.CLEAR_FEATURE.setup: BRA AppError15
USB.SUB.REQ.CLEAR_FEATURE.data: BRA AppError15
USB.SUB.REQ.CLEAR_FEATURE.status: BRA AppError15


; -------------------------------------------------------- SET_FEATURE
USB.SUB.REQ.SET_FEATURE.setup: BRA AppError15
USB.SUB.REQ.SET_FEATURE.data: BRA AppError15
USB.SUB.REQ.SET_FEATURE.status: BRA AppError15

; -------------------------------------------------------- SET_ADDRESS
USB.SUB.REQ.SET_ADDRESS.setup:
    ; Log Set Address event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.SetAddressSetup, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties - there is no data stage
    MOV     [w5+CTword], w0
    BSET    w0, #CTST
    MOV     w0, [w5+CTword]
    ; ---------------------------------------------------------------
    ; NOTE:
    ; The Set Address request contains the device assigned address
    ; in the wValue field. The address should be set in the status
    ; stage of the request because the host will continue to use the
    ; old address until the control transfer has successfully
    ; completed.
    ; ---------------------------------------------------------------
    ADD     w5, #8, w7
    MOV     [w7+CT.SETUP.wValue], w0        ; Store wValue in w0
    MOV     w0, USB.REG.CT.PendingAddress   ; Store address
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.setup

USB.SUB.REQ.SET_ADDRESS.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.SetAddressStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Write the pending address ready for the next communication
    MOV     USB.REG.CT.PendingAddress, w0
    MOV     w0, U1ADDR
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.status


; ----------------------------------------------------- GET_DESCRIPTOR
USB.SUB.REQ.GET_DESCRIPTOR.setup:
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties
    ;   - There is a data stage
    ;   - Next packet is DATA1
    MOV     [w5+CTword], w0
    BSET    w0, #NDT
    BSET    w0, #CTDAT
    MOV     w0, [w5+CTword]
    ; ---------------------------------------------------------------
    ; NOTE:
    ; wValue contains the descriptor type in the high byte and the
    ; descriptor index (if there is one) in the low byte. The
    ; descriptors are accessed by using a lookup table which contains
    ; the starting addresses of the descriptors.
    ; ---------------------------------------------------------------
    ADD     w5, #8, w7
    MOV     [w7+CT.SETUP.wValue], w0    ; Store wValue in w0
    MOV     #.startof.(USB.SUB.REQ.DescriptorAddressTable), w1
    ; Log Get Descriptor event and descriptor type.
    ; The descriptor type is the value assigned in the USB 2.0
    ; specification for each descriptor
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.GetDescriptorSetup, w3
    CLR     w4
    MOV.B   [w3], w4
    SL      w4, #8, w4
    MOV     #0x30, w3
    LSR     w0, #8, w8
    ADD     w8, w3, w2
    ADD     w4, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Construct address
    ADD     w0, w1, w0
    ; w0 now points to the required descriptor address
    ; Load the address into the BD
    MOV     [w0], w1
    MOV     #0x0002, w2
    CPSNE   w1, w2          ; Test for request error
    BRA     USB.SUB.REQ.REQUEST_ERROR
    INC     w1, w1          ; Add 1 to address
    ; Store the start address of the data to send
    MOV     w1, USB.REG.CT.NextBufferAddress
    ; Read the amount of data to be returned from the LENGTH_FIELD
    DEC     w1, w1              ; Subtract 1 from w1
    CLR     w4
    MOV.B   [w1], w4            ; w4 contains the descriptor length
    ; Store the length of the data to send
    MOV     w4, USB.REG.CT.NextTransferLength
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.setup

USB.SUB.REQ.GET_DESCRIPTOR.data:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetDescriptorData, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.data

USB.SUB.REQ.GET_DESCRIPTOR.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetDescriptorStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.status

; ----------------------------------------------------- SET_DESCRIPTOR
USB.SUB.REQ.SET_DESCRIPTOR.setup: BRA AppError15
USB.SUB.REQ.SET_DESCRIPTOR.data: BRA AppError15
USB.SUB.REQ.SET_DESCRIPTOR.status: BRA AppError15

; -------------------------------------------------- GET_CONFIGURATION
USB.SUB.REQ.GET_CONFIGURATION.setup: BRA AppError15
USB.SUB.REQ.GET_CONFIGURATION.data: BRA AppError15
USB.SUB.REQ.GET_CONFIGURATION.status: BRA AppError15

; -------------------------------------------------- SET_CONFIGURATION
USB.SUB.REQ.SET_CONFIGURATION.setup:
    ; Log Set Configuration event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.SetConfigurationSetup, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties - there is no data stage
    MOV     [w5+CTword], w0
    BSET    w0, #CTST
    MOV     w0, [w5+CTword]
    ; Enable endpoint 1 for interrupt transfers
    MOV     #0x001D, w0
    MOV     w0, U1EP1       ; Enable EP1 for RX/TX transfers
    MOV     w0, U1EP2       ; Enable EP2 for RX/TX transfers
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.setup

USB.SUB.REQ.SET_CONFIGURATION.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.SetConfigurationStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.status

; ------------------------------------------------------ GET_INTERFACE
USB.SUB.REQ.GET_INTERFACE.setup: BRA AppError15
USB.SUB.REQ.GET_INTERFACE.data: BRA AppError15
USB.SUB.REQ.GET_INTERFACE.status: BRA AppError15

; ------------------------------------------------------ SET_INTERFACE
USB.SUB.REQ.SET_INTERFACE.setup: BRA AppError15
USB.SUB.REQ.SET_INTERFACE.data: BRA AppError15
USB.SUB.REQ.SET_INTERFACE.status: BRA AppError15

; -------------------------------------------------------- SYNCH_FRAME
USB.SUB.REQ.SYNCH_FRAME.setup: BRA AppError15
USB.SUB.REQ.SYNCH_FRAME.data: BRA AppError15
USB.SUB.REQ.SYNCH_FRAME.status: BRA AppError15
; -------------------------------------------------- GET_MS_DESCRIPTOR
USB.SUB.REQ.GET_MS_DESCRIPTOR.setup:
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties
    ;   - There is a data stage
    ;   - Next packet is DATA1
    MOV     [w5+CTword], w0
    BSET    w0, #NDT
    BSET    w0, #CTDAT
    MOV     w0, [w5+CTword]
    ; wIndex contains the descriptor type that is being requested
    ADD     w5, #8, w7
    MOV     [w7+CT.SETUP.wIndex], w0    ; Store wIndex in w0
    ; Log Get Descriptor event and descriptor type.
    ; The descriptor type is the value assigned in the USB 2.0
    ; specification for each descriptor
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.GetMSDescriptorSetup, w3
    CLR     w4
    MOV.B   [w3], w4
    SL      w4, #8, w4
    MOV     #0x30, w3
    ADD     w0, w3, w2
    ADD     w4, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Align address so that it points to even bytes only
    SL      w0, #1, w0
    MOV     #.startof.(USB.SUB.REQ.MSDescriptorAddressTable), w1
    ; Construct address
    ADD     w0, w1, w0
    ; w0 now points to the required descriptor address
    ; Load the address into the BD
    MOV     [w0], w1
    MOV     #0x0002, w2
    CPSNE   w1, w2          ; Test for request error
    BRA     USB.SUB.REQ.REQUEST_ERROR
    INC     w1, w1          ; Add 1 to address
    ; Store the start address of the data to send
    MOV     w1, USB.REG.CT.NextBufferAddress
    ; Read the amount of data to be returned from the LENGTH_FIELD
    DEC     w1, w1              ; Subtract 1 from w1
    CLR     w4
    MOV.B   [w1], w4            ; w4 contains the descriptor length
    ; Store the length of the data to send
    MOV     w4, USB.REG.CT.NextTransferLength
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.setup

USB.SUB.REQ.GET_MS_DESCRIPTOR.data:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetMSDescriptorData, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.data

USB.SUB.REQ.GET_MS_DESCRIPTOR.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetMSDescriptorStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.status


; ----------------------------------------------- GET_MS_20_DESCRIPTOR
USB.SUB.REQ.GET_MS_20_DESCRIPTOR.setup: BRA AppError15
USB.SUB.REQ.GET_MS_20_DESCRIPTOR.data: BRA AppError15
USB.SUB.REQ.GET_MS_20_DESCRIPTOR.status: BRA AppError15

; ------------------------------------------------------ REQUEST_ERROR
USB.SUB.REQ.REQUEST_ERROR:
    ; Log Request Error event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.RequestError, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Process the request error
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    MOV     USB.REG.CurrentBD, w2
    MOV     #0x00C4, w0                 ; Set UOWN, use DATA1
    MOV     w0, [w2+TX.EVEN.WORD0]      ; Next trans. TX EVEN
    MOV     #0x0001, w0
    MOV     w0, [w2+TX.EVEN.BYTECOUNT]  ; Choose non-zero length
    ; Clear up registers for end of CT
    MOV     [w5+CTword], w0
    BCLR    w0, #CTEN
    BCLR    w0, #CTDAT
    BCLR    w0, #CTST
    BCLR    w0, #NDT
    BCLR    w0, #READ
    MOV     w0, [w5+CTword]
    MOV     [w5+DLword], w0
    CLR     w0
    MOV     w0, [w5+DLword]
    ; Reset RX buffer descriptors
    MOV     #0x0080, w0
    MOV     #64, w1
    MOV     w0, [w2+RX.EVEN.WORD0]
    MOV     w1, [w2+RX.EVEN.BYTECOUNT]
    ; Return to Transaction Processing Routine
    RETURN
    BRA AppError15

; --------------------------------------------------------- TOGGLE_LED
USB.SUB.REQ.TOGGLE_LED.setup:
    ; Log Toggle LED event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.ToggleLEDSetup, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties - there is no data stage
    MOV     [w5+CTword], w0
    BSET    w0, #CTST
    MOV     w0, [w5+CTword]
    ; The wValue contains the instruction details: which LED to
    ; modify and whether to switch it on or off
    ADD     w5, #8, w7
    MOV     [w7+CT.SETUP.wValue], w0    ; Store wValue in w0
    ; Test each case, modify the port latch accordingly
    MOV     #red_on, w1
    CPBNE   w0, w1, 0f
    BSET    LATD, #red
    BRA     1f
0:  MOV     #amber_on, w1
    CPBNE   w0, w1, 0f
    BSET    LATD, #amber
    BRA     1f
0:  MOV     #green_on, w1
    CPBNE   w0, w1, 0f
    BSET    LATD, #green
    BRA     1f
0:  MOV     #red_off, w1
    CPBNE   w0, w1, 0f
    BCLR    LATD, #red
    BRA     1f
0:  MOV     #amber_off, w1
    CPBNE   w0, w1, 0f
    BCLR    LATD, #amber
    BRA     1f
0:  MOV     #green_off, w1
    CPBNE   w0, w1, 0f
    BCLR    LATD, #green
    ; Call generic protocol routine
1:  BRA     USB.SUB.CT.control_write.setup

USB.SUB.REQ.TOGGLE_LED.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.ToggleLEDStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.status

; ---------------------------------------------------- WINDOWS_COMMAND
USB.SUB.REQ.WINDOWS_COMMAND.setup:
    ; Log Windows Command event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.WindowsCommandSetup, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties - there is no data stage
    MOV     [w5+CTword], w0
    BSET    w0, #CTST
    MOV     w0, [w5+CTword]
    ; ---------------------------------------------------------------
    ; NOTE:
    ; All USB based control of the device by a Windows application
    ; takes place through this command. The command does not have a
    ; data stage. Command information is contained in the wValue
    ; ----------------------------------------------------------------

    ; The wValue and wIndex contain the instruction
    ADD     w5, #8, w7
    MOV     [w7+CT.SETUP.wValue], w0    ; Store wValue in w0

    ; Make a request to the system for new function execution
    MOV     SYS.REG.REQUEST_BUFFER.pointer, w3
    MOV     w0, [w3]                    ; load request
    RCALL   SYS.SUB.pointer_increment   ; Increment request pointer

    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.setup

USB.SUB.REQ.WINDOWS_COMMAND.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.WindowsCommandStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_write.status

; ------------------------------------------------------ READ_BUTTONS
USB.SUB.REQ.READ_BUTTONS.setup:
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    ; Update control transfer properties
    ;   - There is a data stage
    ;   - Next packet is DATA1
    MOV     [w5+CTword], w0
    BSET    w0, #NDT
    BSET    w0, #CTDAT
    MOV     w0, [w5+CTword]
    ; ---------------------------------------------------------------
    ; NOTE:
    ; wValue contains the descriptor type in the high byte and the
    ; descriptor index (if there is one) in the low byte. The
    ; descriptors are accessed by using a lookup table which contains
    ; the starting addresses of the descriptors.
    ; ---------------------------------------------------------------
    ADD     w5, #8, w7
    MOV     [w7+CT.SETUP.wValue], w0    ; Store wValue in w0
    MOV     #.startof.(USB.SUB.REQ.DescriptorAddressTable), w1
    ; Log Get Descriptor event and descriptor type.
    ; The descriptor type is the value assigned in the USB 2.0
    ; specification for each descriptor
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.GetDescriptorSetup, w3
    CLR     w4
    MOV.B   [w3], w4
    SL      w4, #8, w4
    MOV     #0x30, w3
    LSR     w0, #8, w8
    ADD     w8, w3, w2
    ADD     w4, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Construct address
    ADD     w0, w1, w0
    ; w0 now points to the required descriptor address
    ; Load the address into the BD
    MOV     [w0], w1
    MOV     #0x0002, w2
    CPSNE   w1, w2          ; Test for request error
    BRA     USB.SUB.REQ.REQUEST_ERROR
    INC     w1, w1          ; Add 1 to address
    ; Store the start address of the data to send
    MOV     w1, USB.REG.CT.NextBufferAddress
    ; Read the amount of data to be returned from the LENGTH_FIELD
    DEC     w1, w1              ; Subtract 1 from w1
    CLR     w4
    MOV.B   [w1], w4            ; w4 contains the descriptor length
    ; Store the length of the data to send
    MOV     w4, USB.REG.CT.NextTransferLength
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.setup

USB.SUB.REQ.READ_BUTTONS.data:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetDescriptorData, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.data

USB.SUB.REQ.READ_BUTTONS.status:
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel2
    MOV     #USB.DEBUG.GetDescriptorStatus, w6
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif
    ; Call generic protocol routine
    BRA     USB.SUB.CT.control_read.status
    
    
                                                      ; End of routine
; --------------------------------------------------------------------



; =============================== DATA ===============================


; --------------------------------------------------------------------
; USB Descriptor Address Table
; --------------------------------------------------------------------
; The following table holds the addresses of all the descriptors
; that might be requested by the host. The address offset is the
; unconditioned wValue which means that each address occupies a 16
; byte block. Descriptors of the same type with different indices
; can be placed inside this block.

.section USB.SUB.REQ.DescriptorAddressTable, data

; Alignment gap
.space  256

; Device descriptor block
.word   .startof.(USB.DESC.ST.DEVICE)
.space  254

; Configuration descriptor block
.word   .startof.(USB.DESC.ST.CONFIG.1)
.space  254

; String descriptor block
.word   .startof.(USB.DESC.ST.STRING.LANGID)
.word   .startof.(USB.DESC.ST.STRING.MANUFACTURER)
.word   .startof.(USB.DESC.ST.STRING.PRODUCT)
.word   .startof.(USB.DESC.ST.STRING.SERIAL)
.space  230
.word   .startof.(USB.DESC.MS.OSSTRING)
.space  16

; Interface/endpoint descriptors are not accessed individually
.space  512

; Device_qualifier descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254

; Other_spped_configuration descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254

; Interface_power descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254

; Alignment gap
.space  768

; Security descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254

; Key descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254

; Encryption_type descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254

; BOS descriptor block
.word   .startof.(USB.DESC.MS.BOS)
.space  254

; Device Capability descriptors are not accessed individually
.word   0x0002          ; To indicate a request error
.space  254

; Wireless_endpoint_companion descriptor does not exist
.word   0x0002          ; To indicate a request error
.space  254


; --------------------------------------------------------------------
; MS Descriptor Address Table
; --------------------------------------------------------------------
; Microsoft defines specific descriptors for use with Windows. The
; MS descriptor is requested using GET_MS_DESCRIPTOR and the
; descriptor type is contained in the wIndex value.

.section USB.SUB.REQ.MSDescriptorAddressTable, data

; Alignment gap
.space  2

; Genre descriptor does not exist
.word   0x0002          ; To indicate a request error

; Alignment gap
.space  4

; Extended_compat_id descriptor block
.word   .startof.(USB.DESC.MS.ECID)

; Extended_properties descriptor block
.word   .startof.(USB.DESC.MS.EP)














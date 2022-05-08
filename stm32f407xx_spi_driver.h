
/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: May 6, 2022
 *      Author: PLC
 */




/************************************************
 * MEMS ACCE. PIN OUT
 * LIS302DL
 * **********************************************
 * SPI1_MISO - SDO   			PA6 - 12
 * SPI1 - SDA/SDI/SDO      		PA7 - 13
 * SPI1 - SCL/SPC   			PA5 - 14
 *
 * CS_I2C/SPI    				PE3 - 7
 * MEMS_INT1 - INT 1  			PE0 - 8
 * MEMS_INT2 - INT 2  			PE1 - 9
 *
 */

#ifndef STM32F407XX_SPI_DRIVER_H_
#define STM32F407XX_SPI_DRIVER_H_




/*
 * INIT
 * STATE
 * HANDLE
 *
 */

/*
Peripheral:		SPI1
Base address:	0x40013000
Register:			CR1
Address:			0x40013000
Value:				null
Size:				32
Reset value:			0x0
Reset mask:			0xFFFFFFFF
Access permission:	RW
Read action:
typedef struct
*/

typedef struct
{
	uint8_t Bidirectional_data_mode_enable;//

	uint8_t Output_enable_in_bidirectional_mode;//

	uint8_t Hardware_CRC_calculation_enable;//

	uint8_t CRC_transfer_next;//

	uint8_t Data_frame_format;//

	uint8_t Receive_only;//

	uint8_t Software_slave_management;//

	uint8_t Internal_slave_select;//

	uint8_t Frame_format;//

	uint8_t SPI_enable;//

	uint8_t Baud_rate_control;//

	uint8_t Master_selection;//

	uint8_t Clock_polarity;//

	uint8_t Clock_phase;//

	uint32_t Data_register;//

	/*
		Register:			DR
		Address:			0x4001300c
		Value:				null
		Size:				32
		Reset value:			0x0
		Reset mask:			0xFFFFFFFF
		Access permission:	RW
		Read action:
		Bit field:			DR
		LSB:				0
		MSB:				16
		Size:				16
		Reset value:			0x0
		Access permission:	RW
		Read action:
		Description:		Data register
		*/

}SPI_INIT;





/*
Register:			SR
Address:			0x40013008
Value:				null
Size:				32
Reset value:			0x2
Reset mask:			0xFFFFFFFF
Access permission:	RW
Read action:
*/
typedef struct
{
	uint8_t TI_frame_format_error;//

	uint8_t Busy_flag;//

	uint8_t Overrun_flag;//

	uint8_t Mode_fault;//

	uint8_t CRC_error_flag;//

	uint8_t Underrun_flag;//

	uint8_t Channel_side;//

	uint8_t Transmit_buffer_empty;//

	uint8_t Receive_buffer_not_empty;//




}SPI_STATUS;

typedef struct
{
	SPI_TypeDef                *Instance;      /*!< SPI registers base address               */

	SPI_InitTypeDef            Init;           /*!< SPI communication parameters             */

	uint8_t                    *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer        */

	uint16_t                   TxXferSize;     /*!< SPI Tx Transfer size                     */

	//__IO uint16_t              TxXferCount;    /*!< SPI Tx Transfer Counter                  */

	uint8_t                    *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer        */

	uint16_t                   RxXferSize;     /*!< SPI Rx Transfer size                     */

	//__IO uint16_t              RxXferCount;    /*!< SPI Rx Transfer Counter                  */

	//void (*RxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Rx ISR       */

	//void (*TxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Tx ISR       */

	//DMA_HandleTypeDef          *hdmatx;        /*!< SPI Tx DMA Handle parameters             */

	//DMA_HandleTypeDef          *hdmarx;        /*!< SPI Rx DMA Handle parameters             */

	//HAL_LockTypeDef            Lock;           /*!< Locking object                           */

	//__IO HAL_SPI_StateTypeDef  State;          /*!< SPI communication state                  */

	//__IO uint32_t              ErrorCode;      /*!< SPI Error code                           */

}SPI_HANDLE;
//******************************************

//               SPI_INIT

//*****************************************************************

/*
Bit 15 BIDIMODE: Bidirectional data mode enable
0: 2-line unidirectional data mode selected
1: 1-line bidirectional data mode selected
Note: This bit is not used in I2S mode
*/
#define Bidirectional_data_mode_enable;//
#define MODE_2LINE;
#define MODE_1LIDE;



/*
Bit 14 BIDIOE: Output enable in bidirectional mode
This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
0: Output disabled (receive-only mode)
1: Output enabled (transmit-only mode)
Note: This bit is not used in I2S mode.
In master mode, the MOSI pin is used while the MISO pin is used in slave mode.
*/
#define Output_enable_in_bidirectional_mode;//
#define Rx_ONLY;
#define Tx_ONLY;



/*
Bit 13 CRCEN: Hardware CRC calculation enable
0: CRC calculation disabled
1: CRC calculation enabled
Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
It is not used in I2S mode.
*/
#define Hardware_CRC_calculation_enable;//



/*
Bit 12 CRCNEXT: CRC transfer next
0: Data phase (no CRC phase)
1: Next transfer is CRC (CRC phase)
Note: When the SPI is configured in full duplex or transmitter only modes, CRCNEXT must be
written as soon as the last data is written to the SPI_DR register.
When the SPI is configured in receiver only mode, CRCNEXT must be set after the
second last data reception.
This bit should be kept cleared when the transfers are managed by DMA.
It is not used in I2S mode.
*/
#define CRC_transfer_next;//
#define CRCNEXT_CHECK_I2S;
#define CRCNEXT_CHECK_DMA;
#define IS_SPI_Rx_ONLY;
#define IS_SPI_FD_Tx_ONLY;
#define CHECK_DATA_IN_DATA_REG;
/*
Bit 11 DFF: Data frame format
0: 8-bit data frame format is selected for transmission/reception
1: 16-bit data frame format is selected for transmission/reception
Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
It is not used in I2S mode
*/
#define Data_frame_format;//
#define DDF_8BIT;
#define DDF_16BIT:


/*
Bit 10 RXONLY: Receive only
This bit combined with the BIDImode bit selects the direction of transfer in 2-line
unidirectional mode. This bit is also useful in a multislave system in which this particular
slave is not accessed, the output from the accessed slave is not corrupted.
0: Full duplex (Transmit and receive)
1: Output disabled (Receive-only mode)
Note: This bit is not used in I2S mode
*/
#define Receive_only;//
#define FULL_DUPLEX_ENBALE;
#define HALF_DUPLEDX_ENABLE;


/*
Bit 9 SSM: Software slave management
When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
0: Software slave management disabled
1: Software slave management enabled
Note: This bit is not used in I2S mode and SPI TI mode
*/
#define Software_slave_management;//
#define SSM_ENABLE;
#define SSM_DISABLE;



/*
Bit 8 SSI: Internal slave select
This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
NSS pin and the IO value of the NSS pin is ignored.
Note: This bit is not used in I2S mode and SPI TI mode
*/
#define Internal_slave_select;//
#define CHECK_IF_SSM_ENABLED;
#define INTERNAL_SLAVE_SELECT_ENABLE;


/*
Bit 7 LSBFIRST: Frame format
0: MSB transmitted first
1: LSB transmitted first
Note: This bit should not be changed when communication is ongoing.
It is not used in I2S mode and SPI TI mode
*/
#define Frame_format;//
#define BIG_ENDIAN_ENABLE;
#define LITTLE_ENDIAN_ENABLE;



/*
Bit 6 SPE: SPI enable
0: Peripheral disabled
1: Peripheral enabled
Note: This bit is not used in I2S mode.
When disabling the SPI, follow the procedure described in Section 28.3.8.
*/
#define SPI_enable;//
#define SPI_PERIPHERAL_ENABLE;
#define SPI_PERIPHERAL_DISABLE;



/*
Bits 5:3 BR[2:0]: Baud rate control
000: fPCLK/2
001: fPCLK/4
010: fPCLK/8
011: fPCLK/16
100: fPCLK/32
101: fPCLK/64
110: fPCLK/128
111: fPCLK/256
Note: These bits should not be changed when communication is ongoing.
They are not used in I2S mode.
*/
#define Baud_rate_control;//
#define BAUD_DEVIDE_BY_2;
#define BAUD_DEVIDE_BY_4;
#define BAUD_DEVIDE_BY_8;
#define BAUD_DEVIDE_BY_16;
#define BAUD_DEVIDE_BY_32;
#define BAUD_DEVIDE_BY_64;
#define BAUD_DEVIDE_BY_128;
#define BAUD_DEVIDE_BY_256;


/*
Bit 2 MSTR: Master selection
0: Slave configuration
1: Master configuration
Note: This bit should not be changed when communication is ongoing.
It is not used in I2S mode
*/
#define Master_selection;//
#define MASTER_AS_MASTER_ENABLE;
#define SLAVE_AS_MASTER_ENABLE;

/*
Bit1 CPOL: Clock polarity
0: CK to 0 when idle
1: CK to 1 when idle
Note: This bit should not be changed when communication is ongoing.
It is not used in I2S mode and SPI TI mode.
*/
#define Clock_polarity;//
#define CLOCK_HIGH_WHEN_IDLE_ENABLE;
#define CLOCK_LOW_WHEN_IDLE_ENABLE;



/*
Bit 0 CPHA: Clock phase
0: The first clock transition is the first data capture edge
1: The second clock transition is the first data capture edge
Note: This bit should not be changed when communication is ongoing.
It is not used in I2S mode and SPI TI mode.
*/
#define Clock_phase;//
#define FIRST_EDGE_DATA_CAPTURE_ENABLE;
#define SECOND_EDGE_DATA_CAPTURE_ENABLE;


/*
Bits 15:0 DR[15:0]: Data register
Data received or to be transmitted.
The data register is split into 2 buffers - one for writing (Transmit Buffer) and another one for
reading (Receive buffer). A write to the data register will write into the Tx buffer and a read
from the data register will return the value held in the Rx buffer.

Note: These notes apply to SPI mode:
Depending on the data frame format selection bit (DFF in SPI_CR1 register), the data
sent or received is either 8-bit or 16-bit. This selection has to be made before enabling
the SPI to ensure correct operation.

For an 8-bit data frame, the buffers are 8-bit and only the LSB of the register
(SPI_DR[7:0]) is used for transmission/reception. When in reception mode, the MSB of
the register (SPI_DR[15:8]) is forced to 0.
For a 16-bit data frame, the buffers are 16-bit and the entire register, SPI_DR[15:0] is
used for transmission/reception.
*/
#define Data_register;//






//******************************************

//               SPI_STATUS

//*****************************************************************

/*
Bits 15:9 Reserved. Forced to 0 by hardware.
*/


/*
Bit 8 FRE: Frame format error
0: No frame format error
1: A frame format error occurred
This flag is set by hardware and cleared by software when the SPIx_SR register is read.
Note: This flag is used when the SPI operates in TI slave mode or I2S slave mode (refer to
Section 28.3.10).
*/


/*
Bit 7 BSY: Busy flag
0: SPI (or I2S) not busy
1: SPI (or I2S) is busy in communication or Tx buffer is not empty
This flag is set and cleared by hardware.
Note: BSY flag must be used with caution: refer to Section 28.3.7 and Section 28.3.8.
*/


/*
Bit 6 OVR: Overrun flag
0: No overrun occurred
1: Overrun occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 28.4.8:
Error flags for the software sequence.
*/


/*
Bit 5 MODF: Mode fault
0: No mode fault occurred
1: Mode fault occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 28.4.8:
Error flags for the software sequence.
Note: This bit is not used in I2S mode
*/


/*
Bit 4 CRCERR: CRC error flag
0: CRC value received matches the SPI_RXCRCR value
1: CRC value received does not match the SPI_RXCRCR value
This flag is set by hardware and cleared by software writing 0.
Note: This bit is not used in I2S mode.
*/


/*
Bit 3 UDR: Underrun flag
0: No underrun occurred
1: Underrun occurred
This flag is set by hardware and reset by a software sequence. Refer to Section 28.4.8:
Error flags for the software sequence.
Note: This bit is not used in SPI mode.
*/


/*
Bit 2 CHSIDE: Channel side
0: Channel Left has to be transmitted or has been received
1: Channel Right has to be transmitted or has been received
Note: This bit is not used for SPI mode and is meaningless in PCM mode.
*/


/*
Bit 1 TXE: Transmit buffer empty
0: Tx buffer not empty
1: Tx buffer empty
*/


/*
Bit 0 RXNE: Receive buffer not empty
0: Rx buffer empty
1: Rx buffer not empty
*/






#define TI_frame_format_error;//

#define Busy_flag;//

#define Overrun_flag;//

#define Mode_fault;//

#define CRC_error_flag;//

#define Underrun_flag;//

#define Channel_side;//

#define Transmit_buffer_empty;//

#define Receive_buffer_not_empty;//


//**************************************************************
//******************************************

//               SPI_HANDLE

//*****************************************************************



// ? // SPI_TypeDef                *Instance;      /*!< SPI registers base address               */

// ? // SPI_InitTypeDef            Init;           /*!< SPI communication parameters             */

// ? // uint8_t                    *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer        */

#define                   TxXferSize;     /*!< SPI Tx Transfer size                     */

//__IO uint16_t              TxXferCount;    /*!< SPI Tx Transfer Counter                  */

// ? // uint8_t                    *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer        */

#define                   RxXferSize;     /*!< SPI Rx Transfer size                     */
















#endif /* STM32F407XX_SPI_DRIVER_H_ */

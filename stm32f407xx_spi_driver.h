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




}SPI_STATE;

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






























#endif /* STM32F407XX_SPI_DRIVER_H_ */

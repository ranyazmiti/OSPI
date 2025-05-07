/*
 * xspi_driver.h
 *
 *  Created on: May 7, 2025
 *      Author: LENOVO
 */

#ifndef APPLICATION_USER_CORE_INC_XSPI_DRIVER_H_
#define APPLICATION_USER_CORE_INC_XSPI_DRIVER_H_

#include "stm32h5xx_hal.h"
#include "stm32h5xx_hal_xspi.h"
#include <stddef.h>
#include <stdint.h>

#define PAGE_SIZE      256
#define XSPI_TIMEOUT   5000

int XSPI_Read(void *buffer, uint32_t address, size_t size);
int XSPI_Write(const void *buffer, uint32_t address, size_t size);
int XSPI_Erase_Block(uint32_t address);

#endif // XSPI_DRIVER_H

//#endif /* APPLICATION_USER_CORE_INC_XSPI_DRIVER_H_ */

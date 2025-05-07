/*
 * xspi_driver.h
 *
 *  Created on: May 7, 2025
 *      Author: LENOVO
 */

#ifndef APPLICATION_USER_CORE_INC_XSPI_DRIVER_H_
#define APPLICATION_USER_CORE_INC_XSPI_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "stm32h5xx_hal.h"
#include <stdint.h>
#include <stddef.h>

#define BLOCK_SIZE     4096
#define PAGE_SIZE      256
#define XSPI_TIMEOUT   5000

int XSPI_Init(void);
int XSPI_EraseSector(uint32_t address);
int XSPI_Write(const void *buffer, uint32_t address, size_t size);
int XSPI_Read(void *buffer, uint32_t address, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_USER_CORE_INC_XSPI_DRIVER_H_ */

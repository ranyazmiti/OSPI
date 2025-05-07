/*
 * ospi_driver.h
 *
 *  Created on: May 6, 2025
 *      Author: LENOVO
 */

#ifndef APPLICATION_USER_INC_OSPI_DRIVER_H_
#define APPLICATION_USER_INC_OSPI_DRIVER_H_



#include <stdint.h>
#include <stddef.h>

int OSPI_Read(void *buffer, uint32_t address, size_t size);
int OSPI_Write(const void *buffer, uint32_t address, size_t size);
int OSPI_Erase_Block(uint32_t address);


#endif /* APPLICATION_USER_INC_OSPI_DRIVER_H_ */

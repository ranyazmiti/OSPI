#include "xspi_driver.h"
#include "lfs.h"
#include "lfs_util.h"
#include "stm32h5xx_hal.h"
#include "lfs_config.h"

extern XSPI_HandleTypeDef hospi1;
uint32_t addr;
int xspi_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size) {
    uint32_t addr = block * c->block_size + off;
    if (XSPI_Read( buffer, addr, size) != HAL_OK) {
        return LFS_ERR_IO;
    }
    return 0;
}

int xspi_write(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size) {
	addr = block * c->block_size + off;
    if (XSPI_Write((uint8_t *)buffer, addr, size) != HAL_OK) {
        return LFS_ERR_IO;
    }
    return 0;
}

int xspi_erase(const struct lfs_config *c, lfs_block_t block) {
	addr = block * c->block_size;
    if (XSPI_Erase( addr, c->block_size) != HAL_OK) {
        return LFS_ERR_IO;
    }
    return 0;
}

int xspi_sync(const struct lfs_config *c) {
    return 0;
}

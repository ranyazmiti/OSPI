#include "lfs.h"
#include "lfs_util.h"
#include "stm32h573i_discovery_xspi.h"
#include "lfs_config.h"
#include <string.h>

#define BLOCK_SIZE      4096
#define BLOCK_COUNT     (64UL * 1024 * 1024 / BLOCK_SIZE)
#define OSPI_BASE_ADDR  0x90000000

// Initialisation automatique de l’XSPI
static void xspi_init_if_needed(void) {
    static uint8_t initialized = 0;
    if (!initialized) {
        if (BSP_XSPI_NOR_Init(0, NULL) != BSP_ERROR_NONE) {
            while (1);  // Bloque si l'init échoue (option à adapter)
        }
        initialized = 1;
    }
}

// Interface de LittleFS
int user_provided_block_device_read(const struct lfs_config *c, lfs_block_t block,
                                    lfs_off_t offset, void *buffer, lfs_size_t size) {
    xspi_init_if_needed();
    uint32_t addr = OSPI_BASE_ADDR + block * c->block_size + offset;
    if (BSP_XSPI_NOR_Read(0, buffer, addr, size) != BSP_ERROR_NONE) {
        return LFS_ERR_IO;
    }
    return 0;
}

int user_provided_block_device_prog(const struct lfs_config *c, lfs_block_t block,
                                    lfs_off_t offset, const void *buffer, lfs_size_t size) {
    xspi_init_if_needed();
    uint32_t addr = OSPI_BASE_ADDR + block * c->block_size + offset;
    if (BSP_XSPI_NOR_Write(0, buffer, addr, size) != BSP_ERROR_NONE) {
        return LFS_ERR_IO;
    }
    return 0;
}

int user_provided_block_device_erase(const struct lfs_config *c, lfs_block_t block) {
    xspi_init_if_needed();
    uint32_t addr = OSPI_BASE_ADDR + block * c->block_size;
    if (BSP_XSPI_NOR_Erase_Block(0, addr, BSP_XSPI_NOR_ERASE_4K) != BSP_ERROR_NONE) {
        return LFS_ERR_IO;
    }
    return 0;
}

int user_provided_block_device_sync(const struct lfs_config *c) {
    xspi_init_if_needed();
    if (BSP_XSPI_NOR_GetStatus(0) != BSP_ERROR_NONE) {
        return LFS_ERR_IO;
    }
    return 0;
}

// Config globale utilisée par LittleFS
struct lfs_config cfg = {
    .read  = user_provided_block_device_read,
    .prog  = user_provided_block_device_prog,
    .erase = user_provided_block_device_erase,
    .sync  = user_provided_block_device_sync,

    .read_size = 256,
    .prog_size = 256,
    .block_size = BLOCK_SIZE,
    .block_count = BLOCK_COUNT,
    .cache_size = 256,
    .lookahead_size = 16,
    .block_cycles = 1000,
};

// Fonction utilisée dans main.c pour init le XSPI depuis l'extérieur
void lfs_config_init(void) {
    xspi_init_if_needed();
}


#include "lfs.h"
#include <string.h>
#include "ospi_driver.h"

#define BLOCK_SIZE       256
#define BLOCK_COUNT      128
#define OSPI_BASE_ADDR   0x90000000


int user_provided_block_device_read(const struct lfs_config *c,
                                    lfs_block_t block,
                                    lfs_off_t offset,
                                    void *buffer,
                                    lfs_size_t size) {
    uint32_t addr = OSPI_BASE_ADDR + block * c->block_size + offset;
    return OSPI_Read(buffer, addr, size);
}

int user_provided_block_device_prog(const struct lfs_config *c,
                                    lfs_block_t block,
                                    lfs_off_t offset,
                                    const void *buffer,
                                    lfs_size_t size) {
    uint32_t addr = OSPI_BASE_ADDR + block * c->block_size + offset;
    return OSPI_Write(buffer, addr, size);
}

int user_provided_block_device_erase(const struct lfs_config *c,
                                     lfs_block_t block) {
    uint32_t addr = OSPI_BASE_ADDR + block * c->block_size;
    return OSPI_Erase_Block(addr);
}

int user_provided_block_device_sync(const struct lfs_config *c) {
    return 0;
}

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



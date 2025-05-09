#include "lfs.h"
#include "lfs_util.h"
#include "xspi_driver.h"
#include <string.h>
#include "lfs_config.h"

#define BLOCK_SIZE  4096
#define BLOCK_COUNT (64UL * 1024 * 1024 / BLOCK_SIZE)
#define OSPI_BASE_ADDR 0x90000000

int user_provided_block_device_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t offset, void *buffer, lfs_size_t size) {
    return xspi_read(c, block, offset, buffer, size);
}

int user_provided_block_device_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t offset, const void *buffer, lfs_size_t size) {
    return xspi_write(c, block, offset, buffer, size);
}

int user_provided_block_device_erase(const struct lfs_config *c, lfs_block_t block) {
    return xspi_erase(c, block);
}

int user_provided_block_device_sync(const struct lfs_config *c) {
    return xspi_sync(c);
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

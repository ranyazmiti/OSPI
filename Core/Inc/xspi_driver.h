#ifndef __XSPI_DRIVER_H
#define __XSPI_DRIVER_H

#include "main.h"
#include "lfs.h"
#include "lfs_util.h"

int xspi_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size);
int xspi_write(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size);
int xspi_erase(const struct lfs_config *c, lfs_block_t block);
int xspi_sync(const struct lfs_config *c);

#endif /* __XSPI_DRIVER_H */

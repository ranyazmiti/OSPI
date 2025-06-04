#ifndef LFS_CONFIG_H
#define LFS_CONFIG_H

#include "lfs.h"



#ifdef __cplusplus
extern "C" {
#endif

int user_provided_block_device_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t offset, void *buffer, lfs_size_t size);
int user_provided_block_device_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t offset, const void *buffer, lfs_size_t size);
int user_provided_block_device_erase(const struct lfs_config *c, lfs_block_t block);
int user_provided_block_device_sync(const struct lfs_config *c);

void lfs_config_init(void);  // ✅ à ajouter

extern struct lfs_config cfg;

#ifdef __cplusplus
}
#endif

#endif // LFS_CONFIG_H

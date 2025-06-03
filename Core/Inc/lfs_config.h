/*
 * lfs_config.h
 *
 *  Created on: May 9, 2025
 *      Author: hp
 */

#ifndef LFS_CONFIG_H
#define LFS_CONFIG_H

#include "lfs.h"

// Taille d'un bloc (en octets)
#define BLOCK_SIZE  4096

// Nombre total de blocs sur le périphérique (ex : 64 Mo / BLOCK_SIZE)
#define BLOCK_COUNT (64UL * 1024 * 1024 / BLOCK_SIZE)

// Adresse de base du périphérique mémoire (optionnelle selon ton usage)
#define OSPI_BASE_ADDR 0x90000000

#ifdef __cplusplus
extern "C" {
#endif

// Fonctions fournies par l'utilisateur pour l'accès au périphérique
int user_provided_block_device_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t offset, void *buffer, lfs_size_t size);
int user_provided_block_device_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t offset, const void *buffer, lfs_size_t size);
int user_provided_block_device_erase(const struct lfs_config *c, lfs_block_t block);
int user_provided_block_device_sync(const struct lfs_config *c);

// Configuration de LittleFS
extern struct lfs_config cfg;

#ifdef __cplusplus
}
#endif

#endif // LFS_CONFIG_H

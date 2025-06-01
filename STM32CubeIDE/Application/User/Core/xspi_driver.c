#include "xspi_driver.h"
#include "lfs.h"
#include "lfs_util.h"
#include "stm32h5xx_hal.h"
#include "lfs_config.h"







extern XSPI_HandleTypeDef hospi1;
uint32_t addr;

int xspi_hw_read(uint32_t address, uint8_t *buffer, size_t size) {
    XSPI_RegularCmdTypeDef sCommand = {0};

    sCommand.OperationType = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.Instruction = 0x0B;  // 🛠️ à ajuster selon ta mémoire
    sCommand.InstructionMode = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.Address = address;
    sCommand.AddressMode = HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressWidth = HAL_XSPI_ADDRESS_32_BITS;  // ← ICI
    sCommand.DataMode = HAL_XSPI_DATA_1_LINE;
    sCommand.DataLength = size;  // ← ICI
    sCommand.DummyCycles = 8;  // 🛠️ selon ta mémoire
    sCommand.DQSMode = HAL_XSPI_DQS_DISABLE;
    sCommand.SIOOMode = HAL_XSPI_SIOO_INST_EVERY_CMD;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) return HAL_ERROR;
    if (HAL_XSPI_Receive(&hospi1, buffer, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) return HAL_ERROR;
    return HAL_OK;
}


int xspi_hw_write(uint32_t address, const uint8_t *buffer, size_t size) {
    XSPI_RegularCmdTypeDef sCommand = {0};

    sCommand.OperationType = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.Instruction = 0x02;  // 🛠️ à vérifier dans ta datasheet
    sCommand.InstructionMode = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.Address = address;
    sCommand.AddressMode = HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressWidth = HAL_XSPI_ADDRESS_32_BITS;  // ← ICI
    sCommand.DataMode = HAL_XSPI_DATA_1_LINE;
    sCommand.DataLength = size;  // ← ICI
    sCommand.DQSMode = HAL_XSPI_DQS_DISABLE;
    sCommand.SIOOMode = HAL_XSPI_SIOO_INST_EVERY_CMD;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) return HAL_ERROR;
    if (HAL_XSPI_Transmit(&hospi1, (uint8_t *)buffer, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) return HAL_ERROR;
    return HAL_OK;
}


int xspi_hw_erase(uint32_t address) {
    XSPI_RegularCmdTypeDef sCommand = {0};

    sCommand.OperationType = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.Instruction = 0x20;  // 🛠️ opcode erase 4KB
    sCommand.InstructionMode = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.Address = address;
    sCommand.AddressMode = HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressWidth = HAL_XSPI_ADDRESS_32_BITS;  // ← ICI
    sCommand.DataMode = HAL_XSPI_DATA_NONE;
    sCommand.DQSMode = HAL_XSPI_DQS_DISABLE;
    sCommand.SIOOMode = HAL_XSPI_SIOO_INST_EVERY_CMD;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) return HAL_ERROR;

    // (optionnel) polling de fin d'effacement

    return HAL_OK;
}

int xspi_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size) {
    uint32_t addr = block * c->block_size + off;
    return xspi_hw_read(addr, buffer, size) == HAL_OK ? 0 : LFS_ERR_IO;
}

int xspi_write(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size) {
    uint32_t addr = block * c->block_size + off;
    return xspi_hw_write(addr, (const uint8_t *)buffer, size) == HAL_OK ? 0 : LFS_ERR_IO;
}

int xspi_erase(const struct lfs_config *c, lfs_block_t block) {
    uint32_t addr = block * c->block_size;
    return xspi_hw_erase(addr) == HAL_OK ? 0 : LFS_ERR_IO;
}

int xspi_sync(const struct lfs_config *c) {
    return 0;  // Rien à faire pour la plupart des flash NOR
}


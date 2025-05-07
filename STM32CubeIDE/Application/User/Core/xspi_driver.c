#include "xspi_driver.h"

extern XSPI_HandleTypeDef hospi1;

int XSPI_Init(void) {
    // Si déjà initialisé dans MX_XSPI1_Init(), rien à faire
    return 0;
}

int XSPI_Erase_Block(uint32_t address) {
    XSPI_RegularCmdTypeDef sCommand = {0};

    sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction        = 0x20; // Sector erase
    sCommand.AddressMode        = HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressWidth        = HAL_XSPI_ADDRESS_24_BITS;
    sCommand.Address            = address;
    sCommand.DataMode           = HAL_XSPI_DATA_NONE;
    sCommand.DummyCycles        = 0;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;
    sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_DISABLE;
    sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_DISABLE;

    if (HAL_XSPI_Command(&hospi1, &sCommand, XSPI_TIMEOUT) != HAL_OK)
        return -1;

    // Attente que l'effacement soit terminé (ajouter si nécessaire)
    return 0;
}

int XSPI_Write(const void *buffer, uint32_t address, size_t size) {
    XSPI_RegularCmdTypeDef sCommand = {0};

    sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction        = 0x02; // Page program
    sCommand.AddressMode        = HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressWidth        = HAL_XSPI_ADDRESS_24_BITS;
    sCommand.Address            = address;
    sCommand.DataMode           = HAL_XSPI_DATA_1_LINE;
    sCommand.DataLength         = size;
    sCommand.DummyCycles        = 0;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;
    sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_DISABLE;
    sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_DISABLE;

    if (HAL_XSPI_Command(&hospi1, &sCommand, XSPI_TIMEOUT) != HAL_OK)
        return -1;

    if (HAL_XSPI_Transmit(&hospi1, (uint8_t *)buffer, XSPI_TIMEOUT) != HAL_OK)
        return -1;

    return 0;
}

int XSPI_Read(void *buffer, uint32_t address, size_t size) {
    XSPI_RegularCmdTypeDef sCommand = {0};

    sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction        = 0x03; // Read data
    sCommand.AddressMode        = HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressWidth        = HAL_XSPI_ADDRESS_24_BITS;
    sCommand.Address            = address;
    sCommand.DataMode           = HAL_XSPI_DATA_1_LINE;
    sCommand.DataLength         = size;
    sCommand.DummyCycles        = 0;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;
    sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_DISABLE;
    sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_DISABLE;

    if (HAL_XSPI_Command(&hospi1, &sCommand, XSPI_TIMEOUT) != HAL_OK)
        return -1;

    if (HAL_XSPI_Receive(&hospi1, (uint8_t *)buffer, XSPI_TIMEOUT) != HAL_OK)
        return -1;

    return 0;
}

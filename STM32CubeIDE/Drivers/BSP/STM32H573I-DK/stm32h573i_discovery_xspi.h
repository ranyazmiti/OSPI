#ifndef STM32H573I_DK_XSPI_H
#define STM32H573I_DK_XSPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h573i_discovery_conf.h"
#include "stm32h573i_discovery_errno.h"
#include "../Components/mx25lm51245g/mx25lm51245g.h"
#include "stm32h5xx_hal_xspi.h"  // XSPI instead of OSPI

typedef enum
{
  XSPI_ACCESS_NONE = 0,
  XSPI_ACCESS_INDIRECT,
  XSPI_ACCESS_MMP
} XSPI_Access_t;

#if (USE_HAL_XSPI_REGISTER_CALLBACKS == 1)
typedef struct
{
  pXSPI_CallbackTypeDef  pMspInitCb;
  pXSPI_CallbackTypeDef  pMspDeInitCb;
} BSP_XSPI_Cb_t;
#endif

typedef struct
{
  uint32_t MemorySize;
  uint32_t ClockPrescaler;
  uint32_t SampleShifting;
  uint32_t TransferRate;
} MX_XSPI_InitTypeDef;

#define BSP_XSPI_NOR_Info_t                MX25LM51245G_Info_t
#define BSP_XSPI_NOR_Interface_t           MX25LM51245G_Interface_t
#define BSP_XSPI_NOR_Transfer_t            MX25LM51245G_Transfer_t
#define BSP_XSPI_NOR_Erase_t               MX25LM51245G_Erase_t

typedef struct
{
  XSPI_Access_t              IsInitialized;
  BSP_XSPI_NOR_Interface_t   InterfaceMode;
  BSP_XSPI_NOR_Transfer_t    TransferRate;
} XSPI_NOR_Ctx_t;

typedef struct
{
  BSP_XSPI_NOR_Interface_t   InterfaceMode;
  BSP_XSPI_NOR_Transfer_t    TransferRate;
} BSP_XSPI_NOR_Init_t;

/* Clock & GPIO settings */
#define XSPI_NOR_CLK_ENABLE()                 __HAL_RCC_OSPI1_CLK_ENABLE()
#define XSPI_NOR_CLK_DISABLE()                __HAL_RCC_OSPI1_CLK_DISABLE()
#define XSPI_NOR_FORCE_RESET()                __HAL_RCC_OSPI1_FORCE_RESET()
#define XSPI_NOR_RELEASE_RESET()              __HAL_RCC_OSPI1_RELEASE_RESET()

#define XSPI_NOR_CS_PIN                       GPIO_PIN_6
#define XSPI_NOR_CS_GPIO_PORT                 GPIOG
#define XSPI_NOR_CS_PIN_AF                    GPIO_AF10_OCTOSPI1
#define XSPI_NOR_CS_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOG_CLK_ENABLE()

#define XSPI_NOR_CLK_PIN                      GPIO_PIN_10
#define XSPI_NOR_CLK_GPIO_PORT                GPIOF
#define XSPI_NOR_CLK_PIN_AF                   GPIO_AF9_OCTOSPI1
#define XSPI_NOR_CLK_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOF_CLK_ENABLE()

#define XSPI_NOR_DQS_PIN                      GPIO_PIN_2
#define XSPI_NOR_DQS_GPIO_PORT                GPIOB
#define XSPI_NOR_DQS_PIN_AF                   GPIO_AF10_OCTOSPI1
#define XSPI_NOR_DQS_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOB_CLK_ENABLE()

#define XSPI_NOR_D0_PIN                       GPIO_PIN_1
#define XSPI_NOR_D0_GPIO_PORT                 GPIOB
#define XSPI_NOR_D0_PIN_AF                    GPIO_AF6_OCTOSPI1
#define XSPI_NOR_D0_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOB_CLK_ENABLE()

#define XSPI_NOR_D1_PIN                       GPIO_PIN_12
#define XSPI_NOR_D1_GPIO_PORT                 GPIOD
#define XSPI_NOR_D1_PIN_AF                    GPIO_AF9_OCTOSPI1
#define XSPI_NOR_D1_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOD_CLK_ENABLE()

#define XSPI_NOR_D2_PIN                       GPIO_PIN_2
#define XSPI_NOR_D2_GPIO_PORT                 GPIOC
#define XSPI_NOR_D2_PIN_AF                    GPIO_AF9_OCTOSPI1
#define XSPI_NOR_D2_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()

#define XSPI_NOR_D3_PIN                       GPIO_PIN_13
#define XSPI_NOR_D3_GPIO_PORT                 GPIOD
#define XSPI_NOR_D3_PIN_AF                    GPIO_AF9_OCTOSPI1
#define XSPI_NOR_D3_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOD_CLK_ENABLE()

#define XSPI_NOR_D4_PIN                       GPIO_PIN_2
#define XSPI_NOR_D4_GPIO_PORT                 GPIOH
#define XSPI_NOR_D4_PIN_AF                    GPIO_AF9_OCTOSPI1
#define XSPI_NOR_D4_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()

#define XSPI_NOR_D5_PIN                       GPIO_PIN_3
#define XSPI_NOR_D5_GPIO_PORT                 GPIOH
#define XSPI_NOR_D5_PIN_AF                    GPIO_AF9_OCTOSPI1
#define XSPI_NOR_D5_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()

#define XSPI_NOR_D6_PIN                       GPIO_PIN_9
#define XSPI_NOR_D6_GPIO_PORT                 GPIOG
#define XSPI_NOR_D6_PIN_AF                    GPIO_AF9_OCTOSPI1
#define XSPI_NOR_D6_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOG_CLK_ENABLE()

#define XSPI_NOR_D7_PIN                       GPIO_PIN_0
#define XSPI_NOR_D7_GPIO_PORT                 GPIOC
#define XSPI_NOR_D7_PIN_AF                    GPIO_AF10_OCTOSPI1
#define XSPI_NOR_D7_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()

#define XSPI_NOR_INSTANCES_NUMBER         1U

#define BSP_XSPI_NOR_SPI_MODE (BSP_XSPI_NOR_Interface_t)MX25LM51245G_SPI_MODE
#define BSP_XSPI_NOR_OPI_MODE (BSP_XSPI_NOR_Interface_t)MX25LM51245G_OPI_MODE

#define BSP_XSPI_NOR_STR_TRANSFER  (BSP_XSPI_NOR_Transfer_t)MX25LM51245G_STR_TRANSFER
#define BSP_XSPI_NOR_DTR_TRANSFER  (BSP_XSPI_NOR_Transfer_t)MX25LM51245G_DTR_TRANSFER

#define BSP_XSPI_NOR_ERASE_4K             MX25LM51245G_ERASE_4K
#define BSP_XSPI_NOR_ERASE_64K            MX25LM51245G_ERASE_64K
#define BSP_XSPI_NOR_ERASE_CHIP           MX25LM51245G_ERASE_BULK

#define BSP_XSPI_NOR_BLOCK_4K             MX25LM51245G_SUBSECTOR_4K
#define BSP_XSPI_NOR_BLOCK_64K            MX25LM51245G_SECTOR_64K

extern XSPI_HandleTypeDef hxsip_nor[XSPI_NOR_INSTANCES_NUMBER];
extern XSPI_NOR_Ctx_t Xspi_Nor_Ctx[XSPI_NOR_INSTANCES_NUMBER];

int32_t BSP_XSPI_NOR_Init(uint32_t Instance, BSP_XSPI_NOR_Init_t *Init);
int32_t BSP_XSPI_NOR_DeInit(uint32_t Instance);
#if (USE_HAL_XSPI_REGISTER_CALLBACKS == 1)
int32_t BSP_XSPI_NOR_RegisterMspCallbacks(uint32_t Instance, BSP_XSPI_Cb_t *CallBacks);
int32_t BSP_XSPI_NOR_RegisterDefaultMspCallbacks(uint32_t Instance);
#endif
int32_t BSP_XSPI_NOR_Read(uint32_t Instance, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t BSP_XSPI_NOR_Write(uint32_t Instance, const uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t BSP_XSPI_NOR_Erase_Block(uint32_t Instance, uint32_t BlockAddress, BSP_XSPI_NOR_Erase_t BlockSize);
int32_t BSP_XSPI_NOR_Erase_Chip(uint32_t Instance);
int32_t BSP_XSPI_NOR_GetStatus(uint32_t Instance);
int32_t BSP_XSPI_NOR_GetInfo(uint32_t Instance, BSP_XSPI_NOR_Info_t *pInfo);
int32_t BSP_XSPI_NOR_EnableMemoryMappedMode(uint32_t Instance);
int32_t BSP_XSPI_NOR_DisableMemoryMappedMode(uint32_t Instance);
int32_t BSP_XSPI_NOR_ReadID(uint32_t Instance, uint8_t *Id);
int32_t BSP_XSPI_NOR_ConfigFlash(uint32_t Instance, BSP_XSPI_NOR_Interface_t Mode, BSP_XSPI_NOR_Transfer_t Rate);
int32_t BSP_XSPI_NOR_SuspendErase(uint32_t Instance);
int32_t BSP_XSPI_NOR_ResumeErase(uint32_t Instance);
int32_t BSP_XSPI_NOR_EnterDeepPowerDown(uint32_t Instance);
int32_t BSP_XSPI_NOR_LeaveDeepPowerDown(uint32_t Instance);

HAL_StatusTypeDef MX_XSPI_NOR_Init(XSPI_HandleTypeDef *hxsip, MX_XSPI_InitTypeDef *Init);

#ifdef __cplusplus
}
#endif

#endif /* STM32H573I_DK_XSPI_H */

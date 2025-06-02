#ifndef STM32H573I_DISCOVERY_CONF_H
#define STM32H573I_DISCOVERY_CONF_H

// Active seulement OSPI NOR
#define USE_BSP_OSPI_NOR            1U

// Désactive les autres périphériques inutiles
#define USE_BSP_COM_FEATURE         0U
#define USE_BSP_AUDIO_FEATURE       0U
#define USE_BSP_TS_FEATURE          0U
#define USE_BSP_SD_FEATURE          0U
#define USE_BSP_IO_CLASS            1U

#endif /* STM32H573I_DISCOVERY_CONF_H */

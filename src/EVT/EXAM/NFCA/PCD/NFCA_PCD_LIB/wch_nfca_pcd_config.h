/********************************** (C) COPYRIGHT *******************************
 * File Name          : wch_nfca_pcd_config.h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2024/08/22
 * Description        : NFC-A PCD底层配置
 *********************************************************************************
 * Copyright (c) 2024 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#ifndef _WCH_NFCA_PCD_CONFIG_H_
#define _WCH_NFCA_PCD_CONFIG_H_

#include "CH58x_common.h"

#ifndef NFCA_PCD_DATA_BUF_SIZE
#define NFCA_PCD_DATA_BUF_SIZE                                  32      /* NFC PCD信号数据缓存区大小配置 */
#endif

#if NFCA_PCD_DATA_BUF_SIZE < 20
#error "NFCA_PCD_DATA_BUF_SIZE must bigger or equal than 20."
#endif

#ifndef NFCA_PCD_WAIT_MAX_MS
#define NFCA_PCD_WAIT_MAX_MS                                    1000    /* 每次通讯的最大等待时间，超过则异常结束，需要根据不同卡片的情况修改。 */
#endif

#ifndef NFCA_PCD_LPCD_THRESHOLD_PERMIL
#define NFCA_PCD_LPCD_THRESHOLD_PERMIL                          5       /* 低功耗检卡的ADC差值比例阈值，千分比。不可以小于3，过小可能导致误唤醒 */
#endif

#if NFCA_PCD_LPCD_THRESHOLD_PERMIL < 3
#error "NFCA_PCD_LPCD_THRESHOLD_PERMIL must bigger or equal than 3."
#endif

#ifndef NFCA_PCD_LPCD_THRESHOLD_MAX_LIMIT_PERMIL
#define NFCA_PCD_LPCD_THRESHOLD_MAX_LIMIT_PERMIL                20      /* 低功耗检卡的检测值变大时进行阈值更新的限幅，千分比。 */
#endif

#ifndef NFCA_PCD_LPCD_THRESHOLD_MIN_LIMIT_PERMIL
#define NFCA_PCD_LPCD_THRESHOLD_MIN_LIMIT_PERMIL                1       /* 低功耗检卡的检测值变小时进行阈值更新的限幅，千分比。 */
#endif

#endif  /* _WCH_NFCA_PCD_CONFIG_H_ */

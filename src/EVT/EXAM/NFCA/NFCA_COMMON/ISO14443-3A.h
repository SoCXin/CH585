/********************************** (C) COPYRIGHT *******************************
 * File Name          : ISO14443-3A.h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2024/08/05
 * Description        : ISO14443-3A相关函数
 * Copyright (c) 2024 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#ifndef _ISO14443_3A_H_
#define _ISO14443_3A_H_

#include "CH58x_common.h"
#include "wch_nfca_crypto1.h"

#define ISO14443A_CMD_REQA                          0x26
#define ISO14443A_CMD_WUPA                          0x52
#define ISO14443A_CMD_SELECT_CL1                    0x93
#define ISO14443A_CMD_SELECT_CL2                    0x95
#define ISO14443A_CMD_SELECT_CL3                    0x97
#define ISO14443A_CMD_HLTA                          0x50

#define ISO14443A_NVB_AC_START                      0x20
#define ISO14443A_NVB_AC_END                        0x70

#define ISO14443A_CL_UID_OFFSET                     0
#define ISO14443A_CL_UID_SIZE                       4
#define ISO14443A_CL_BCC_OFFSET                     4
#define ISO14443A_CL_BCC_SIZE                       1
#define ISO14443A_CL_FRAME_SIZE                     ((ISO14443A_CL_UID_SIZE + ISO14443A_CL_BCC_SIZE) * 8)
#define ISO14443A_SAK_INCOMPLETE                    0x24
#define ISO14443A_SAK_INCOMPLETE_NOT_COMPLIANT      0x04
#define ISO14443A_SAK_COMPLETE_COMPLIANT            0x20
#define ISO14443A_SAK_COMPLETE_NOT_COMPLIANT        0x00

#define ISO14443A_ATQA_FRAME_SIZE_BYTES             (2)
#define ISO14443A_ATQA_FRAME_SIZE                   (2 * 8)
#define ISO14443A_SAK_FRAME_SIZE                    (3 * 8)
#define ISO14443A_HLTA_FRAME_SIZE                   (2 * 8)

#define ISO14443A_CRCA_SIZE                         2

#define CRC_INIT                                    0x6363
#define CRC_INIT_R                                  0xC6C6

/* 计算BCC校验码 */
#define ISO14443A_CALC_BCC(ByteBuffer)              (ByteBuffer[0] ^ ByteBuffer[1] ^ ByteBuffer[2] ^ ByteBuffer[3])

/* 检查BCC校验码 */
#define ISO14443A_CHECK_BCC(B)                      ((B[0] ^ B[1] ^ B[2] ^ B[3]) == B[4])

/*********************************************************************
 * @fn      ISO14443_CRCA
 *
 * @brief   check CRC.
 *
 * @param   Buffer - the data need to check
 *          ByteCount -  the length of data
 *
 * @return  0 if no error.
 */
extern uint16_t ISO14443_CRCA(uint8_t *buf, uint8_t len);

/*********************************************************************
 * @fn      ISO14443AAppendCRCA
 *
 * @brief   add CRC value behind the data.
 *
 * @param   buf - the data need to check
 *          len -  the length of data
 *
 * @return  crc value.
 */
extern uint16_t ISO14443AAppendCRCA(void *buf, uint16_t len);

/*********************************************************************
 * @fn      ISO14443ACheckOddParityBit
 *
 * @brief   check odd parity bit.
 *
 * @param   data - the data need to check
 *          parity - the parity need to check
 *          len -  the length of data
 *
 * @return  1 if the parity is correct, 0 is wrong.
 */
extern uint8_t ISO14443ACheckOddParityBit(uint8_t *data, uint8_t *parity, uint16_t len);

/*********************************************************************
 * @fn      ISO14443ACalOddParityBit
 *
 * @brief   check odd parity bit.
 *
 * @param   data - the data need to check
 *          parity - the parity need to check
 *          len -  the length of data
 *
 * @return  1 if the parity is correct, 0 is wrong.
 */
extern void ISO14443ACalOddParityBit(uint8_t *data, uint8_t *out_parity, uint16_t len);

#endif  /* _ISO14443_3A_H_ */

/********************************** (C) COPYRIGHT *******************************
 * File Name          : ISO14443-3A.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2024/08/05
 * Description        : ISO14443-3A相关函数
 * Copyright (c) 2024 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#include "ISO14443-3A.h"

#define HI_UINT16(a) (((a) >> 8) & 0xFF)
#define LO_UINT16(a) ((a) & 0xFF)

RV_STATIC_INLINE uint16_t _crc_ccitt_update(uint16_t crc, uint8_t data)
{
    data ^= LO_UINT16(crc);
    data ^= data << 4;

    return ((((uint16_t)data << 8) | HI_UINT16(crc)) ^ (uint8_t)(data >> 4)
            ^ ((uint16_t)data << 3));
}

/*********************************************************************
 * @fn      ISO14443_CRCA
 *
 * @brief   检查CRC是否正确
 *
 * @param   buf      - 数据指针
 * @param   len   - 数据长度
 *
 * @return  0 if everything is ok, others is error.
 */
uint16_t ISO14443_CRCA(uint8_t *buf, uint8_t len)
{
    uint8_t *data = buf;
    uint16_t crc = CRC_INIT;
    uint8_t ch;
    while (len--)
    {
        ch = *data++ ^ crc;
        ch = ch ^ (ch << 4);
        crc = (crc >> 8) ^ (ch << 8) ^ (ch << 3) ^ (ch >> 4);
    }
    return crc;
}

/*********************************************************************
 * @fn      ISO14443AAppendCRCA
 *
 * @brief   在数据尾部生成CRC
 *
 * @param   buf      - 数据指针
 * @param   len   - 数据长度
 *
 * @return  CRC.
 */
uint16_t ISO14443AAppendCRCA(void *buf, uint16_t len)
{
    uint16_t crc = CRC_INIT;
    uint8_t *data = (uint8_t *) buf;

    while (len--)
    {
        uint8_t byte8 = *data++;
        crc = _crc_ccitt_update(crc, byte8);
    }

    data[0] = (crc >> 0) & 0x00FF;
    data[1] = (crc >> 8) & 0x00FF;

    return crc;
}

/*********************************************************************
 * @fn      ISO14443ACheckOddParityBit
 *
 * @brief   检查奇校验位
 *
 * @param   data      - 数据指针
 * @param   parity    - 校验位指针
 * @param   len       - 数据长度
 *
 * @return  1 if ok, 0 if error.
 */
uint8_t ISO14443ACheckOddParityBit(uint8_t *data, uint8_t *parity, uint16_t len)
{
    uint16_t i;
    uint8_t odd;

    for (i = 0; i < len; i++)
    {
        if ((byteParityBitsTable[data[i]]) != parity[i])
        {
            return 0;
        }
    }
    return 1;
}

/*********************************************************************
 * @fn      ISO14443ACalOddParityBit
 *
 * @brief   计算奇校验位
 *
 * @param   data        - 数据指针
 * @param   out_parity  - 校验位指针
 * @param   len         - 数据长度
 *
 * @return  None.
 */
void ISO14443ACalOddParityBit(uint8_t *data, uint8_t *out_parity, uint16_t len)
{
    uint16_t i;

    for (i = 0; i < len; i++)
    {
        out_parity[i] = byteParityBitsTable[data[i]];
    }
}

/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2024/02/27
 * Description        : ������������
 * Copyright (c) 2024 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

/******************************************************************************/
/* ͷ�ļ����� */
#include "Touch.h"
#include "app.h"

/*********************************************************************
 * GLOBAL TYPEDEFS
 */


/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   ���ڴ�ӡ��ʼ��
 *
 * @return  none
 *
 * @note	Uart1��Ĭ��ӳ�����ſ����봥��ͨ����ͻ��
 * 			�ڴ���Ӧ����Ӧѡ������UART��������ӳ��
 */
void DebugInit(void)
{
#ifdef  DEBUG
#if DEBUG == Debug_UART0
	GPIOB_SetBits(GPIO_Pin_7);
	GPIOB_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA);
	UART0_DefInit();
#elif DEBUG == Debug_UART1
	GPIOPinRemap(ENABLE, RB_PIN_UART1);
	GPIOB_SetBits(GPIO_Pin_13);
	GPIOB_ModeCfg(GPIO_Pin_13, GPIO_ModeOut_PP_5mA);
	UART1_DefInit();
#elif DEBUG == Debug_UART2
	GPIOPinRemap(ENABLE, RB_PIN_UART2);
	GPIOB_SetBits(GPIO_Pin_23);
	GPIOB_ModeCfg(GPIO_Pin_23, GPIO_ModeOut_PP_5mA);
	UART2_DefInit();
#elif DEBUG == Debug_UART3
	GPIOPinRemap(ENABLE, RB_PIN_UART3);
	GPIOB_SetBits(GPIO_Pin_21);
	GPIOB_ModeCfg(GPIO_Pin_21, GPIO_ModeOut_PP_5mA);
	UART3_DefInit();
#endif
#endif
}

/*********************************************************************
 * @fn      main
 *
 * @brief   ������
 *
 * @return  none
 */
int main(void)
{
    HSECFG_Capacitance(HSECap_18p);
	SetSysClock(CLK_SOURCE_HSE_PLL_62_4MHz);
	DebugInit();
	PRINT("12 touch keys\n");
    touch_init();
	while(1)
	{
		touch_dataProcess();
	}
}

/******************************** endfile @ main ******************************/
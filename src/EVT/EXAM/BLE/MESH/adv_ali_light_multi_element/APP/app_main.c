/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2021/03/24
 * Description        :
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/******************************************************************************/
/* 头文件包含 */
#include "CONFIG.h"
#include "MESH_LIB.h"
#include "HAL.h"
#include "app_mesh_config.h"
#include "app.h"

/*********************************************************************
 * GLOBAL TYPEDEFS
 */
__attribute__((aligned(4)))  uint32_t MEM_BUF[BLE_MEMHEAP_SIZE / 4];

/*********************************************************************
 * @fn      Main_Circulation
 *
 * @brief   主循环
 *
 * @return  none
 */
__HIGH_CODE
__attribute__((noinline))
void Main_Circulation()
{
    while( 1 )
    {
        TMOS_SystemProcess();
    }
}

/*********************************************************************
 * @fn      bt_mesh_lib_init
 *
 * @brief   mesh 库初始化
 *
 * @return  state
 */
uint8_t bt_mesh_lib_init( void )
{
    uint8_t ret;

    if( tmos_memcmp( VER_MESH_LIB, VER_MESH_FILE, strlen( VER_MESH_FILE ) ) == FALSE )
    {
        PRINT( "mesh head file error...\n" );
        while( 1 );
    }

    ret = RF_RoleInit();

#if ((CONFIG_BLE_MESH_PROXY) || \
	(CONFIG_BLE_MESH_PB_GATT) || \
	(CONFIG_BLE_MESH_OTA))
    ret = GAPRole_PeripheralInit();
#endif /* PROXY || PB-GATT || OTA */

#if (CONFIG_BLE_MESH_PROXY_CLI)
    ret = GAPRole_CentralInit();
#endif /* CONFIG_BLE_MESH_PROXY_CLI */

    MeshTimer_Init();
    MeshDeamon_Init();
    ble_sm_alg_ecc_init();

#if (CONFIG_BLE_MESH_IV_UPDATE_TEST)
    bt_mesh_iv_update_test(TRUE);
#endif
    return ret;
}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
int main( void )
{
    SetSysClock( CLK_SOURCE_HSE_PLL_62_4MHz );

#ifdef DEBUG
    GPIOA_SetBits(GPIO_Pin_14);
    GPIOPinRemap(ENABLE, RB_PIN_UART0);
    GPIOA_ModeCfg(GPIO_Pin_15, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_14, GPIO_ModeOut_PP_5mA);
    UART0_DefInit();
#endif  
    PRINT( "%s\n", VER_LIB );
    PRINT( "%s\n", VER_MESH_LIB );
    CH58x_BLEInit();
    HAL_Init();
    bt_mesh_lib_init();
    App_Init();
    Main_Circulation();
}

/******************************** endfile @ main ******************************/

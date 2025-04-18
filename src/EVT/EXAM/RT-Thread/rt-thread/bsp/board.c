/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-07-24     Tanek        the first version
 * 2018-11-12     Ernest Chen  modify copyright
 */
 
#include <stdint.h>
#include <rthw.h>
#include <rtthread.h>
#include "board.h"

rt_uint32_t _SysTick_Config(rt_uint32_t ticks)
{
    PFIC_SetPriority(SWI_IRQn, 0xf0);
    PFIC_EnableIRQ(SWI_IRQn);

    PFIC_SetPriority(SysTick_IRQn, 0xf0);
    SysTick_Config(ticks);

    return 0;
}

__attribute__((interrupt("WCH-Interrupt-fast")))
__HIGH_CODE
void SysTick_Handler(void)
{
    rt_interrupt_enter();
    rt_tick_increase();
    SysTick->SR=0;
    rt_interrupt_leave();
}

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024
static uint32_t rt_heap[RT_HEAP_SIZE];     // heap default size: 4K(1024 * 4)
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

extern void SW_Handler(void);

/**
 * This function will initial your board.
 */
void rt_hw_board_init()
{
    /* Set system clock */
    HSECFG_Capacitance(HSECap_18p);
    SetSysClock(CLK_SOURCE_HSE_PLL_62_4MHz);

    SetVTFIRQ((uint32_t)SW_Handler, SWI_IRQn, 0, ENABLE);                   /* 提升任务切换速度，不从统一入口执行，在处理期间不可中断嵌套 */
    SetVTFIRQ((uint32_t)SysTick_Handler, SysTick_IRQn, 1, ENABLE);          /* 提升systick中断速度，不从统一入口执行，在处理期间不可中断嵌套 */

    /* System Tick Configuration */
    _SysTick_Config(GetSysClock() / RT_TICK_PER_SECOND);

    /* Call components board initial (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
}


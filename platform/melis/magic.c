/*
*********************************************************************************************************
*											        ePDK
*						            the Easy Portable/Player Develop Kits
*									           hello world sample
*
*						        (c) Copyright 2006-2007, Steven.ZGJ China
*											All	Rights Reserved
*
* File    : pfhead.h
* By      : Steven.ZGJ
* Version : V1.00
*********************************************************************************************************
*/
#ifdef AW_MELIS
#ifndef AW_MELIS4
#include "epdk.h"

extern __s32 app_tui(void *p_arg);
#pragma arm section rodata="MAGIC"
const __exec_mgsec_t exfinfo =
{
	{'e','P','D','K','.','e','x','f'},		//.magic
	0x01000000,								//.version
	0,										//.type
	/*进程堆的地址，必须小于32M，并且保证堆的放置不会操作32M边界            */
	0x1F00000,
	/* 进程堆大小（初值，后续随着需要会自动增加，但最大不能操作32M边界      */
	0x400,
	/*主任务入口地址                                                        */
	app_tui,
	/*主任务栈大小                                                          */
	0x40000,				
	/* 主任伍任务优先级                                                     */
    KRNL_priolevel1		
};
#pragma arm section 
#endif
#endif

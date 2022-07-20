/*
* Copyright (c) 2019-2025 Allwinner Technology Co., Ltd. ALL rights reserved.
*
* Allwinner is a trademark of Allwinner Technology Co.,Ltd., registered in
* the the People's Republic of China and other countries.
* All Allwinner Technology Co.,Ltd. trademarks are used with permission.
*
* DISCLAIMER
* THIRD PARTY LICENCES MAY BE REQUIRED TO IMPLEMENT THE SOLUTION/PRODUCT.
* IF YOU NEED TO INTEGRATE THIRD PARTY¡¯S TECHNOLOGY (SONY, DTS, DOLBY, AVS OR MPEGLA, ETC.)
* IN ALLWINNERS¡¯SDK OR PRODUCTS, YOU SHALL BE SOLELY RESPONSIBLE TO OBTAIN
* ALL APPROPRIATELY REQUIRED THIRD PARTY LICENCES.
* ALLWINNER SHALL HAVE NO WARRANTY, INDEMNITY OR OTHER OBLIGATIONS WITH RESPECT TO MATTERS
* COVERED UNDER ANY REQUIRED THIRD PARTY LICENSE.
* YOU ARE SOLELY RESPONSIBLE FOR YOUR USAGE OF THIRD PARTY¡¯S TECHNOLOGY.
*
*
* THIS SOFTWARE IS PROVIDED BY ALLWINNER"AS IS" AND TO THE MAXIMUM EXTENT
* PERMITTED BY LAW, ALLWINNER EXPRESSLY DISCLAIMS ALL WARRANTIES OF ANY KIND,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING WITHOUT LIMITATION REGARDING
* THE TITLE, NON-INFRINGEMENT, ACCURACY, CONDITION, COMPLETENESS, PERFORMANCE
* OR MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL ALLWINNER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS, OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifdef AW_MELIS4
#include <log.h>
#include <mod_defs.h>
#include <kapi.h>

__mp app_tui_mp = {0, 0};

extern int home_create(char *res_path);

static void app_tui(void *para)
{
	home_create("d:\\res\\res.disk");

	/* kill app_tui self */
	esEXEC_PDel(EXEC_pidself);

	/* del app_tui main thread */
	__log("app_tui thread: Bye Bye!\n");

	esKRNL_TDel(OS_PRIO_SELF);

	esKRNL_TimeDly(100);
}

/*
****************************************************************************************************
*
*                           app_tui_MInit
*
*  Description:
*       app_tui_MInit
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
int32_t app_tui_MInit(void)
{
    return EPDK_OK;
}

/*
****************************************************************************************************
*
*                           app_tui_MExit
*
*  Description:
*       app_tui_MExit
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
int32_t app_tui_MExit(void)
{
    return EPDK_OK;
}

/*
****************************************************************************************************
*
*                           app_tui_MOpen
*
*  Description:
*       app_tui_MOpen
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
__mp *app_tui_MOpen(uint32_t mid, uint32_t mod)
{
    __log("app_tui_MOpen module test\t\n");

    esKRNL_TCreate(app_tui, NULL, 0x8000, 3);   
    
    
    return &app_tui_mp;
}

/*
****************************************************************************************************
*
*             app_tui_MClose
*
*  Description:
*       app_tui_MClose
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
int32_t app_tui_MClose(__mp *mp)
{
    return EPDK_OK;
}

/*
****************************************************************************************************
*
*             app_tui_MRead
*
*  Description:
*       app_tui_MRead
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
uint32_t app_tui_MRead(void *pdata, uint32_t size, uint32_t n, __mp *mp)
{
    return size * n;
}

/*
****************************************************************************************************
*
*             app_tui_MWrite
*
*  Description:
*       app_tui_MWrite
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
uint32_t app_tui_MWrite(const void *pdata, uint32_t size, uint32_t n, __mp *mp)
{
    return size * n;
}

/*
****************************************************************************************************
*
*             app_tui_MIoctrl
*
*  Description:
*       app_tui_MIoctrl
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
long app_tui_MIoctrl(__mp *mp, uint32_t cmd, int32_t aux, void *pbuffer)
{
    /* no ioctl command now */
    return EPDK_OK;
}
#endif


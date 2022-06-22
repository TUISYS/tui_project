/*
* Copyright (c) 2019-2025 Allwinner Technology Co., Ltd. ALL rights reserved.
*
* Allwinner is a trademark of Allwinner Technology Co.,Ltd., registered in
* the the People's Republic of China and other countries.
* All Allwinner Technology Co.,Ltd. trademarks are used with permission.
*
* DISCLAIMER
* THIRD PARTY LICENCES MAY BE REQUIRED TO IMPLEMENT THE SOLUTION/PRODUCT.
* IF YOU NEED TO INTEGRATE THIRD PARTY’S TECHNOLOGY (SONY, DTS, DOLBY, AVS OR MPEGLA, ETC.)
* IN ALLWINNERS’SDK OR PRODUCTS, YOU SHALL BE SOLELY RESPONSIBLE TO OBTAIN
* ALL APPROPRIATELY REQUIRED THIRD PARTY LICENCES.
* ALLWINNER SHALL HAVE NO WARRANTY, INDEMNITY OR OTHER OBLIGATIONS WITH RESPECT TO MATTERS
* COVERED UNDER ANY REQUIRED THIRD PARTY LICENSE.
* YOU ARE SOLELY RESPONSIBLE FOR YOUR USAGE OF THIRD PARTY’S TECHNOLOGY.
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

int app_tui(void *p_arg);

__mp ftest_mp = {0, 0};


void mod_test_thread(void *para)
{
	app_tui();
}

/*
****************************************************************************************************
*
*                           ftest_MInit
*
*  Description:
*       ftest_MInit
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
int32_t ftest_MInit(void)
{
    return EPDK_OK;
}

/*
****************************************************************************************************
*
*                           ftest_MExit
*
*  Description:
*       ftest_MExit
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
int32_t ftest_MExit(void)
{
    return EPDK_OK;
}

/*
****************************************************************************************************
*
*                           ftest_MOpen
*
*  Description:
*       ftest_MOpen
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
__mp *ftest_MOpen(uint32_t mid, uint32_t mod)
{
    __log("ftest_MOpen module test\t\n");

    esKRNL_TCreate(mod_test_thread, NULL, 0x8000, 3);   
    
    
    return &ftest_mp;
}

/*
****************************************************************************************************
*
*             ftest_MClose
*
*  Description:
*       ftest_MClose
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
int32_t ftest_MClose(__mp *mp)
{
    return EPDK_OK;
}

/*
****************************************************************************************************
*
*             ftest_MRead
*
*  Description:
*       ftest_MRead
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
uint32_t ftest_MRead(void *pdata, uint32_t size, uint32_t n, __mp *mp)
{
    return size * n;
}

/*
****************************************************************************************************
*
*             ftest_MWrite
*
*  Description:
*       ftest_MWrite
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
uint32_t ftest_MWrite(const void *pdata, uint32_t size, uint32_t n, __mp *mp)
{
    return size * n;
}

/*
****************************************************************************************************
*
*             ftest_MIoctrl
*
*  Description:
*       ftest_MIoctrl
*
*  Parameters:
*
*  Return value:
*       EPDK_OK
*       EPDK_FAIL
****************************************************************************************************
*/
long ftest_MIoctrl(__mp *mp, uint32_t cmd, int32_t aux, void *pbuffer)
{
    /* no ioctl command now */
    return EPDK_OK;
}
#endif


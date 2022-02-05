#include "tui.h"
#ifdef AW_MELIS
#include "epdk.h"
#endif

static tui_obj_t * this_app_obj;
#ifdef AW_MELIS
static ES_FILE  *hdle = NULL;
static __ev_tp_pos_t *cross_pos;
#endif

tui_obj_t * adjust_adjust_view_view_create(void);
static void adjust_exit(void);

#ifdef AW_MELIS
static int tpdrv_open(void)
{
	hdle = eLIBs_fopen("b:\\input\\TP", "r+");
	if(!hdle) {
		printf("open tp dev file fail\n");
		return -1;
	}
	cross_pos = eLIBs_malloc(sizeof(__ev_tp_pos_t));

	return 0;
}

static int tpdrv_close(void)
{
	if (hdle) {
		eLIBs_fclose(hdle);
	}

	eLIBs_free(cross_pos);

	return 0;
}

static int tp_adjust(__u8 cnt, __ev_tp_pos_t *pbuf)
{
	int	ret;

	ret = eLIBs_fioctrl(hdle, DRV_TP_CMD_ADJUST, cnt, pbuf);

	return ret;
}

static void adjust_thread_entry(void *parameter)
{
	int ret, index;

	tpdrv_open();

	tp_adjust(0, 0);

	index = 1;
	while (1) {
		if (index == 1) {
			cross_pos->disp_xpos = 50+15;
			cross_pos->disp_ypos = 50+15;
			ret = tp_adjust(index, (void *)cross_pos);
			printf("ADJUT%d:%d\n", index, ret);
			if (ret != EPDK_OK) {
				if(ret == -2) {
					tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_START, NULL, NULL);
					index = 1;
				}
				tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_FAIL, NULL, NULL);
				continue;
			}
			index++;
			tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN1, NULL, NULL);
		} else if (index == 2) {
			cross_pos->disp_xpos = 700+15;
			cross_pos->disp_ypos = 50+15;
			ret = tp_adjust(index, (void *)cross_pos);
			printf("ADJUT%d:%d\n", index, ret);
			if (ret != EPDK_OK) {
				if (ret == -2) {
					tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_START, NULL, NULL);
					index = 1;
				}
				tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_FAIL, NULL, NULL);
				continue;
			}
			index++;
			tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN2, NULL, NULL);
		} else if (index == 3) {
			cross_pos->disp_xpos = 700+15;
			cross_pos->disp_ypos = 500+15;
			ret = tp_adjust(index, (void *)cross_pos);
			printf("ADJUT%d:%d\n", index, ret);
			if (ret != EPDK_OK) {
				if (ret == -2) {
					tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_START, NULL, NULL);
					index = 1;
				}
				tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_FAIL, NULL, NULL);
				continue;
			}
			index++;
			tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN3, NULL, NULL);
		} else if (index == 4) {
			cross_pos->disp_xpos = 50+15;
			cross_pos->disp_ypos = 500+15;
			ret = tp_adjust(index, (void *)cross_pos);
			printf("ADJUT%d:%d\n", index, ret);
			if (ret != EPDK_OK) {
				if (ret == -2) {
					tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_START, NULL, NULL);
					index = 1;
				}
				tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_FAIL, NULL, NULL);
				continue;
			}
			index++;
			tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN4, NULL, NULL);
		} else if (index == 5) {
			cross_pos->disp_xpos = 375+15;
			cross_pos->disp_ypos = 275+15;
			ret = tp_adjust(index, (void *)cross_pos);
			printf("ADJUT%d:%d\n", index, ret);
			if (ret != EPDK_OK) {
				if (ret == -2) {
					tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_START, NULL, NULL);
					index = 1;
				}
				tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_FAIL, NULL, NULL);
				continue;
			}
			index++;
			tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN5, NULL, NULL);

			{//
				ES_FILE* hFile;

				//flush user disk data to NOR flash
				hFile = eLIBs_fopen("b:\\STORAGE\\SPINOR", "rb");
				if (hFile == NULL)
				{
					printf("open NOR file failed\n");
				}
				eLIBs_fioctrl(hFile, DEV_IOC_USR_FLUSH_CACHE, 0, 0);

				eLIBs_fclose(hFile);
			}

			break;
		}
	}

	esKRNL_TDel(EXEC_prioself);

	return;
}
#endif

static int32_t adjust_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t * obj;

	switch (cmd)
	{
	case TUI_USER_MSG_APP_ADJUT_START:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_232);
		tui_obj_set_x(obj, 50);
		tui_obj_set_y(obj, 50);
		tui_obj_set_hidden(obj, 0);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_233);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_234);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_235);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_236);
		tui_obj_set_hidden(obj, 1);
		break;
	case TUI_USER_MSG_APP_ADJUT_BTN1:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_232);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_233);
		tui_obj_set_x(obj, 700);
		tui_obj_set_y(obj, 50);
		tui_obj_set_hidden(obj, 0);
		break;
	case TUI_USER_MSG_APP_ADJUT_BTN2:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_233);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_234);
		tui_obj_set_x(obj, 700);
		tui_obj_set_y(obj, 500);
		tui_obj_set_hidden(obj, 0);
		break;
	case TUI_USER_MSG_APP_ADJUT_BTN3:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_234);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_235);
		tui_obj_set_x(obj, 50);
		tui_obj_set_y(obj, 500);
		tui_obj_set_hidden(obj, 0);
		break;
	case TUI_USER_MSG_APP_ADJUT_BTN4:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_235);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_236);
		tui_obj_set_x(obj, 375);
		tui_obj_set_y(obj, 275);
		tui_obj_set_hidden(obj, 0);
		break;
	case TUI_USER_MSG_APP_ADJUT_BTN5:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_BUTTON_236);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_LABEL_237);
		tui_obj_set_hidden(obj, 1);
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_LABEL_239);
		tui_obj_set_hidden(obj, 0);
		adjust_exit();
		tui_sys_msg_send_dly(TUI_USER_MSG_APP_ADJUT_OK, 1000, NULL, NULL);
		break;
	case TUI_USER_MSG_APP_ADJUT_FAIL:
		obj = tui_get_obj_from_id(this_app_obj, ADJUST_ADJUST_VIEW_LABEL_240);
		tui_obj_anim_fade_out(obj, 1500, NULL);
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * adjust_enter(void)
{
	tui_sys_msg_reg(adjust_sys_msg_cb);
	
	this_app_obj = adjust_adjust_view_view_create();
#ifdef AW_MELIS
	esKRNL_TCreate(adjust_thread_entry, NULL, 0x800, KRNL_priolevel4);
#endif
	return this_app_obj;
}

static void adjust_exit(void)
{
	tui_sys_msg_unreg(adjust_sys_msg_cb);
#ifdef AW_MELIS
	tpdrv_close();
#endif
}

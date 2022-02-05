#include "tui.h"

static tui_obj_t * this_app_obj;
static int g_val = 0;

static void button_app1_exit(void);
extern tui_obj_t * button_app1_button_view_view_create(void);

static int32_t button_app1_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t * obj;
	tui_obj_t * txt_obj;
	char txt_str[8];
	printf("button_app1 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		button_app1_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP1_BTN1:
		break;
	case TUI_USER_MSG_APP1_BTN2:
		break;
	case TUI_USER_MSG_APP1_BTN3:
		break;
	case TUI_USER_MSG_APP1_SWITCH:
		obj = tui_get_obj_from_id(this_app_obj, BUTTON_APP1_BUTTON_VIEW_BUTTON_34);
		tui_obj_set_hidden(obj, (int)param0);
		obj = tui_get_obj_from_id(this_app_obj, BUTTON_APP1_BUTTON_VIEW_BUTTON_35);
		tui_obj_set_hidden(obj, (int)param0);
		obj = tui_get_obj_from_id(this_app_obj, BUTTON_APP1_BUTTON_VIEW_BUTTON_36);
		tui_obj_set_hidden(obj, (int)param0);
		obj = tui_search_obj_from_id(GLOBAL_BAR_STATUS_BAR);
		if (param0 == 0)
			tui_obj_anim_fade_in(obj, 300, NULL);
		else
			tui_obj_anim_fade_out(obj, 300, NULL);
		break;
	case TUI_USER_MSG_APP1_BTN_IMG1:
		txt_obj = tui_get_obj_from_id(this_app_obj, BUTTON_APP1_BUTTON_VIEW_LABEL_40);
		g_val++;

		sprintf(txt_str, "%d", g_val);
		tui_label_set_txt(txt_obj, txt_str);
		break;
	case TUI_USER_MSG_APP1_BTN_IMG2:
		txt_obj = tui_get_obj_from_id(this_app_obj, BUTTON_APP1_BUTTON_VIEW_LABEL_40);
		g_val--;

		sprintf(txt_str, "%d", g_val);
		tui_label_set_txt(txt_obj, txt_str);
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * button_app1_enter(void)
{
	g_val = 0;

	tui_sys_msg_reg(button_app1_sys_msg_cb);

	this_app_obj = button_app1_button_view_view_create();

	return this_app_obj;
}

static void button_app1_exit(void)
{
	tui_sys_msg_unreg(button_app1_sys_msg_cb);
}

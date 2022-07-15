#include "tui.h"

static tui_obj_t * this_app_obj;

static void bar_app3_exit(void);
extern tui_obj_t * bar_app3_bar_view_view_create(void);

static int32_t bar_app3_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t * txt_obj;
	char txt_str[8];
	printf("bar_app3 system message:0x%x\n", cmd);
	switch (cmd)
	{
		case TUI_USER_MSG_APP_BACK:
		case TUI_USER_MSG_APP_HOME:
			tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
			break;
		case TUI_USER_MSG_APP3_BAR1:
			txt_obj = tui_get_obj_from_id(this_app_obj, BAR_APP3_BAR_VIEW_LABEL_47);

			sprintf(txt_str, "%d", (int)param0);
			tui_label_set_txt(txt_obj, txt_str);
			break;
		case TUI_USER_MSG_APP3_BAR2:
			txt_obj = tui_get_obj_from_id(this_app_obj, BAR_APP3_BAR_VIEW_LABEL_48);

			sprintf(txt_str, "%d", (int)param0);
			tui_label_set_txt(txt_obj, txt_str);
			break;
		default:
			break;
	}
	return 0;
}

tui_obj_t * bar_app3_enter(void)
{

	tui_sys_msg_reg(bar_app3_sys_msg_cb);

	this_app_obj = bar_app3_bar_view_view_create();
	tui_obj_set_del_cb(this_app_obj, bar_app3_exit);

	return this_app_obj;
}

static void bar_app3_exit(void)
{
	tui_sys_msg_unreg(bar_app3_sys_msg_cb);
}

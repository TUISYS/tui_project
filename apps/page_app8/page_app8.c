#include "tui.h"

static tui_obj_t * this_app_obj;

static void page_app8_exit(void);
tui_obj_t * page_app8_page_view_view_create(void);

static int32_t page_app8_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	printf("page_app8 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * page_app8_enter(void)
{
	tui_sys_msg_reg(page_app8_sys_msg_cb);

	this_app_obj = page_app8_page_view_view_create();
	tui_obj_set_del_cb(this_app_obj, page_app8_exit);

	//tui_obj_set_click(tui_get_obj_from_id(this_app_obj, PAGE_APP8_PAGE_VIEW_IMAGE_156), 1);
	//tui_obj_set_click(tui_get_obj_from_id(this_app_obj, PAGE_APP8_PAGE_VIEW_IMAGE_152), 1);
	//tui_obj_set_click(tui_get_obj_from_id(this_app_obj, PAGE_APP8_PAGE_VIEW_IMAGE_153), 1);
	//tui_obj_set_click(tui_get_obj_from_id(this_app_obj, PAGE_APP8_PAGE_VIEW_IMAGE_154), 1);
	//tui_obj_set_click(tui_get_obj_from_id(this_app_obj, PAGE_APP8_PAGE_VIEW_IMAGE_155), 1);
	
	return this_app_obj;
}

static void page_app8_exit(void)
{
	tui_sys_msg_unreg(page_app8_sys_msg_cb);
}

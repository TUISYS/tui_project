#include "tui.h"

static tui_obj_t * this_app_obj; 
static tui_point_t point_0;
static tui_point_t point_1;
static int line_w;

static void line_app2_exit(void);
extern tui_obj_t * line_app2_line_view_view_create(void);

static int32_t line_app2_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t *line;
	//printf("line_app2 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		line_app2_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP2_BTN1:
		point_0.x = (tui_coord_t)param0 + 23;
		point_0.y = (tui_coord_t)param1 + 23;

		line = tui_get_obj_from_id(this_app_obj, LINE_APP2_LINE_VIEW_LINE_50);
		if (line)
			tui_line_set_points(line, point_0, point_1);

		break;
	case TUI_USER_MSG_APP2_BTN2:
		point_1.x = (tui_coord_t)param0 + 23;
		point_1.y = (tui_coord_t)param1 + 23;

		line = tui_get_obj_from_id(this_app_obj, LINE_APP2_LINE_VIEW_LINE_50);
		if (line)
			tui_line_set_points(line, point_0, point_1);
		break;

	case TUI_USER_MSG_APP2_BTN_UP:
		line_w++;
		line = tui_get_obj_from_id(this_app_obj, LINE_APP2_LINE_VIEW_LINE_50);
		if (line)
			tui_line_set_line_width(line, line_w);
		break;
	case TUI_USER_MSG_APP2_BTN_DOWN:
		line_w--;
		if (line_w < 1)
			line_w = 1;
		line = tui_get_obj_from_id(this_app_obj, LINE_APP2_LINE_VIEW_LINE_50);
		if (line)
			tui_line_set_line_width(line, line_w);
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * line_app2_enter(void)
{
	tui_obj_t *btn1_obj, *btn2_obj;
	line_w = 5;

	tui_sys_msg_reg(line_app2_sys_msg_cb);

	this_app_obj = line_app2_line_view_view_create();

	btn1_obj = tui_get_obj_from_id(this_app_obj, LINE_APP2_LINE_VIEW_CONTAINER_51);
	tui_obj_set_ext_click_area(btn1_obj, 20, 20, 20, 20);
	tui_obj_set_border_radius(btn1_obj, 0x7fff);
	tui_obj_set_drag_dir(btn1_obj, TUI_DRAG_DIR_BOTH);
	btn2_obj = tui_get_obj_from_id(this_app_obj, LINE_APP2_LINE_VIEW_CONTAINER_52);
	tui_obj_set_ext_click_area(btn2_obj, 20, 20, 20, 20);
	tui_obj_set_border_radius(btn2_obj, 0x7fff);
	tui_obj_set_drag_dir(btn2_obj, TUI_DRAG_DIR_BOTH);

	return this_app_obj;
}

static void line_app2_exit(void)
{	
	tui_sys_msg_unreg(line_app2_sys_msg_cb);
}

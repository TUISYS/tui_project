#include "tui.h"

static tui_obj_t * this_app_obj;
static tui_obj_t * this_draw_obj;
static tui_point_t points_new;

static void draw_app9_exit(void);
tui_obj_t * draw_app9_draw_view_view_create(void);

static int32_t draw_app9_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_point_t points[2];

	printf("draw_app9 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP9_CLICK:
		points[0].x = points_new.x;
		points[0].y = points_new.y;
		points[1].x = (tui_coord_t)param0;
		points[1].y = (tui_coord_t)param1;
		
		tui_canvas_draw_line(this_draw_obj, points, 2, 2, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0, 0xff));

		points_new.x = (tui_coord_t)param0;
		points_new.y = (tui_coord_t)param1;
		break;
	case TUI_USER_MSG_APP9_CLICK_PRESSED:
		points_new.x = (tui_coord_t)param0;
		points_new.y = (tui_coord_t)param1;
		break;
	case TUI_USER_MSG_APP9_CLICK_RELEASED:
		points_new.x = (tui_coord_t)param0;
		points_new.y = (tui_coord_t)param1;
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * draw_app9_enter(void)
{
	tui_point_t points[3] = { { 10, 10 }, { 50, 15 }, { 80, 10 } };
	tui_point_t points_t[3] = { { 10, 80 }, { 70, 180 }, { 80, 80 } };
	tui_point_t points_r[5] = { { 0, 0 }, { 299, 0 }, { 299, 299 }, { 0, 299 }, { 0, 0 } };

	tui_sys_msg_reg(draw_app9_sys_msg_cb);

	this_app_obj = draw_app9_draw_view_view_create();
	tui_obj_set_del_cb(this_app_obj, draw_app9_exit);

	this_draw_obj = tui_get_obj_from_id(this_app_obj, DRAW_APP9_DRAW_VIEW_CANVAS_190);
	tui_obj_set_click(this_draw_obj, 1);

	/* »æÖÆº¯Êý */
	tui_canvas_fill_bg(this_draw_obj, TUI_ARGB_COLOR_MAKE(0x3f, 0xff, 0xff, 0));
	tui_canvas_draw_pixel(this_draw_obj, 15, 15, TUI_ARGB_COLOR_MAKE(0xff, 0, 0, 0));
	tui_canvas_draw_line(this_draw_obj, points, 3, 2, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0, 0));
	tui_canvas_draw_line(this_draw_obj, points_r, 5, 10, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0, 0));
	tui_canvas_draw_rect(this_draw_obj, 50, 150, 150, 150, TUI_ARGB_COLOR_MAKE(0xff, 0, 0xff, 0));
	tui_canvas_draw_polygon(this_draw_obj, points_t, 3, TUI_ARGB_COLOR_MAKE(0xff, 0, 0, 0xff));
	tui_canvas_draw_arc(this_draw_obj, 200, 100, 100, 0, 360, 2, TUI_ARGB_COLOR_MAKE(0xff, 0, 0xff, 0xff));
	tui_canvas_draw_text(this_draw_obj, 100, 200, "hello2345", 60, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0xff, 0));
	tui_canvas_draw_img(this_draw_obj, 20, 20, "V:/image/10.bin");

	return this_app_obj;
}

static void draw_app9_exit(void)
{
	tui_sys_msg_unreg(draw_app9_sys_msg_cb);
}

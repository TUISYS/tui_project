#include "tui.h"

static tui_obj_t * this_app_obj;
static tui_obj_t * this_wind1_obj;
static tui_obj_t * this_wind2_obj;
static tui_obj_t * this_wind3_obj;
static tui_obj_t * this_wind4_obj;
static tui_timer_t * this_timer;
static int wind3_cnt;

static void window_app6_exit(void);
extern tui_obj_t * window_app6_window_view_view_create(void);
extern tui_obj_t * window_app6_window1_view_view_create(void);
extern tui_obj_t * window_app6_window2_view_view_create(void);
extern tui_obj_t * window_app6_window3_view_view_create(void);
extern tui_obj_t * window_app6_window4_view_view_create(void);

static void window_app6_wind3(tui_timer_t * t)
{
	tui_obj_t * txt_obj;
	char txt[5] = { 0 };


	if (wind3_cnt <= 0) {
		tui_obj_del(this_wind3_obj);
		this_wind3_obj = NULL;
		tui_timer_del(this_timer);
		this_timer = NULL;
		return;
	}

	wind3_cnt--;

	txt_obj = tui_get_obj_from_id(this_wind3_obj, WINDOW_APP6_WINDOW3_VIEW_LABEL_101);
	sprintf(txt, "%ds", wind3_cnt);
	tui_label_set_txt(txt_obj, txt);
}

static void window_app6_indev_point_trigger_cb(uint8_t state, int32_t x, int32_t y)
{
	if (this_wind4_obj && state == 1) {
		tui_area_t cords;

		tui_obj_get_coords(this_wind4_obj, &cords);

		if (!(x > cords.x1 && x < cords.x2 && y > cords.y1 && y < cords.y2)) {
			tui_obj_del(this_wind4_obj);
			this_wind4_obj = NULL;
		}
	}
}

static int32_t window_app6_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	printf("window_app6 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		window_app6_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP6_WIND1:
		if (this_wind1_obj == NULL) {
			this_wind1_obj = window_app6_window1_view_view_create();
			tui_obj_set_parent(this_wind1_obj, tui_layer_top());
			tui_obj_set_click(tui_layer_top(), 1);
			tui_obj_set_alpha(this_app_obj, 128);
		}
		break;
	case TUI_USER_MSG_APP6_WIND1_YES:
		if (this_wind1_obj) {
			tui_obj_del(this_wind1_obj);
			this_wind1_obj = NULL;
			tui_obj_set_click(tui_layer_top(), 0);
			tui_obj_set_alpha(this_app_obj, 255);
		}
		break;
	case TUI_USER_MSG_APP6_WIND1_NO:
		if (this_wind1_obj) {
			tui_obj_del(this_wind1_obj);
			this_wind1_obj = NULL;
			tui_obj_set_click(tui_layer_top(), 0);
			tui_obj_set_alpha(this_app_obj, 255);
		}
		break;
	case TUI_USER_MSG_APP6_WIND2:
		if (this_wind2_obj == NULL) {
			this_wind2_obj = window_app6_window2_view_view_create();
		}
		break;
	case TUI_USER_MSG_APP6_WIND2_YES:
		if (this_wind2_obj) {
			tui_obj_del(this_wind2_obj);
			this_wind2_obj = NULL;
		}
		break;
	case TUI_USER_MSG_APP6_WIND3:
		if (this_wind3_obj == NULL) {
			wind3_cnt = 5;
			this_wind3_obj = window_app6_window3_view_view_create();
			this_timer = tui_timer_create(window_app6_wind3, 1000, TUI_TIMER_PRIO_LOWEST, NULL);
		}
		break;
	case TUI_USER_MSG_APP6_WIND4:
		if (this_wind4_obj == NULL) {
			this_wind4_obj = window_app6_window4_view_view_create();
		}
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * window_app6_enter(void)
{
	tui_sys_msg_reg(window_app6_sys_msg_cb);

	this_app_obj = window_app6_window_view_view_create();

	indev_point_trigger_cb_reg(window_app6_indev_point_trigger_cb);

	return this_app_obj;
}

static void window_app6_exit(void)
{
	if (this_wind1_obj) {
		tui_obj_del(this_wind1_obj);
		this_wind1_obj = NULL;
		tui_obj_set_click(tui_layer_top(), 0);
	}
	if (this_wind2_obj) {
		tui_obj_del(this_wind2_obj);
		this_wind2_obj = NULL;
	}
	if (this_wind3_obj) {
		tui_obj_del(this_wind3_obj);
		this_wind3_obj = NULL;
	}
	if (this_wind4_obj) {
		tui_obj_del(this_wind4_obj);
		this_wind4_obj = NULL;
	}
	if (this_timer) {
		tui_timer_del(this_timer);
		this_timer = NULL;
	}

	indev_point_trigger_cb_unreg();

	tui_sys_msg_unreg(window_app6_sys_msg_cb);
}
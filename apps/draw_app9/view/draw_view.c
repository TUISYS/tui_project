#include "tui.h"



tui_obj_t *draw_app9_draw_view_view_obj; 

static void canvas_190_cb_190(tui_obj_t *obj, tui_event_e event) {
	 /* obj 画布对象 */
	 /* event 画布的事件值 */
	int32_t x, y;
	uint8_t st;

	indev_get_point_value(&st, &x, &y);

	if (event == TUI_EVENT_PRESSED)
		tui_sys_msg_send(TUI_USER_MSG_APP9_CLICK_PRESSED, (void*)x, (void*)y);
	else if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP9_CLICK_RELEASED, (void*)x, (void*)y);
	else if (event == TUI_EVENT_PRESSING)
		tui_sys_msg_send(TUI_USER_MSG_APP9_CLICK, (void*)x, (void*)y);
}



static tui_map_cb_t cb_map[] = {
	{ DRAW_APP9_DRAW_VIEW_CANVAS_190, (void*)canvas_190_cb_190 },
	{ 0, (void*)0 }
};



tui_obj_t * draw_app9_draw_view_view_create(void){
	draw_app9_draw_view_view_obj = 0;
	draw_app9_draw_view_view_obj = tui_view_create("V:/layout/draw_app9/draw_view.bin", cb_map);
	return draw_app9_draw_view_view_obj;
}

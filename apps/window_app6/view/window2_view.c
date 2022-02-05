#include "tui.h"



tui_obj_t *window_app6_window2_view_view_obj; 

static void button_95_cb_95(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND2_YES, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ WINDOW_APP6_WINDOW2_VIEW_BUTTON_95, (void*)button_95_cb_95 },
	{ 0, (void*)0 }
};

tui_obj_t * window_app6_window2_view_view_create(void){
	window_app6_window2_view_view_obj = 0;
	window_app6_window2_view_view_obj = tui_view_create("V:/layout/window_app6/window2_view.bin", cb_map);
	return window_app6_window2_view_view_obj;
}

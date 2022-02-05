#include "tui.h"


tui_obj_t *window_app6_window1_view_view_obj;

static void button_87_cb_87(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND1_YES, NULL, NULL);
}


static void button_88_cb_88(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND1_NO, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ WINDOW_APP6_WINDOW1_VIEW_BUTTON_87, (void*)button_87_cb_87 },
	{ WINDOW_APP6_WINDOW1_VIEW_BUTTON_88, (void*)button_88_cb_88 },
	{ 0, (void*)0 }
};

tui_obj_t * window_app6_window1_view_view_create(void){
	window_app6_window1_view_view_obj = 0;
	window_app6_window1_view_view_obj = tui_view_create("V:/layout/window_app6/window1_view.bin", cb_map);
	return window_app6_window1_view_view_obj;
}

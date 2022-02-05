#include "tui.h"


tui_obj_t *window_app6_window_view_view_obj; 

static void button_77_cb_77(tui_obj_t *obj, tui_event_e event) {
	/* obj 按键对象 */
	/* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND1, NULL, NULL);
}


static void button_78_cb_78(tui_obj_t *obj, tui_event_e event) {
	/* obj 按键对象 */
	/* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND2, NULL, NULL);
}


static void button_79_cb_79(tui_obj_t *obj, tui_event_e event) {
	/* obj 按键对象 */
	/* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND3, NULL, NULL);
}



static void label_104_cb_104(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}



static void button_103_cb_103(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6_WIND4, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ WINDOW_APP6_WINDOW_VIEW_BUTTON_77, (void*)button_77_cb_77 },
	{ WINDOW_APP6_WINDOW_VIEW_BUTTON_78, (void*)button_78_cb_78 },
	{ WINDOW_APP6_WINDOW_VIEW_BUTTON_79, (void*)button_79_cb_79 },
	{ WINDOW_APP6_WINDOW_VIEW_BUTTON_103, (void*)button_103_cb_103 },
	{ WINDOW_APP6_WINDOW_VIEW_LABEL_104, (void*)label_104_cb_104 },
	{ 0, (void*)0 }
};

tui_obj_t * window_app6_window_view_view_create(void){
	window_app6_window_view_view_obj = 0;
	window_app6_window_view_view_obj = tui_view_create("V:/layout/window_app6/window_view.bin", cb_map);
	return window_app6_window_view_view_obj;
}

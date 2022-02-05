#include "tui.h"



tui_obj_t *adjust_adjust_view_view_obj; 

static void button_232_cb_232(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN1, NULL, NULL);
}
static void button_233_cb_233(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN2, NULL, NULL);
}
static void button_234_cb_234(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN3, NULL, NULL);
}
static void button_235_cb_235(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN4, NULL, NULL);
}
static void button_236_cb_236(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_BTN5, NULL, NULL);
}

static tui_map_cb_t cb_map[] = {
	{ ADJUST_ADJUST_VIEW_BUTTON_232, (void*)button_232_cb_232 },
	{ ADJUST_ADJUST_VIEW_BUTTON_233, (void*)button_233_cb_233 },
	{ ADJUST_ADJUST_VIEW_BUTTON_234, (void*)button_234_cb_234 },
	{ ADJUST_ADJUST_VIEW_BUTTON_235, (void*)button_235_cb_235 },
	{ ADJUST_ADJUST_VIEW_BUTTON_236, (void*)button_236_cb_236 },
	{ 0, (void*)0 }
};

tui_obj_t * adjust_adjust_view_view_create(void){
	adjust_adjust_view_view_obj = 0;
	adjust_adjust_view_view_obj = tui_view_create("V:/layout/adjust/adjust_view.bin", cb_map);
	return adjust_adjust_view_view_obj;
}

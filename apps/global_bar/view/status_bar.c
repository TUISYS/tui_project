#include "tui.h"


tui_obj_t *global_bar_status_bar_view_obj;

static void dropdown_263_cb_263(tui_obj_t *obj, tui_event_e event, int16_t index) {
	 /* obj 下拉菜单对象 */
	 /* event 下拉菜单的事件值*/
	 /* index 下拉菜单的当前索引 */
}


static void image_258_cb_258(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片对象 */
	 /* event 图片变化的事件状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_DEBUG, NULL, NULL);
}


static void image_btn_259_cb_259(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_DEBUG_RUN, NULL, NULL);
}
 

static void home_btn_23_cb_23(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_HOME, NULL, NULL);
}


static void back_btn_24_cb_24(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_BACK, NULL, NULL);
}





static void image_btn_102_cb_102(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_POWER_DOWN, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ GLOBAL_BAR_STATUS_BAR_HOME_BTN_23, (void*)home_btn_23_cb_23 },
	{ GLOBAL_BAR_STATUS_BAR_BACK_BTN_24, (void*)back_btn_24_cb_24 },
	{ GLOBAL_BAR_STATUS_BAR_IMAGE_BTN_102, (void*)image_btn_102_cb_102 },
	{ GLOBAL_BAR_STATUS_BAR_IMAGE_258, (void*)image_258_cb_258 },
	{ GLOBAL_BAR_STATUS_BAR_IMAGE_BTN_259, (void*)image_btn_259_cb_259 },
	{ GLOBAL_BAR_STATUS_BAR_DROPDOWN_263, (void*)dropdown_263_cb_263 },
	{ 0, (void*)0 }
};

tui_obj_t * global_bar_status_bar_view_create(void){
	global_bar_status_bar_view_obj = 0;
	global_bar_status_bar_view_obj = tui_view_create("V:/layout/global_bar/status_bar.bin", cb_map);
	return global_bar_status_bar_view_obj;
}

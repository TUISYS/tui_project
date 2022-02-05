#include "tui.h"



tui_obj_t *line_app2_line_view_view_obj; 

static void container_52_cb_52(tui_obj_t *obj, tui_event_e event) {
	 /* obj 容器对象 */
	 /* event 容器的事件 */
	tui_sys_msg_send(TUI_USER_MSG_APP2_BTN2, (void*)tui_obj_get_x(obj), (void*)tui_obj_get_y(obj));
}


static void container_51_cb_51(tui_obj_t *obj, tui_event_e event) {
	 /* obj 容器对象 */
	 /* event 容器的事件 */
	tui_sys_msg_send(TUI_USER_MSG_APP2_BTN1, (void*)tui_obj_get_x(obj), (void*)tui_obj_get_y(obj));
}





static void image_btn_53_cb_53(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED || TUI_EVENT_LONG_PRESSED_REPEAT == event)
		tui_sys_msg_send(TUI_USER_MSG_APP2_BTN_UP, NULL, NULL);
}


static void image_btn_54_cb_54(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED || TUI_EVENT_LONG_PRESSED_REPEAT == event)
		tui_sys_msg_send(TUI_USER_MSG_APP2_BTN_DOWN, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ LINE_APP2_LINE_VIEW_CONTAINER_52, (void*)container_52_cb_52 },
	{ LINE_APP2_LINE_VIEW_CONTAINER_51, (void*)container_51_cb_51 },
	{ LINE_APP2_LINE_VIEW_IMAGE_BTN_53, (void*)image_btn_53_cb_53 },
	{ LINE_APP2_LINE_VIEW_IMAGE_BTN_54, (void*)image_btn_54_cb_54 },
	{ 0, (void*)0 }
};

tui_obj_t * line_app2_line_view_view_create(void){
	line_app2_line_view_view_obj = 0;
	line_app2_line_view_view_obj = tui_view_create("V:/layout/line_app2/line_view.bin", cb_map);
	return line_app2_line_view_view_obj;
}

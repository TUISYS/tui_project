#include "tui.h"




tui_obj_t *home_main_view_view_obj;

static void label_227_cb_227(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_222_cb_222(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_221_cb_221(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_220_cb_220(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_219_cb_219(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_218_cb_218(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_217_cb_217(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void label_216_cb_216(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}


static void multi_screen_3_cb_3(tui_obj_t *obj, tui_event_e event, int16_t index) {
	 /* obj 多屏控件的对象 */
	 /* event 多屏控件的事件值 */
	 /* index 多屏控件当前屏幕索引 */
	tui_obj_t *obj_index;

	if (TUI_EVENT_OBJECT_INIT != event) {
		obj_index = tui_get_obj_from_id(home_main_view_view_obj, HOME_MAIN_VIEW_MC_INDEX_20);
		if (obj_index)
			tui_image_set_cur_img_index(obj_index, index);
	}
}


static void app_1_cb_6(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP0, NULL, NULL);
}


static void app_2_cb_7(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP1, NULL, NULL);
}


static void app_3_cb_8(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP2, NULL, NULL);
}


static void app_4_cb_9(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP3, NULL, NULL);
}


static void app_5_cb_10(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP4, NULL, NULL);
}


static void app_6_cb_11(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5, NULL, NULL);
}


static void app_7_cb_12(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP6, NULL, NULL);
}


static void app_8_cb_13(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP7, NULL, NULL);
}


static void app_9_cb_14(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP8, NULL, NULL);
}


static void app_10_cb_15(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP9, NULL, NULL);
}


static void app_11_cb_16(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP10, NULL, NULL);
}


static void app_12_cb_17(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片按键对象 */
	 /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
	 /* img_index 当前图片的索引值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP11, NULL, NULL);
}


static void mc_index_20_cb_20(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片对象 */
	 /* event 图片变化的事件状态值 */
	 /* img_index 当前图片的索引值 */
}
static tui_map_cb_t cb_map[] = {
	{ HOME_MAIN_VIEW_MULTI_SCREEN_3, (void*)multi_screen_3_cb_3 },
	{ HOME_MAIN_VIEW_APP_1, (void*)app_1_cb_6 },
	{ HOME_MAIN_VIEW_APP_2, (void*)app_2_cb_7 },
	{ HOME_MAIN_VIEW_APP_3, (void*)app_3_cb_8 },
	{ HOME_MAIN_VIEW_APP_4, (void*)app_4_cb_9 },
	{ HOME_MAIN_VIEW_APP_5, (void*)app_5_cb_10 },
	{ HOME_MAIN_VIEW_APP_6, (void*)app_6_cb_11 },
	{ HOME_MAIN_VIEW_APP_7, (void*)app_7_cb_12 },
	{ HOME_MAIN_VIEW_APP_8, (void*)app_8_cb_13 },
	{ HOME_MAIN_VIEW_APP_9, (void*)app_9_cb_14 },
	{ HOME_MAIN_VIEW_APP_10, (void*)app_10_cb_15 },
	{ HOME_MAIN_VIEW_APP_11, (void*)app_11_cb_16 },
	{ HOME_MAIN_VIEW_APP_12, (void*)app_12_cb_17 },
	{ HOME_MAIN_VIEW_MC_INDEX_20, (void*)mc_index_20_cb_20 },
	{ HOME_MAIN_VIEW_LABEL_216, (void*)label_216_cb_216 },
	{ HOME_MAIN_VIEW_LABEL_217, (void*)label_217_cb_217 },
	{ HOME_MAIN_VIEW_LABEL_218, (void*)label_218_cb_218 },
	{ HOME_MAIN_VIEW_LABEL_219, (void*)label_219_cb_219 },
	{ HOME_MAIN_VIEW_LABEL_220, (void*)label_220_cb_220 },
	{ HOME_MAIN_VIEW_LABEL_221, (void*)label_221_cb_221 },
	{ HOME_MAIN_VIEW_LABEL_222, (void*)label_222_cb_222 },
	{ HOME_MAIN_VIEW_LABEL_227, (void*)label_227_cb_227 },
	{ 0, (void*)0 }
};

tui_obj_t * home_main_view_view_create(void){
	home_main_view_view_obj = 0;
	home_main_view_view_obj = tui_view_create("V:/layout/home/main_view.bin", cb_map);
	return home_main_view_view_obj;
}

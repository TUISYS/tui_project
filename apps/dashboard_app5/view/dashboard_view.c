#include "tui.h"



tui_obj_t *dashboard_app5_dashboard_view_view_obj; 

static void button0_61_cb_61(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(180+60), NULL);
}


static void button90_62_cb_62(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(180 + 60 + 90), NULL);
}


static void button60_63_cb_63(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(180 + 60 + 60), NULL);
}


static void button35_64_cb_64(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(180 + 60+35), NULL);
}


static void button120_65_cb_65(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(180 + 60 + 120), NULL);
}


static void button210_66_cb_66(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(210 - 120), NULL);
}


static void button180_67_cb_67(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(180 - 120), NULL);
}


static void button150_68_cb_68(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(150 - 120), NULL);
}


static void button240_69_cb_69(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP5_ANGLE, (void*)(240 - 120), NULL);
}
static tui_map_cb_t cb_map[] = {
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON0_61, (void*)button0_61_cb_61 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON90_62, (void*)button90_62_cb_62 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON60_63, (void*)button60_63_cb_63 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON35_64, (void*)button35_64_cb_64 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON120_65, (void*)button120_65_cb_65 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON210_66, (void*)button210_66_cb_66 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON180_67, (void*)button180_67_cb_67 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON150_68, (void*)button150_68_cb_68 },
	{ DASHBOARD_APP5_DASHBOARD_VIEW_BUTTON240_69, (void*)button240_69_cb_69 },
	{ 0, (void*)0 }
};

tui_obj_t * dashboard_app5_dashboard_view_view_create(void){
	dashboard_app5_dashboard_view_view_obj = 0;
	dashboard_app5_dashboard_view_view_obj = tui_view_create("V:/layout/dashboard_app5/dashboard_view.bin", cb_map);
	return dashboard_app5_dashboard_view_view_obj;
}

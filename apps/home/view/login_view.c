#include "tui.h"

tui_obj_t *home_login_view_view_obj;

static void button_253_cb_253(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP_LOGIN_CHECK, NULL, NULL);
}
 


static tui_map_cb_t cb_map[] = {
	{ HOME_LOGIN_VIEW_BUTTON_253, (void*)button_253_cb_253 },
	{ 0, (void*)0 }
};

tui_obj_t * home_login_view_view_create(void){
	home_login_view_view_obj = 0;
	home_login_view_view_obj = tui_view_create("V:/layout/home/login_view.bin", cb_map);
	return home_login_view_view_obj;
}

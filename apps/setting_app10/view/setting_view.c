#include "tui.h"



tui_obj_t *setting_app10_setting_view_view_obj;

static void list_245_cb_245(tui_obj_t *obj_list, tui_event_e event, int32_t index) {
	 /* obj_list 列表对象 */
	 /* event 列表的事件值 */
	 /* index 列表的当前index */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP10_FS, (void*)index, NULL);
}


static void button_246_cb_246(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP10_FS_BACK, NULL, NULL);
}
 



static void dropdown_206_cb_206(tui_obj_t *obj, tui_event_e event, int16_t index) {
	 /* obj 下拉菜单对象 */
	 /* event 下拉菜单的事件值*/
	 /* index 下拉菜单的当前索引 */
	tui_set_language(index);
	tui_sys_msg_send(TUI_USER_MSG_APP10_LANG, NULL, NULL);
}



static void list_183_cb_183(tui_obj_t *obj_list, tui_event_e event, int32_t index) {
	 /* obj_list 列表对象 */
	 /* event 列表的事件值 */
	 /* index 列表的当前index */
}


static tui_map_cb_t cb_map[] = {
	{ SETTING_APP10_SETTING_VIEW_LIST_183, (void*)list_183_cb_183 },
	{ SETTING_APP10_SETTING_VIEW_DROPDOWN_206, (void*)dropdown_206_cb_206 },
	{ SETTING_APP10_SETTING_VIEW_LIST_245, (void*)list_245_cb_245 },
	{ SETTING_APP10_SETTING_VIEW_BUTTON_246, (void*)button_246_cb_246 },
	{ 0, (void*)0 }
};

tui_obj_t * setting_app10_setting_view_view_create(void){
	setting_app10_setting_view_view_obj = 0;
	setting_app10_setting_view_view_obj = tui_view_create("V:/layout/setting_app10/setting_view.bin", cb_map);
	return setting_app10_setting_view_view_obj;
}

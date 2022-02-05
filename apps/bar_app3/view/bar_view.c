#include "tui.h"



tui_obj_t *bar_app3_bar_view_view_obj; 

static void bar_slider_45_cb_45(tui_obj_t *obj, tui_event_e event, int16_t value) {
	 /* obj 滑条对象 */
	 /* event 滑条的事件 */
	 /* value 滑条的值，范围是0~100 */
	tui_sys_msg_send(TUI_USER_MSG_APP3_BAR1, (void*)value, NULL);
}


static void bar_slider_46_cb_46(tui_obj_t *obj, tui_event_e event, int16_t value) {
	 /* obj 滑条对象 */
	 /* event 滑条的事件 */
	 /* value 滑条的值，范围是0~100 */
	tui_sys_msg_send(TUI_USER_MSG_APP3_BAR2, (void*)value, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ BAR_APP3_BAR_VIEW_BAR_SLIDER_45, (void*)bar_slider_45_cb_45 },
	{ BAR_APP3_BAR_VIEW_BAR_SLIDER_46, (void*)bar_slider_46_cb_46 },
	{ 0, (void*)0 }
};

tui_obj_t * bar_app3_bar_view_view_create(void){
	bar_app3_bar_view_view_obj = 0;
	bar_app3_bar_view_view_obj = tui_view_create("V:/layout/bar_app3/bar_view.bin", cb_map);
	return bar_app3_bar_view_view_obj;
}

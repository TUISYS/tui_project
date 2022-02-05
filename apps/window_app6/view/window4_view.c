#include "tui.h"



tui_obj_t *window_app6_window4_view_view_obj; 

static void label_h_106_cb_106(tui_obj_t *obj, tui_event_e event) {
	 /* obj 标签对象 */
	 /* event 标签的事件 */
}
static tui_map_cb_t cb_map[] = {
	{ WINDOW_APP6_WINDOW4_VIEW_LABEL_H_106, (void*)label_h_106_cb_106 },
	{ 0, (void*)0 }
};

tui_obj_t * window_app6_window4_view_view_create(void){
	window_app6_window4_view_view_obj = 0;
	window_app6_window4_view_view_obj = tui_view_create("V:/layout/window_app6/window4_view.bin", cb_map);
	return window_app6_window4_view_view_obj;
}

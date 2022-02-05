#include "tui.h"



tui_obj_t *window_app6_window3_view_view_obj; 
static tui_map_cb_t cb_map[] = {
	{ 0, (void*)0 }
};

tui_obj_t * window_app6_window3_view_view_create(void){
	window_app6_window3_view_view_obj = 0;
	window_app6_window3_view_view_obj = tui_view_create("V:/layout/window_app6/window3_view.bin", cb_map);
	return window_app6_window3_view_view_obj;
}

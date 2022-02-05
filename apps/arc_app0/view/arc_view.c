#include "tui.h"


tui_obj_t *arc_app0_arc_view_view_obj; 
static tui_map_cb_t cb_map[] = {
	{ 0, (void*)0 }
};

tui_obj_t * arc_app0_arc_view_view_create(void){
	arc_app0_arc_view_view_obj = 0;
	arc_app0_arc_view_view_obj = tui_view_create("V:/layout/arc_app0/arc_view.bin", cb_map);
	return arc_app0_arc_view_view_obj;
}

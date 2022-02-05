#include "tui.h"



tui_obj_t *page_app8_page_view_view_obj; 
static tui_map_cb_t cb_map[] = {
	{ 0, (void*)0 }
};

tui_obj_t * page_app8_page_view_view_create(void){
	page_app8_page_view_view_obj = 0;
	page_app8_page_view_view_obj = tui_view_create("V:/layout/page_app8/page_view.bin", cb_map);
	return page_app8_page_view_view_obj;
}

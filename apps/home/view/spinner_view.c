#include "tui.h"

tui_obj_t *home_spinner_view_view_obj; 

static void bar_slider_261_cb_261(tui_obj_t *obj, tui_event_e event, int16_t value) {
	 /* obj 滑条对象 */
	 /* event 滑条的事件 */
	 /* value 滑条的值，范围是0~100 */
	tui_obj_t *led_obj;

	led_obj = tui_get_obj_from_id(home_spinner_view_view_obj, HOME_SPINNER_VIEW_LED_262);

	if (led_obj)
		tui_led_set_bright(led_obj, value/10);
}

static tui_map_cb_t cb_map[] = {
	{ HOME_SPINNER_VIEW_BAR_SLIDER_261, (void*)bar_slider_261_cb_261 },
	{ 0, (void*)0 }
};

tui_obj_t * home_spinner_view_view_create(void){
	home_spinner_view_view_obj = 0;
	home_spinner_view_view_obj = tui_view_create("V:/layout/home/spinner_view.bin", cb_map);
	return home_spinner_view_view_obj;
}

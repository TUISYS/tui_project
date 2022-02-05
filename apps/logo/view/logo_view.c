#include "tui.h"



tui_obj_t *logo_logo_view_view_obj; 



static void image_168_cb_168(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj 图片对象 */
	 /* event 图片变化的事件状态值 */
	 /* img_index 当前图片的索引值 */
	if (TUI_EVENT_IMAGE_ANIMATION_END == event)
		tui_sys_msg_send(TUI_USER_MSG_APP_LOGO, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ LOGO_LOGO_VIEW_IMAGE_168, (void*)image_168_cb_168 },
	{ 0, (void*)0 }
};

tui_obj_t * logo_logo_view_view_create(void){
	logo_logo_view_view_obj = 0;
	logo_logo_view_view_obj = tui_view_create("V:/layout/logo/logo_view.bin", cb_map);
	return logo_logo_view_view_obj;
}

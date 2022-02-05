#include "tui.h"


tui_obj_t *animation_app4_animation_view_view_obj;

static void gif_229_cb_229(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj GIF对象 */
	 /* event 动画的事件值 */
	 /* img_index 当前图片的索引值 */
}

static void animation_207_cb_207(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
    /* obj 动画的对象 */
    /* event 动画的事件 */
    /* img_index 动画当前图片的索引值 */
}

static void image_btn_57_cb_57(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
    /* obj 图片按键对象 */
    /* event 图片按键的事件，按下、抬起、以及变化的状态值 */
    /* img_index 当前图片的索引值 */
    if (event == TUI_EVENT_RELEASED)
    tui_sys_msg_send(TUI_USER_MSG_APP4_BTN, NULL, NULL);
}

static tui_map_cb_t cb_map[] = {
	{ ANIMATION_APP4_ANIMATION_VIEW_IMAGE_BTN_57, (void*)image_btn_57_cb_57 },
	{ ANIMATION_APP4_ANIMATION_VIEW_ANIMATION_207, (void*)animation_207_cb_207 },
	{ ANIMATION_APP4_ANIMATION_VIEW_GIF_229, (void*)gif_229_cb_229 },
	{ 0, (void*)0 }
};

tui_obj_t * animation_app4_animation_view_view_create(void){
	animation_app4_animation_view_view_obj = 0;
	animation_app4_animation_view_view_obj = tui_view_create("V:/layout/animation_app4/animation_view.bin", cb_map);
	return animation_app4_animation_view_view_obj;
}

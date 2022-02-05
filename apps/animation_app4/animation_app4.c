#include "tui.h"

static tui_obj_t * this_app_obj;

static void animation_app4_exit(void);
extern tui_obj_t * animation_app4_animation_view_view_create(void);

static int32_t animation_app4_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t *animation_obj;
	tui_obj_t *img_btn_obj;
	tui_animation_attri_t attri;
	//printf("animation_app4 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		animation_app4_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP4_BTN:
		img_btn_obj = tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_IMAGE_BTN_57);
		animation_obj = tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_ANIMATION_207);
		if (animation_obj) {
			tui_animation_get_attri(animation_obj, &attri);
			if (attri.timer) {
				tui_animation_stop_anim(animation_obj);
				tui_gif_pause(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_238));
				tui_gif_pause(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_229));
				tui_image_btn_set_cur_img_index(img_btn_obj, 1);
			}
			else {
				tui_animation_start_anim(animation_obj, attri.mode);
				tui_gif_restart(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_238));
				tui_gif_restart(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_229));
				tui_image_btn_set_cur_img_index(img_btn_obj, 0);
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * animation_app4_enter(void)
{
	tui_sys_msg_reg(animation_app4_sys_msg_cb);

	this_app_obj = animation_app4_animation_view_view_create();


	return this_app_obj;
}

static void animation_app4_exit(void)
{
	tui_sys_msg_unreg(animation_app4_sys_msg_cb);
}

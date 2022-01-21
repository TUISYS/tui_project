#include "tui.h"

static tui_obj_t * this_app_obj;

static void dashboard_app5_exit(void);
extern tui_obj_t * dashboard_app5_dashboard_view_view_create(void);
/*      .0
*
*
*.270		.90
*
*
*	.180
*/
static int32_t dashboard_app5_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t *img_obj;
	//printf("dashboard_app5 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		dashboard_app5_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP5_ANGLE:
		img_obj = tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_60);
		if (img_obj) {
			tui_image_set_angle(img_obj, (int16_t)param0, true);
		}
		//tui_image_set_rotation_center_coor(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 250, 191);
		//tui_image_anim_zoom(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 64, 256, TUI_ANIM_PATH_OVERSHOOT, NULL);
		//tui_image_anim_angle(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 360, 0, TUI_ANIM_PATH_OVERSHOOT, NULL);
		//tui_image_anim_width(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 1000, 500, TUI_ANIM_PATH_OVERSHOOT, NULL);
		tui_image_anim_height(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 766, 383, TUI_ANIM_PATH_OVERSHOOT, NULL);
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * dashboard_app5_enter(void)
{
	tui_sys_msg_reg(dashboard_app5_sys_msg_cb);

	this_app_obj = dashboard_app5_dashboard_view_view_create();


	return this_app_obj;
}

static void dashboard_app5_exit(void)
{
	tui_sys_msg_unreg(dashboard_app5_sys_msg_cb);
}
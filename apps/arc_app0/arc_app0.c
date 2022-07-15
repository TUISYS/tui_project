#include "tui.h"

static tui_obj_t * this_app_obj;
static tui_timer_t * this_timer;
static tui_timer_t * this_timer2;
static tui_timer_t * this_timer3;
static int g_num = 0;
static tui_obj_t *img_0u_1 = NULL, *img_0d_1 = NULL, *img_1u_1 = NULL, *img_1d_1 = NULL;
static tui_obj_t *img_0u_2 = NULL, *img_0d_2 = NULL, *img_1u_2 = NULL, *img_1d_2 = NULL;
static int g_way = -1;

static void arc_app0_exit(void);
extern tui_obj_t * arc_app0_arc_view_view_create(void);
/*      .0
*
*
*.270		.90
*
*
*	.180
*/
static void arc_loader(tui_timer_t * t)
{
	tui_obj_t * arc_obj;
	tui_arc_attri_t attri;

	arc_obj = tui_get_obj_from_id(this_app_obj, ARC_APP0_ARC_VIEW_ARC_28);

	tui_arc_get_attri(arc_obj, &attri);
	attri.start_angle = (attri.start_angle + 1) % 360;
	//attri.end_angle = (attri.end_angle + 1) % 360;

	tui_arc_set_angles(arc_obj, attri.start_angle, attri.end_angle);
}

static void arc_loader2(tui_timer_t * t)
{
	tui_obj_t * arc_obj;
	tui_obj_t * txt_obj;
	tui_arc_attri_t attri;
	char txt_str[5] = { 0 };

	arc_obj = tui_get_obj_from_id(this_app_obj, ARC_APP0_ARC_VIEW_ARC_31);
	txt_obj = tui_get_obj_from_id(this_app_obj, ARC_APP0_ARC_VIEW_LABEL_32);

	tui_arc_get_attri(arc_obj, &attri);
	if (attri.end_angle == 359)
		g_way *= -1;
	else if (attri.end_angle == 0)
		g_way *= -1;
	attri.end_angle = attri.end_angle + g_way;

	tui_arc_set_angles(arc_obj, attri.start_angle, attri.end_angle);
	sprintf(txt_str, "%d", attri.end_angle);
	tui_label_set_txt(txt_obj, txt_str);
}

static int32_t arc_app0_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	printf("arc_app0 system message:0x%x\n", cmd);
	switch (cmd)
	{
		case TUI_USER_MSG_APP_BACK:
		case TUI_USER_MSG_APP_HOME:
			tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
			break;
		default:
			break;
	}
	return 0;
}

static void arc_app0_anim1_cb(tui_obj_t * obj)
{
	tui_image_anim_height(img_1d_1, 800, 0, 79, TUI_ANIM_PATH_LINEAR, NULL);
}

static void arc_app0_show_num1(int num)
{
	tui_image_attri_t attri = { 0 };
	char path[32] = {0};

	if (num < 0 || num > 9)
		return;

	if (img_1u_1) {
		tui_obj_del(img_1u_1);
		img_1u_1 = NULL;
	}
	if (img_0u_1) {
		tui_obj_del(img_0u_1);
		img_0u_1 = NULL;
	}
	if (img_0d_1) {
		tui_obj_del(img_0d_1);
		img_0d_1 = NULL;
	}
	if (img_1d_1) {
		tui_obj_del(img_1d_1);
		img_1d_1 = NULL;
	}

	if (img_1u_1 == NULL)
		img_1u_1 = tui_image_create(this_app_obj);
	if (img_0u_1 == NULL)
		img_0u_1 = tui_image_create(this_app_obj);
	if (img_0d_1 == NULL)
		img_0d_1 = tui_image_create(this_app_obj);
	if (img_1d_1 == NULL)
		img_1d_1 = tui_image_create(this_app_obj);

	/* 设置属性 */
	attri.obj.pt.x = 280;
	attri.obj.pt.y = 400;
	attri.img_num = 1;
	tui_image_set_attri(img_1u_1, &attri);
	sprintf(path, "V:\\image\\%du.png", num);
	tui_image_set_image_src(img_1u_1, 0, path);
	tui_image_set_cur_img_index(img_1u_1, 0);

	/* 设置属性 */
	attri.obj.pt.x = 280;
	attri.obj.pt.y = 400;
	attri.img_num = 1;
	tui_image_set_attri(img_0u_1, &attri);
	if (num == 0)
		sprintf(path, "V:\\image\\%du.png", 9);
	else
		sprintf(path, "V:\\image\\%du.png", num-1);
	tui_image_set_image_src(img_0u_1, 0, path);
	tui_image_set_cur_img_index(img_0u_1, 0);

	/* 设置属性 */
	attri.obj.pt.x = 280;
	attri.obj.pt.y = 400 + 79;
	attri.img_num = 1;
	tui_image_set_attri(img_0d_1, &attri);
	if (num == 0)
		sprintf(path, "V:\\image\\%dd.png", 9);
	else
		sprintf(path, "V:\\image\\%dd.png", num - 1);
	tui_image_set_image_src(img_0d_1, 0, path);
	tui_image_set_cur_img_index(img_0d_1, 0);

	/* 设置属性 */
	attri.obj.pt.x = 280;
	attri.obj.pt.y = 400 + 79;
	attri.img_num = 1;
	tui_image_set_attri(img_1d_1, &attri);
	sprintf(path, "V:\\image\\%dd.png", num);
	tui_image_set_image_src(img_1d_1, 0, path);
	tui_image_set_cur_img_index(img_1d_1, 0);
	tui_image_set_size(img_1d_1, 100, 0);

	tui_image_anim_height(img_0u_1, 800, 79, 0, TUI_ANIM_PATH_LINEAR, arc_app0_anim1_cb);
	tui_obj_anim_mov_y(img_0u_1, 800, 400, 400 + 79, TUI_ANIM_PATH_LINEAR, NULL);
}

static void arc_app0_anim2_cb(tui_obj_t * obj)
{
	tui_image_anim_height(img_1d_2, 800, 0, 79, TUI_ANIM_PATH_LINEAR, NULL);
}

static void arc_app0_show_num2(int num)
{
	tui_image_attri_t attri = { 0 };
	char path[32] = { 0 };

	if (num < 0 || num > 9)
		return;

	if (img_1u_2) {
		tui_obj_del(img_1u_2);
		img_1u_2 = NULL;
	}
	if (img_0u_2) {
		tui_obj_del(img_0u_2);
		img_0u_2 = NULL;
	}
	if (img_0d_2) {
		tui_obj_del(img_0d_2);
		img_0d_2 = NULL;
	}
	if (img_1d_2) {
		tui_obj_del(img_1d_2);
		img_1d_2 = NULL;
	}

	if (img_1u_2 == NULL)
		img_1u_2 = tui_image_create(this_app_obj);
	if (img_0u_2 == NULL)
		img_0u_2 = tui_image_create(this_app_obj);
	if (img_0d_2 == NULL)
		img_0d_2 = tui_image_create(this_app_obj);
	if (img_1d_2 == NULL)
		img_1d_2 = tui_image_create(this_app_obj);

	/* 设置属性 */
	attri.obj.pt.x = 150;
	attri.obj.pt.y = 400;
	attri.img_num = 1;
	tui_image_set_attri(img_1u_2, &attri);
	sprintf(path, "V:\\image\\%du.png", num);
	tui_image_set_image_src(img_1u_2, 0, path);
	tui_image_set_cur_img_index(img_1u_2, 0);

	/* 设置属性 */
	attri.obj.pt.x = 150;
	attri.obj.pt.y = 400;
	attri.img_num = 1;
	tui_image_set_attri(img_0u_2, &attri);
	if (num == 0)
		sprintf(path, "V:\\image\\%du.png", 9);
	else
		sprintf(path, "V:\\image\\%du.png", num - 1);
	tui_image_set_image_src(img_0u_2, 0, path);
	tui_image_set_cur_img_index(img_0u_2, 0);

	/* 设置属性 */
	attri.obj.pt.x = 150;
	attri.obj.pt.y = 400 + 79;
	attri.img_num = 1;
	tui_image_set_attri(img_0d_2, &attri);
	if (num == 0)
		sprintf(path, "V:\\image\\%dd.png", 9);
	else
		sprintf(path, "V:\\image\\%dd.png", num - 1);
	tui_image_set_image_src(img_0d_2, 0, path);
	tui_image_set_cur_img_index(img_0d_2, 0);

	/* 设置属性 */
	attri.obj.pt.x = 150;
	attri.obj.pt.y = 400 + 79;
	attri.img_num = 1;
	tui_image_set_attri(img_1d_2, &attri);
	sprintf(path, "V:\\image\\%dd.png", num);
	tui_image_set_image_src(img_1d_2, 0, path);
	tui_image_set_cur_img_index(img_1d_2, 0);
	tui_image_set_size(img_1d_2, 100, 0);

	tui_image_anim_height(img_0u_2, 800, 79, 0, TUI_ANIM_PATH_LINEAR, arc_app0_anim2_cb);
	tui_obj_anim_mov_y(img_0u_2, 800, 400, 400 + 79, TUI_ANIM_PATH_LINEAR, NULL);
}

static void num_anim(tui_timer_t * t)
{
	arc_app0_show_num1(g_num % 10);
	if (g_num % 10 == 0 )
		arc_app0_show_num2(g_num / 10);
	g_num = (g_num + 1) % 100;
}

tui_obj_t * arc_app0_enter(void)
{
	g_way = -1;
	
	g_num = 0;
	img_0u_1 = NULL;
	img_0d_1 = NULL;
	img_1u_1 = NULL;
	img_1d_1 = NULL;
	img_0u_2 = NULL;
	img_0d_2 = NULL;
	img_1u_2 = NULL;
	img_1d_2 = NULL;

	tui_sys_msg_reg(arc_app0_sys_msg_cb);

	this_app_obj = arc_app0_arc_view_view_create();
	tui_obj_set_del_cb(this_app_obj, arc_app0_exit);

	tui_arc_set_rounded(tui_get_obj_from_id(this_app_obj, ARC_APP0_ARC_VIEW_ARC_28), 1);

	this_timer = tui_timer_create(arc_loader, 10, TUI_TIMER_PRIO_LOWEST, NULL);
	this_timer2 = tui_timer_create(arc_loader2, 10, TUI_TIMER_PRIO_LOWEST, NULL);
	this_timer3 = tui_timer_create(num_anim, 2000, TUI_TIMER_PRIO_LOWEST, NULL);

	tui_arc_set_anim_loading(tui_get_obj_from_id(this_app_obj, ARC_APP0_ARC_VIEW_ARC_29), 2000, 1);

	return this_app_obj;
}

static void arc_app0_exit(void)
{
	if (this_timer) {
		tui_timer_del(this_timer);
		this_timer = NULL;
	}
	
	if (this_timer2) {
		tui_timer_del(this_timer2);
		this_timer2 = NULL;
	}

	if (this_timer3) {
		tui_timer_del(this_timer3);
		this_timer3 = NULL;
	}

	tui_sys_msg_unreg(arc_app0_sys_msg_cb);
}

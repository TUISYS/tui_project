#include "tui.h"

/*
 * �ֲ���������
 */
static tui_obj_t * this_app_obj;
static FILE *rec_point_file = NULL;


/*
 * ��ͼ��������
 */
extern tui_obj_t * global_bar_status_bar_view_create(void);


static void rec_points_cb(uint8_t state, int32_t x, int32_t y)
{
	char buf[32];

	if (rec_point_file) {
		sprintf(buf, "%09d%02d%04d%04d\r\n", tui_get_system_run_milliseconds(), state, x, y);
		fwrite(buf, 1, strlen(buf), rec_point_file);
	}
}

static void rec_points_start(char* rec_path)
{
	if (rec_point_file == NULL) {
		rec_point_file = fopen(rec_path, "wb");
		if (rec_point_file)
			tui_point_trigger_cb_reg(rec_points_cb);
	}
}

static void rec_points_stop(void)
{
	if (rec_point_file) {
		tui_point_trigger_cb_unreg(rec_points_cb);
		fclose(rec_point_file);
		rec_point_file = NULL;
	}
}

/*
 * APPϵͳ��Ϣ���ջص�����
 */
static int32_t global_bar_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t *dbg_obj;

	switch (cmd)
	{
	case TUI_USER_MSG_APP_DEBUG:
		dbg_obj = tui_get_obj_from_id(this_app_obj, GLOBAL_BAR_STATUS_BAR_IMAGE_258);
		if (0 == tui_image_get_anim_state(dbg_obj)) {
			tui_image_start_anim(dbg_obj, 200, TUI_IMAGE_LOOP);
			rec_points_start("./dbg.txt");
			tui_obj_set_hidden(tui_get_obj_from_id(this_app_obj, GLOBAL_BAR_STATUS_BAR_IMAGE_BTN_259), 1);
		} else {
			rec_points_stop();
			tui_image_stop_anim(dbg_obj);
			tui_image_set_cur_img_index(dbg_obj, 0);
			tui_obj_set_hidden(tui_get_obj_from_id(this_app_obj, GLOBAL_BAR_STATUS_BAR_IMAGE_BTN_259), 0);
		}
		break;
	case TUI_USER_MSG_APP_DEBUG_RUN:
		dbg_obj = tui_get_obj_from_id(this_app_obj, GLOBAL_BAR_STATUS_BAR_IMAGE_258);
		tui_obj_set_hidden(dbg_obj, 1);
		tui_pointer_run_auto_test("./dbg.txt", 1);
		break;
	default:
		break;
	}
	return 0;
}


/*
 * APP�˳��ص�����
 */
static void global_bar_exit(void)
{
	/* ж��ע�����Ϣ���պ�������ͼɾ������վ�� */
	tui_sys_msg_unreg(global_bar_sys_msg_cb);
	this_app_obj = NULL;
}


/*
 * APP��ں��������ⲿ���ã����ص�ǰobject��
 */
tui_obj_t * global_bar_enter(void)
{
	/* ע����Ϣ���պ��� */
	tui_sys_msg_reg(global_bar_sys_msg_cb);

	/* ������ͼ������ͼɾ�����ִ�лص����� */
	this_app_obj = global_bar_status_bar_view_create();
	tui_obj_set_del_cb(this_app_obj, global_bar_exit);

	tui_obj_set_click(tui_get_obj_from_id(this_app_obj, GLOBAL_BAR_STATUS_BAR_IMAGE_258), 1);

	/* ������ͼ��� */
	return this_app_obj;
}


#include "tui.h"

//#define SERIAL_TEST

/*
 * 静态变量控制
 */
static int g_loop_flag;
static int g_exit_flag;
static tui_obj_t * this_logo_obj;
static tui_obj_t * this_login_obj;
static tui_obj_t * this_home_obj;
static tui_obj_t * this_app_obj;
static tui_obj_t * this_bar_status_obj;
static uint8_t cur_screen_index;
static uint8_t cur_app_index;
static tui_timer_t * date_timer;

/*
 * logo、主界面、状态栏视图创建
 */
tui_obj_t * logo_logo_view_view_create(void);
tui_obj_t * home_main_view_view_create(void);
tui_obj_t * home_login_view_view_create(void);
tui_obj_t * global_bar_status_bar_view_create(void);

/*
 * 各个app的入口函数
 */
tui_obj_t * arc_app0_enter(void);
tui_obj_t * button_app1_enter(void);
tui_obj_t * line_app2_enter(void);
tui_obj_t * bar_app3_enter(void);
tui_obj_t * animation_app4_enter(void);
tui_obj_t * dashboard_app5_enter(void);
tui_obj_t * window_app6_enter(void);
tui_obj_t * sound_app7_enter(void);
tui_obj_t * page_app8_enter(void);
tui_obj_t * draw_app9_enter(void);
tui_obj_t * setting_app10_enter(void);
tui_obj_t * logon_app11_enter(void);

/*
 * 串口接收数据回调函数
 */
#ifdef SERIAL_TEST
static int serial_port_read_cb(const char *read_buff, int buf_len)
{
	int i = 0;

	printf("serial_port_read data length=%d ", buf_len);
	for (i = 0; i < buf_len; i++)
		printf("0x%x ", read_buff[i]);

	printf("\n");

	return 0;
}
#endif

/*
 * 状态栏时间刷新定时器回调函数
 */
static void home_date_ref_cb(tui_timer_t * t)
{
	if (this_bar_status_obj) {
		tui_time_t t;
		char time_str[20];
		t = tui_get_localtime();
		sprintf(time_str, "%d:%02d:%02d", t.hour, t.min, t.sec);
		tui_label_set_txt(tui_get_obj_from_id(this_bar_status_obj, GLOBAL_BAR_STATUS_BAR_TIME_26), time_str);
	}
}

static void home_animation_object_anim_cb(tui_obj_t * obj)
{
	tui_obj_anim_mov_x(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_MULTI_SCREEN_3), 300, -100, 0, TUI_ANIM_PATH_EASE_IN, NULL);
}

static void app4_animation_object_anim_cb(tui_obj_t * obj)
{
	tui_sys_msg_send(TUI_USER_MSG_APP4_START, NULL, NULL);
}

static void yu_animation_object_anim_cb(tui_obj_t * obj)
{
	tui_image_set_hor_mirror(tui_get_obj_from_id(this_logo_obj, LOGO_LOGO_VIEW_IMAGE_245), 1);
	tui_obj_anim_mov_x(tui_get_obj_from_id(this_logo_obj, LOGO_LOGO_VIEW_IMAGE_245), 1000, 500, 400, TUI_ANIM_PATH_LINEAR, NULL);
}

/*
 * home界面系统消息接收回调函数
 */
static int32_t home_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	//printf("home system message:0x%x\n", cmd);
	
	switch (cmd)
	{
	case TUI_USER_MSG_APP_LOGO:
		if (this_logo_obj) {
			tui_obj_del(this_logo_obj);
			this_logo_obj = NULL;
		}

		if (tui_config_password_compare("")) {
			this_login_obj = home_login_view_view_create();
			tui_label_set_txt(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_244), tui_config_get_version());
		} else {
			tui_sys_msg_send(TUI_USER_MSG_APP_LOGIN_OK, NULL, NULL);
		}
		break;
	case TUI_USER_MSG_APP_LOGIN_CHECK:
		if (tui_config_password_compare(tui_textbox_get_text(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_TEXTBOX_239)))) {
			tui_label_set_txt(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_243), "Fail");
			tui_obj_anim_fade_in(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_243), 400, NULL);
		} else {
			tui_label_set_txt(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_243), "Success");
			tui_obj_anim_fade_in(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_243), 800, NULL);
			tui_sys_msg_send_dly(TUI_USER_MSG_APP_LOGIN_OK, 800, NULL, NULL);
		}
		break;
	case TUI_USER_MSG_APP_LOGIN_OK:
		if (this_login_obj) {
			tui_obj_del(this_login_obj);
			this_login_obj = NULL;
		}

		if (this_bar_status_obj == NULL) {
			this_bar_status_obj = global_bar_status_bar_view_create();
			date_timer = tui_timer_create(home_date_ref_cb, 500, TUI_TIMER_PRIO_HIGH, NULL);
		}
		if (this_home_obj == NULL)
			this_home_obj = home_main_view_view_create();

		tui_obj_anim_mov_x(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_MULTI_SCREEN_3), 300, 0, -100, TUI_ANIM_PATH_EASE_OUT, home_animation_object_anim_cb);

		tui_group_focus_obj(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_APP_1));
		break;
	case TUI_USER_MSG_APP_POWER_DOWN:
		if (this_home_obj == NULL) {
			tui_sys_msg_send(TUI_USER_MSG_APP_HOME, NULL, NULL);
			g_exit_flag = 1;
		} else {
			if (this_app_obj) {
				tui_obj_del(this_app_obj);
				this_app_obj = NULL;
			}
			if (this_home_obj) {
				tui_obj_del(this_home_obj);
				this_home_obj = NULL;
			}
			if (this_bar_status_obj) {
				tui_timer_del(date_timer);
				date_timer = NULL;
				tui_obj_del(this_bar_status_obj);
				this_bar_status_obj = NULL;
			}
			g_loop_flag = 0;
		}
		break;
	case TUI_USER_MSG_APP_ENTER_HOME:
		if (g_exit_flag == 1) {
			if (this_app_obj) {
				tui_obj_del(this_app_obj);
				this_app_obj = NULL;
			}
			if (this_home_obj) {
				tui_obj_del(this_home_obj);
				this_home_obj = NULL;
			}
			if (this_bar_status_obj) {
				tui_timer_del(date_timer);
				date_timer = NULL;
				tui_obj_del(this_bar_status_obj);
				this_bar_status_obj = NULL;
			}
			g_loop_flag = 0;
		} else {
			if (this_home_obj == NULL) {
				this_home_obj = home_main_view_view_create();
				tui_multi_screen_set_cur_screen_index(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_MULTI_SCREEN_3), cur_screen_index, 0);
				tui_screen_load_anim(this_home_obj, this_app_obj, TUI_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 1, NULL);
				tui_group_focus_obj(tui_get_obj_from_id(this_home_obj, cur_app_index));
				this_app_obj = NULL;
			}

			tui_dbg_core_information_dump();
		}
		break;
	case TUI_USER_MSG_APP0:
		if (this_app_obj == NULL) {
			this_app_obj = arc_app0_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_1;
		}
		break;
	case TUI_USER_MSG_APP1:
		if (this_app_obj == NULL) {
			this_app_obj = button_app1_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_2;
		}
		break;
	case TUI_USER_MSG_APP2:
		if (this_app_obj == NULL) {
			this_app_obj = line_app2_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_3;
		}
		break;
	case TUI_USER_MSG_APP3:
		if (this_app_obj == NULL) {
			this_app_obj = bar_app3_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_4;
		}
		break;
	case TUI_USER_MSG_APP4:
		if (this_app_obj == NULL) {
			this_app_obj = animation_app4_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, app4_animation_object_anim_cb);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_5;
		}
		break;
	case TUI_USER_MSG_APP5:
		if (this_app_obj == NULL) {
			this_app_obj = dashboard_app5_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_6;
		}
		break;
	case TUI_USER_MSG_APP6:
		if (this_app_obj == NULL) {
			this_app_obj = window_app6_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_7;
		}
		break;
	case TUI_USER_MSG_APP7:
		if (this_app_obj == NULL) {
			this_app_obj = sound_app7_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_8;
		}
		break;
	case TUI_USER_MSG_APP8:
		if (this_app_obj == NULL) {
			this_app_obj = page_app8_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_9;
		}
		break;
	case TUI_USER_MSG_APP9:
		if (this_app_obj == NULL) {
			this_app_obj = draw_app9_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_10;
		}
		break;
	case TUI_USER_MSG_APP10:
		if (this_app_obj == NULL) {
			this_app_obj = setting_app10_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_11;
		}
		break;
	case TUI_USER_MSG_APP11:
		if (this_app_obj == NULL) {
			this_app_obj = logon_app11_enter();
			tui_screen_load_anim(this_app_obj, this_home_obj, TUI_SCR_LOAD_ANIM_MOVE_LEFT, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_12;
		}
		break;
	case TUI_USER_MSG_HOME_SCREEN_SWITCH:
		if (0 == tui_multi_screen_set_cur_screen_index(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_MULTI_SCREEN_3), (uint8_t)param1, 1)) {
			cur_screen_index = (uint8_t)param1;
		}
	default:
		break;
	}
	return 0;
}
static int get_file_last_time(char *path)
{
	char str_temp[256];
	int ret = -1;
	STD_DIR *dir = NULL;
	STD_DIRENT *ptr = NULL;

	dir = opendir(path);
	if (dir == NULL) {
		return -1;
	}
	
	while ((ptr = readdir(dir)) != NULL) {
		strcpy(str_temp, ptr->d_name);
		printf("%d:%s\n", ptr->fatdirattr, str_temp);
	}

	closedir(dir);

	return ret;
}

static void draw_line(void)
{
	int x0, y0, x1, y1;
	tui_obj_t *line1_obj, *line2_obj, *line3_obj, *line4_obj;
	tui_obj_t *line5_obj, *line6_obj, *line7_obj;
	tui_line_attri_t line1_attr = { 0 }, line2_attr = { 0 }, line3_attr = { 0 }, line4_attr = { 0 };
	tui_line_attri_t line5_attr = { 0 }, line6_attr = { 0 }, line7_attr = { 0 };
	tui_point_t pt0 = { 100, 50 }, /* pt2, pt4,*/ pt6 = {50,  200};
	tui_point_t pt1 = { 200, 50 }, /* pt3, pt5,*/ pt7 = {250, 200};

	line1_attr.color = 0xFFFF0000;
	line1_attr.width = 2;
	line1_attr.pts[0] = pt0;
	line1_attr.pts[1] = pt1;
	line1_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line1_obj, &line1_attr);

	line2_attr.color = 0xFFFF0000;
	line2_attr.width = 2;
	line2_attr.pts[0] = pt6;
	line2_attr.pts[1] = pt7;
	line2_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line2_obj, &line2_attr);

	line3_attr.color = 0xFFFF0000;
	line3_attr.width = 2;
	line3_attr.pts[0] = pt0;
	line3_attr.pts[1] = pt6;
	line3_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line3_obj, &line3_attr);

	line4_attr.color = 0xFFFF0000;
	line4_attr.width = 2;
	line4_attr.pts[0] = pt1;
	line4_attr.pts[1] = pt7;
	line4_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line4_obj, &line4_attr);




	x0 = pt0.x;
	y0 = pt0.y;
	x1 = pt6.x;
	y1 = pt6.y;
	line5_attr.color = 0xFF00FF00;
	line5_attr.width = 1;
	line5_attr.pts[0].y = 70;
	line5_attr.pts[0].x = ((line5_attr.pts[0].y - y0)*(x1 - x0) + x0*(y1 - y0)) / (y1 - y0);
	x0 = pt1.x;
	y0 = pt1.y;
	x1 = pt7.x;
	y1 = pt7.y;
	line5_attr.pts[1].y = 70;
	line5_attr.pts[1].x = ((line5_attr.pts[1].y - y0)*(x1 - x0) + x0*(y1 - y0)) / (y1 - y0);
	line5_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line5_obj, &line5_attr);



	x0 = pt0.x;
	y0 = pt0.y;
	x1 = pt6.x;
	y1 = pt6.y;
	line6_attr.color = 0xFF0000FF;
	line6_attr.width = 1;
	line6_attr.pts[0].y = 95;
	line6_attr.pts[0].x = ((line6_attr.pts[0].y - y0)*(x1 - x0) + x0*(y1 - y0)) / (y1 - y0);
	x0 = pt1.x;
	y0 = pt1.y;
	x1 = pt7.x;
	y1 = pt7.y;
	line6_attr.pts[1].y = 95;
	line6_attr.pts[1].x = ((line6_attr.pts[1].y - y0)*(x1 - x0) + x0*(y1 - y0)) / (y1 - y0);
	line6_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line6_obj, &line6_attr);



	x0 = pt0.x;
	y0 = pt0.y;
	x1 = pt6.x;
	y1 = pt6.y;
	line7_attr.color = 0xFFFFFF00;
	line7_attr.width = 1;
	line7_attr.pts[0].y = 133;
	line7_attr.pts[0].x = ((line7_attr.pts[0].y - y0)*(x1 - x0) + x0*(y1 - y0)) / (y1 - y0);
	x0 = pt1.x;
	y0 = pt1.y;
	x1 = pt7.x;
	y1 = pt7.y;
	line7_attr.pts[1].y = 133;
	line7_attr.pts[1].x = ((line7_attr.pts[1].y - y0)*(x1 - x0) + x0*(y1 - y0)) / (y1 - y0);
	line7_obj = tui_line_create(tui_layer_normal());
	tui_line_set_attri(line7_obj, &line7_attr);
}

/*
 * 应用入口函数
 */
int gauge_create(const char *soc_str, const char *km_str, const char *tm_str, const char *bottom_str);
int home_create(void)
{
	//return gauge_create("0.0v 000A", "000000 km", "2021-07-08 19:49", "TRIP 000.6 km");
	//get_file_last_time("D:\\Kingvan");
	/* 初始化TUI资源 */
#ifdef __EOS__
	tui_start_init("/mnt/sdcard/res.disk", -1, -1);
#else
	tui_start_init("./tdemo/res.disk", -1, -1);
#endif

#ifdef SERIAL_TEST
	/* 初始化硬件串口 */
	serial_port_open("COM3", -1, -1, -1, -1, serial_port_read_cb);

	/* 测试发送串口数据 */
	serial_port_write("hello world\n", 1);

#endif

	g_exit_flag = 0;
	g_loop_flag = 1;

	/* 创建logo界面视图 */
	this_logo_obj = logo_logo_view_view_create();
	tui_obj_anim_mov_x(tui_get_obj_from_id(this_logo_obj, LOGO_LOGO_VIEW_IMAGE_245), 1000, 400, 500, TUI_ANIM_PATH_EASE_OUT, yu_animation_object_anim_cb);
	
	/* 注册home界面系统消息回调函数 */
	tui_sys_msg_reg(home_sys_msg_cb);

	/* TUI处理器 */
	while (g_loop_flag) {
		tui_run_loop();
	}

#ifdef SERIAL_TEST
	/* 关闭硬件串口 */
	serial_port_close();
#endif

	/* 释放TUI资源退出 */
	tui_end_uninit();
	
	return 0;
}

#ifdef __EOS__
void home_destorty(void)
{
	tui_sys_msg_send(TUI_USER_MSG_APP_POWER_DOWN, NULL, NULL);
}
#endif

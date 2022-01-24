#include "tui.h"

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


/*
 * 应用入口函数
 */
int home_create(void)
{
	/* 初始化TUI资源 */
#ifdef __EOS__
	tui_start_init("/mnt/sdcard/res.disk", -1, -1);
#else
	tui_start_init("./tdemo/res.disk", -1, -1);
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

#include "tui.h"

/*
 * ��̬��������
 */
static int g_loop_flag;
static int g_exit_flag;
static tui_obj_t * this_adjust_obj;
static tui_obj_t * this_logo_obj;
static tui_obj_t * this_login_obj;
static tui_obj_t * this_home_obj;
static tui_obj_t * this_app_obj;
static tui_obj_t * this_bar_status_obj;
static uint8_t cur_screen_index;
static uint8_t cur_app_index;
static tui_timer_t * date_timer;

/*
 * logo�������桢״̬����ͼ����
 */
tui_obj_t * logo_logo_view_view_create(void);
tui_obj_t * home_main_view_view_create(void);
tui_obj_t * home_login_view_view_create(void);
tui_obj_t * global_bar_status_bar_view_create(void);

/*
 * ����app����ں���
 */
tui_obj_t * adjust_enter(void);
tui_obj_t * arc_app0_enter(void);
tui_obj_t * button_app1_enter(void);
tui_obj_t * line_app2_enter(void);
tui_obj_t * bar_app3_enter(void);
tui_obj_t * animation_app4_enter(void);
tui_obj_t * dashboard_app5_enter(void);
tui_obj_t * window_app6_enter(void);
tui_obj_t * uart_app7_enter(void);
tui_obj_t * page_app8_enter(void);
tui_obj_t * draw_app9_enter(void);
tui_obj_t * setting_app10_enter(void);
tui_obj_t * logon_app11_enter(void);

/*
 * ״̬��ʱ��ˢ�¶�ʱ���ص�����
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

static void yu_animation_object_anim_cb(tui_obj_t * obj)
{
	tui_image_set_hor_mirror(tui_get_obj_from_id(this_logo_obj, LOGO_LOGO_VIEW_IMAGE_255), 1);
	tui_obj_anim_mov_x(tui_get_obj_from_id(this_logo_obj, LOGO_LOGO_VIEW_IMAGE_255), 1000, 480, 300, TUI_ANIM_PATH_LINEAR, NULL);
}

/*
 * home����ϵͳ��Ϣ���ջص�����
 */
static int32_t home_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{	
	switch (cmd)
	{
	case TUI_USER_MSG_APP_ADJUT_OK:
		if (this_adjust_obj) {
			tui_obj_del(this_adjust_obj);
			this_adjust_obj = NULL;
		}

		if (tui_config_password_compare("")) {
			this_login_obj = home_login_view_view_create();
			tui_label_set_txt(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_256), tui_config_get_version());
		} else {
			tui_sys_msg_send_dly(TUI_USER_MSG_APP_LOGIN_OK, 800, NULL, NULL);
		}
		break;
	case TUI_USER_MSG_APP_LOGIN_CHECK:
		if (tui_config_password_compare(tui_textbox_get_text(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_TEXTBOX_251)))) {
			tui_label_set_txt(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_257), "Fail");
			tui_obj_anim_fade_in(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_257), 400, NULL);
		} else {
			tui_label_set_txt(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_257), "Success");
			tui_obj_anim_fade_in(tui_get_obj_from_id(this_login_obj, HOME_LOGIN_VIEW_LABEL_257), 800, NULL);
			tui_sys_msg_send_dly(TUI_USER_MSG_APP_LOGIN_OK, 800, NULL, NULL);
		}
		break;
	case TUI_USER_MSG_APP_LOGIN_OK:
		if (this_login_obj) {
			tui_obj_del(this_login_obj);
			this_login_obj = NULL;
		}
		if (this_logo_obj == NULL) {
			this_logo_obj = logo_logo_view_view_create();
			tui_obj_anim_mov_x(tui_get_obj_from_id(this_logo_obj, LOGO_LOGO_VIEW_IMAGE_255), 1000, 300, 480, TUI_ANIM_PATH_EASE_OUT, yu_animation_object_anim_cb);
		}
		break;
	case TUI_USER_MSG_APP_LOGO:
		if (this_bar_status_obj == NULL) {
			this_bar_status_obj = global_bar_status_bar_view_create();
			date_timer = tui_timer_create((tui_timer_cb_t)home_date_ref_cb, 500, TUI_TIMER_PRIO_MID, NULL);
		}
		if (this_home_obj == NULL)
			this_home_obj = home_main_view_view_create();

		//tui_group_focus_obj(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_APP_1)); 

		if (this_logo_obj) {
			tui_obj_del(this_logo_obj);
			this_logo_obj = NULL;
		}
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
				tui_point_t anim_start_pt = { 80, 30 };
				this_home_obj = home_main_view_view_create();
				tui_multi_screen_set_cur_screen_index(tui_get_obj_from_id(this_home_obj, HOME_MAIN_VIEW_MULTI_SCREEN_3), cur_screen_index, 0);

				if (cur_app_index == HOME_MAIN_VIEW_APP_1 || cur_app_index == HOME_MAIN_VIEW_APP_7) {
					anim_start_pt.x = 160;
					anim_start_pt.y = 200;
				} else if (cur_app_index == HOME_MAIN_VIEW_APP_2 || cur_app_index == HOME_MAIN_VIEW_APP_8) {
					anim_start_pt.x = 400;
					anim_start_pt.y = 200;
				} else if (cur_app_index == HOME_MAIN_VIEW_APP_3 || cur_app_index == HOME_MAIN_VIEW_APP_9) {
					anim_start_pt.x = 640;
					anim_start_pt.y = 200;
				} else if (cur_app_index == HOME_MAIN_VIEW_APP_4 || cur_app_index == HOME_MAIN_VIEW_APP_10) {
					anim_start_pt.x = 640;
					anim_start_pt.y = 400;
				} else if (cur_app_index == HOME_MAIN_VIEW_APP_5 || cur_app_index == HOME_MAIN_VIEW_APP_11) {
					anim_start_pt.x = 400;
					anim_start_pt.y = 400;
				} else if (cur_app_index == HOME_MAIN_VIEW_APP_6 || cur_app_index == HOME_MAIN_VIEW_APP_12) {
					anim_start_pt.x = 160;
					anim_start_pt.y = 400;
				}
				tui_screen_load_anim_out_ext(this_home_obj, this_app_obj, anim_start_pt, 300, 1, NULL);
				
				tui_group_focus_obj(tui_get_obj_from_id(this_home_obj, cur_app_index));
				this_app_obj = NULL;
			}

			tui_dbg_core_information_dump();
		}
		break;
	case TUI_USER_MSG_APP0:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 160, 200 };
			this_app_obj = arc_app0_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_1;
		}
		break;
	case TUI_USER_MSG_APP1:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 400, 200 };
			this_app_obj = button_app1_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_2;
		}
		break;
	case TUI_USER_MSG_APP2:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 640, 200 };
			this_app_obj = line_app2_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_3;
		}
		break;
	case TUI_USER_MSG_APP3:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 640, 400 };
			this_app_obj = bar_app3_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_4;
		}
		break;
	case TUI_USER_MSG_APP4:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 400, 400 };
			this_app_obj = animation_app4_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_5;
		}
		break;
	case TUI_USER_MSG_APP5:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 160, 400 };
			this_app_obj = dashboard_app5_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 0;
			cur_app_index = HOME_MAIN_VIEW_APP_6;
		}
		break;
	case TUI_USER_MSG_APP6:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 160, 200 };
			this_app_obj = window_app6_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_7;
		}
		break;
	case TUI_USER_MSG_APP7:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 400, 200 };
			this_app_obj = uart_app7_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_8;
		}
		break;
	case TUI_USER_MSG_APP8:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 640, 200 };
			this_app_obj = page_app8_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_9;
		}
		break;
	case TUI_USER_MSG_APP9:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 640, 400 };
			this_app_obj = draw_app9_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_10;
		}
		break;
	case TUI_USER_MSG_APP10:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 400, 400 };
			this_app_obj = setting_app10_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_11;
		}
		break;
	case TUI_USER_MSG_APP11:
		if (this_app_obj == NULL) {
			tui_point_t anim_start_pt = { 160, 400 };
			this_app_obj = logon_app11_enter();
			tui_screen_load_anim_in_ext(this_app_obj, this_home_obj, anim_start_pt, 300, 1, NULL);
			this_home_obj = NULL;
			cur_screen_index = 1;
			cur_app_index = HOME_MAIN_VIEW_APP_12;
		}
		break;
	default:
		break;
	}
	return 0;
}

static tui_obj_t * sound_tone;
static int sound_play_f;
static void create_key_tone(void)
{
	/* Create an sound */
	tui_sound_attri_t attri_sound = { 0 };
	/* �������� */
	sound_play_f = 0;
	sound_tone = tui_sound_create(tui_layer_normal());
	/* �������� */
	tui_sound_set_attri(sound_tone, &attri_sound);
	/* ������Դ */
	tui_sound_set_sound_src(sound_tone, "V:\\sound\\tone.wav");/* ȷ��������res.iso������·���ļ����� */
}

static void indev_point_trigger(uint8_t state, int32_t x, int32_t y)
{
	if (state == 1 && sound_play_f == 0) {
		sound_play_f = 1;
		tui_sound_play(sound_tone);
	}

	if (state == 0)
		sound_play_f = 0;
}

/*
 * Ӧ����ں���
 */
int home_create(void)
{
	FILE* tp_config;
	
	/* ��ʼ��TUI��Դ */
#ifdef __EOS__
	tui_start_init("/mnt/sdcard/res.disk");
#elif defined (AW_MELIS)
	//tui_start_init("D:\\apps\\res.disk");
	tui_start_init("F:\\res.disk");
#else
	tui_start_init("../../res.disk");
#endif
	
	g_exit_flag = 0;
	g_loop_flag = 1;

	tp_config = fopen("E:\\tpcfg.ini", "rb");

	if (tp_config) {
		fclose(tp_config);
		tui_sys_msg_send(TUI_USER_MSG_APP_ADJUT_OK, NULL, NULL);
	} else {
		/* ����logo������ͼ */
		this_adjust_obj = adjust_enter();
	}
	
	/* ע��home����ϵͳ��Ϣ�ص����� */
	tui_sys_msg_reg(home_sys_msg_cb);

	create_key_tone();
	tui_point_trigger_cb_reg(indev_point_trigger);

	/* TUI������ */
	while (g_loop_flag) {
		tui_run_loop();
	}
	
	if (sound_tone)
		tui_obj_del(sound_tone);

	/* �ͷ�TUI��Դ�˳� */
	tui_end_uninit();
	
	return 0;
}


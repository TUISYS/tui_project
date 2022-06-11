#ifndef __TUI_H__
#define __TUI_H__

#ifndef TUI_SOURCE_CODE
#include "stdxxx.h"
#else
#include "def_inlcude.h"
#endif
#include "sys_msg_def.h"
#include "tui_id.h"

#define TUI_ARGB_COLOR_MAKE(a, r, g, b) (((a&0xff) << 24) | ((r&0xff) << 16) | ((g&0xff) << 8) | (b&0xff))
#define TUI_OBJ(id) tui_search_obj_from_id(id)

typedef void * tui_obj_t;
typedef void * tui_timer_t;
typedef int32_t tui_coord_t;

typedef struct tag_tui_point {
        tui_coord_t x;
        tui_coord_t y;
} tui_point_t;

typedef struct tag_tui_area {
        tui_coord_t x1;
        tui_coord_t y1;
        tui_coord_t x2;
        tui_coord_t y2;
} tui_area_t;

typedef struct tag_tui_size {
        uint32_t width;
        uint32_t height;
} tui_size_t;

typedef struct tag_tui_style {
        uint8_t * map;
        uint32_t sentinel;
} tui_style_t;

typedef struct tag_tui_map_cb {
        uint32_t id;
        void * func;
} tui_map_cb_t;

typedef struct tag_tui_time {
        int sec;                                /* �� - [0,59] */
        int min;                                /* �� - [0,59] */
        int hour;                               /* ʱ - [0,23] */
        int mday;                               /* �� - [1,31] */
        int mon;                                /* �� - [0,11] */
        int year;                               /* ��  */
        int wday;                               /* ���ڣ�0�������� - [0,6] */
} tui_time_t;

typedef enum tag_obj_event {
        TUI_EVENT_PRESSED             = 0,      /* ���������� */
        TUI_EVENT_PRESSING            = 1,      /* �������������� */
        TUI_EVENT_PRESS_LOST          = 2,      /* ���������¶�ʧ */
        TUI_EVENT_SHORT_CLICKED       = 3,      /* �����ʱ�䰴�� */
        TUI_EVENT_LONG_PRESSED        = 4,      /* ����ʱ�䰴�� */
        TUI_EVENT_LONG_PRESSED_REPEAT = 5,      /* �����ظ���ʱ�䰴�� */
        TUI_EVENT_CLICKED             = 6,      /* ���������� */
        TUI_EVENT_RELEASED            = 7,      /* ������̧�� */
        TUI_EVENT_DRAG_BEGIN          = 8,      /* ��������ק��ʼ */
        TUI_EVENT_DRAG_END            = 9,      /* ��������ק���� */
        TUI_EVENT_DRAG_THROW_BEGIN    = 10,     /* ��������ק��ʼ */
        TUI_EVENT_GESTURE             = 11,     /* ����������¼� */
        TUI_EVENT_KEY                 = 12,     /* ����ļ����¼� */
        TUI_EVENT_FOCUSED             = 13,     /* ���󽹵�״̬�¼� */
        TUI_EVENT_DEFOCUSED           = 14,     /* ����ʧȥ����״̬�¼� */
        TUI_EVENT_LEAVE               = 15,     /* �����뿪�¼� */
        TUI_EVENT_VALUE_CHANGED       = 16,     /* �����ֵ�����ı��¼� */
        TUI_EVENT_INSERT              = 17,     /* ��������¼� */
        TUI_EVENT_REFRESH             = 18,     /* ����ˢ���¼� */
        TUI_EVENT_APPLY               = 19,     /* ����Ӧ���¼� */
        TUI_EVENT_CANCEL              = 20,     /* �����˳��¼� */
        TUI_EVENT_DELETE              = 21,     /* ����ɾ���¼� */
        TUI_EVENT_LAST                = 22,     /* �����¼� */
        TUI_EVENT_USER_DEF            = 23,     /* �����¼� */
        TUI_EVENT_OBJECT_INIT         = 24,     /* ���󴴽���ʼ���¼� */
        TUI_EVENT_SOUND_PLAY_END      = 25,     /* �������󲥷Ž����¼� */
        TUI_EVENT_IMAGE_ANIMATION_END = 26,     /* ���󶯻����Ž����¼� */
} tui_event_e;

typedef enum tag_tui_key_value {
        TUI_KEY_HOME                  = 2,
        TUI_KEY_END                   = 3,
        TUI_KEY_BACKSPACE             = 8,
        TUI_KEY_NEXT                  = 9,
        TUI_KEY_ENTER                 = 10,
        TUI_KEY_PREV                  = 11,
        TUI_KEY_UP                    = 17,
        TUI_KEY_DOWN                  = 18,
        TUI_KEY_RIGHT                 = 19,
        TUI_KEY_LEFT                  = 20,
        TUI_KEY_ESC                   = 27,
        TUI_KEY_DEL                   = 127,
} tui_key_value_e;

typedef enum tag_timer_prio {
        TUI_TIMER_PRIO_OFF = 0,
        TUI_TIMER_PRIO_LOWEST,                  /* ������ȼ� */
        TUI_TIMER_PRIO_LOW,                     /* �����ȼ� */
        TUI_TIMER_PRIO_MID,                     /* �е����ȼ� */
        TUI_TIMER_PRIO_HIGH,                    /* �����ȼ� */
        TUI_TIMER_PRIO_HIGHEST,                 /* ������ȼ� */
        TUI_TIMER_PRIO_NUM,
} tui_timer_prio_e;

typedef enum tag_tui_align {
        TUI_ALIGN_CENTER = 0,                   /* ���ж��� */
        TUI_ALIGN_IN_TOP_LEFT,                  /* �ڶ����ڲ����˿������ */
        TUI_ALIGN_IN_TOP_MID,                   /* �ڶ����ڲ������м���� */
        TUI_ALIGN_IN_TOP_RIGHT,                 /* �ڶ����ڲ����˿��Ҷ��� */
        TUI_ALIGN_IN_BOTTOM_LEFT,               /* �ڶ����ڲ��׶˿������ */
        TUI_ALIGN_IN_BOTTOM_MID,                /* �ڶ����ڲ��׶˿������ */
        TUI_ALIGN_IN_BOTTOM_RIGHT,              /* �ڶ����ڲ��׶˿��Ҷ��� */
        TUI_ALIGN_IN_LEFT_MID,                  /* �ڶ����ڲ�������ж��� */
        TUI_ALIGN_IN_RIGHT_MID,                 /* �ڶ����ڲ����Ҿ��ж��� */
        TUI_ALIGN_OUT_TOP_LEFT,                 /* �ڶ����ⲿ���˿������ */
        TUI_ALIGN_OUT_TOP_MID,                  /* �ڶ����ⲿ�����м���� */
        TUI_ALIGN_OUT_TOP_RIGHT,                /* �ڶ����ⲿ���˿��Ҷ��� */
        TUI_ALIGN_OUT_BOTTOM_LEFT,              /* �ڶ����ⲿ�׶˿������ */
        TUI_ALIGN_OUT_BOTTOM_MID,               /* �ڶ����ⲿ�׶˿������ */
        TUI_ALIGN_OUT_BOTTOM_RIGHT,             /* �ڶ����ⲿ�׶˿��Ҷ��� */
        TUI_ALIGN_OUT_LEFT_TOP,                 /* �ڶ����ⲿ���󶥲����� */
        TUI_ALIGN_OUT_LEFT_MID,                 /* �ڶ����ⲿ������ж��� */
        TUI_ALIGN_OUT_LEFT_BOTTOM,              /* �ڶ����ⲿ����ײ����� */
        TUI_ALIGN_OUT_RIGHT_TOP,                /* �ڶ����ⲿ���Ҷ������� */
        TUI_ALIGN_OUT_RIGHT_MID,                /* �ڶ����ⲿ���Ҿ��ж��� */
        TUI_ALIGN_OUT_RIGHT_BOTTOM,             /* �ڶ����ⲿ���ҵײ����� */
} tui_align_e;

typedef enum tag_tui_label_long_mode {
        TUI_LABEL_LONG_EXPAND = 0,              /* ��С���ı�һ�� */
        TUI_LABEL_LONG_BREAK,                   /* ���ֿ�ȣ����ı������Ļ��У����Ӹ߶� */
        TUI_LABEL_LONG_DOT,                     /* �������ڽ�βд��...�� */
        TUI_LABEL_LONG_SROLL,                   /* �����С�����ı��ڹ��� */
        TUI_LABEL_LONG_SROLL_CIRC,              /* ѭ������ */
        TUI_LABEL_LONG_CROP,                    /* �ü��ı� */
} tui_label_long_mode_e;

typedef enum tag_tui_label_align_t {
        TUI_LABEL_ALIGN_LEFT = 0,               /* ����� */
        TUI_LABEL_ALIGN_CENTER,                 /* ���Ķ��� */
        TUI_LABEL_ALIGN_RIGHT,                  /* �Ҷ��� */
        TUI_LABEL_ALIGN_AUTO,                   /* ���ı�������� */
} tui_label_align_e;

typedef enum tag_tui_border_side {
        TUI_BORDER_SIDE_NONE    = 0x00,         /* �ޱ߿� */
        TUI_BORDER_SIDE_BOTTOM  = 0x01,         /* �±߱߿� */
        TUI_BORDER_SIDE_TOP     = 0x02,         /* �ϱ߱߿� */
        TUI_BORDER_SIDE_LEFT    = 0x04,         /* ��߱߿� */
        TUI_BORDER_SIDE_RIGHT   = 0x08,         /* �ұ߱߿� */
        TUI_BORDER_SIDE_FULL    = 0x0F,         /* ȫ�߱߿� */
} tui_border_side_e;

typedef enum tag_tui_drag_dir {
        TUI_DRAG_NONE_DIR       = 0x0,          /* �����϶� */
        TUI_DRAG_DIR_HOR        = 0x1,          /* ֻ��ˮƽ�϶� */
        TUI_DRAG_DIR_VER        = 0x2,          /* ֻ�ܴ�ֱ�϶� */
        TUI_DRAG_DIR_BOTH       = 0x3,          /* �����϶� */
        TUI_DRAG_DIR_ONE        = 0x4,          /* ��һ���϶��ķ����϶� */
} tui_drag_dir_e;

typedef enum tag_tui_scrollbar_mode {
        TUI_SCROLLBAR_MODE_OFF  = 0x0,          /* ����ʾ */
        TUI_SCROLLBAR_MODE_ON   = 0x1,          /* һֱ��ʾ */
        TUI_SCROLLBAR_MODE_DRAG = 0x2,          /* ��ק��ʱ����ʾ */
        TUI_SCROLLBAR_MODE_AUTO = 0x3,          /* �Զ� */
        TUI_SCROLLBAR_MODE_HIDE = 0x4,          /* ��ʱ���� */
} tui_scrollbar_mode_e;

typedef enum tag_tui_image_circulate {
        TUI_IMAGE_ONCE = 0,                     /* ����һ�ζ��� */
        TUI_IMAGE_LOOP,                         /* ѭ�����ж��� */
} tui_image_circulate_e;

typedef enum tag_tui_scr_load_anim {
        TUI_SCR_LOAD_ANIM_NONE = 0,             /* �޶��� */
        TUI_SCR_LOAD_ANIM_OVER_LEFT,            /* �������ƶ� */
        TUI_SCR_LOAD_ANIM_OVER_RIGHT,           /* �������ƶ� */
        TUI_SCR_LOAD_ANIM_OVER_TOP,             /* �������ƶ� */
        TUI_SCR_LOAD_ANIM_OVER_BOTTOM,          /* �������ƶ� */
        TUI_SCR_LOAD_ANIM_MOVE_LEFT,            /* ˫�����ƶ� */
        TUI_SCR_LOAD_ANIM_MOVE_RIGHT,           /* ˫�����ƶ� */
        TUI_SCR_LOAD_ANIM_MOVE_TOP,             /* ˫�����ƶ� */
        TUI_SCR_LOAD_ANIM_MOVE_BOTTOM,          /* ˫�����ƶ� */
        TUI_SCR_LOAD_ANIM_FADE_ON,              /* ˫���뵭�� */
} tui_scr_load_anim_e;

typedef enum tag_tui_anim_path {
        TUI_ANIM_PATH_LINEAR = 0,               /* ����Ч�� */
        TUI_ANIM_PATH_EASE_IN,                  /* ����Ч�� */
        TUI_ANIM_PATH_EASE_OUT,                 /* ����Ч�� */
        TUI_ANIM_PATH_EASE_IN_OUT,              /* ���ټ���Ч�� */
        TUI_ANIM_PATH_OVERSHOOT,                /* Խ�����Ч�� */
        TUI_ANIM_PATH_BOUNCE,                   /* ��������Ч�� */
        TUI_ANIM_PATH_STEP,                     /* ʱ�䵽��ֱ����ʾ */
} tui_anim_path_e;

/*------------------------
 *  TUI�������ڣ���ʼ�������С�����
 *------------------------*/
void tui_start_init(const char * res_path);
void tui_run_loop(void);
void tui_end_uninit(void);

/*------------------------
 *  system messageϵͳ��Ϣ
 *------------------------*/
typedef int32_t (*tui_sys_msg_cb_t)(uint32_t cmd, void *param0, void *param1);
int32_t tui_sys_msg_reg(tui_sys_msg_cb_t cb);
int32_t tui_sys_msg_unreg(tui_sys_msg_cb_t cb);
int32_t tui_sys_msg_send(uint32_t cmd, void *param0, void *param1);
int32_t tui_sys_msg_send_dly(uint32_t cmd, uint32_t dly_ms, void *param0, void *param1);

/*------------------------
 *  timer��ʱ��
 *------------------------*/
typedef void(*tui_timer_cb_t)(tui_timer_t * timer);
tui_timer_t * tui_timer_create(tui_timer_cb_t timer_cb, uint32_t period, tui_timer_prio_e prio, void * user_data);
void tui_timer_reset(tui_timer_t * timer);
void tui_timer_set_cb(tui_timer_t * timer, tui_timer_cb_t timer_cb);
void tui_timer_set_period(tui_timer_t * timer, uint32_t period);
void tui_timer_set_prio(tui_timer_t * timer, tui_timer_prio_e prio);
void tui_timer_del(tui_timer_t * timer);
void * tui_timer_get_user_data(tui_timer_t * timer);

/*------------------------
 *  ��ȡres.disk��������
 *------------------------*/
int tui_config_get_screen_resolution(int *screen_hor_res, int *screen_ver_res);
const char * tui_config_get_version(void);
int tui_config_password_compare(const char * password);
int tui_config_get_serial_port(int *baudrate, int *bytesize, int *parity, int *stopbits);
int tui_config_get_screen_rotate_angle(void);

/*------------------------
 *  language�������
 *------------------------*/
int tui_get_language_num(void);
void tui_set_language(int16_t lang_index);
const char * tui_get_language_utf8_string(const char *str_id);

/*------------------------
 *  ��ȡres.disk��V���ļ�
 *------------------------*/
void *tui_alloc_buffer_from_fs(const char *path, int *get_buf_len);
int tui_free_buffer_from_fs(void *buf);

/*------------------------
 *  gb2312��utf8���ת��
 *------------------------*/
int tui_utf8_to_gb2312(char *gb2312_str, int len_gb2312, char *utf8_str, int len_utf8);
int tui_gb2312_to_utf8(char *utf8_str, int len_utf8, char *gb2312_str, int len_gb2312);
int tui_gb2312_to_utf8_need_size(char *gb2312_str);

/*------------------------
 *  ��ȡϵͳ����ʱ�䡢RTC���ڡ�����
 *------------------------*/
uint32_t tui_get_system_run_milliseconds(void);
tui_time_t tui_get_localtime(void);
void tui_set_localtime(tui_time_t *lt);
void tui_sleep(uint32_t ms);

/*------------------------
 *  ���ڽӿڣ�����PC����ģ��
 *------------------------*/
typedef int(*tui_serial_port_read_cb_t)(const char *read_buff, int buf_len);
int tui_serial_port_open(char *com_name, int baudrate, int bytesize, int parity, int stopbits, tui_serial_port_read_cb_t read_cb);
void tui_serial_port_close(void);
int tui_serial_port_write(char *write_buff, int buf_len);

/*------------------------
 *  tui input��ȡ�����Ͱ���ֵ
 *------------------------*/
typedef void (*tui_point_trigger_cb_t)(uint8_t state, int32_t x, int32_t y);
typedef void (*tui_key_trigger_cb_t)(uint8_t state, uint32_t key_value);
void tui_point_trigger_cb_reg(tui_point_trigger_cb_t cb);
void tui_point_trigger_cb_unreg(tui_point_trigger_cb_t cb);
void tui_key_trigger_cb_reg(tui_key_trigger_cb_t cb);
void tui_key_trigger_cb_unreg(tui_key_trigger_cb_t cb);
void tui_get_point_value(uint8_t *st, int32_t *x, int32_t *y);
void tui_get_key_value(uint8_t *st, uint32_t *key_value);

/*------------------------
 *  group������
 *------------------------*/
void tui_group_add_obj(tui_obj_t * obj);
void tui_group_remove_obj(tui_obj_t * obj);
void tui_group_remove_all_objs(void);
void tui_group_focus_obj(tui_obj_t * obj);
tui_obj_t * tui_group_get_focused(void);

/*------------------------
 *  ������Ϣ
 *------------------------*/
void tui_dbg_core_information_dump(void);
void tui_pointer_run_auto_test(char *rec_path, int is_loop_run);

/*------------------------
 *  ����object����ĸ��ڵ�
 *------------------------*/
tui_obj_t * tui_layer_normal(void);             /* ��ͨ���ڵ����ͼ�� */
tui_obj_t * tui_layer_top(void);                /* ����һ�����ö����ڵ����ͼ�� */
/*------------------------
 *  object��������
 *------------------------*/
typedef struct {
        /* ���ڲ�ʹ��style */
        tui_style_t style;

        tui_size_t size;                        /* �ⲿ���ã�����Ŀ������ */
        tui_point_t pt;                         /* �ⲿ���ã��������ڵ�λ�� */
        bool hidden;                            /* �ⲿ���ã������Ƿ����� */
        uint32_t obj_id;                        /* �ⲿ���ã������ΨһIDֵ */
        char type_name[32];                     /* �ⲿ���ã�����Ŀؼ��������� �� ��Ҫ����31��Ӣ���ַ�*/
} tui_object_attri_t;
/*------------------------
 *  ����������object����
 *------------------------*/
tui_obj_t * tui_obj_create(tui_obj_t * parent);
void tui_obj_del(tui_obj_t * obj);
/*------------------------
 *  object����set
 *------------------------*/
void tui_obj_set_parent(tui_obj_t * obj, tui_obj_t * parent);
void tui_obj_set_typename(tui_obj_t * obj, const char *typename);
void tui_obj_set_id(tui_obj_t * obj, uint32_t id);
void tui_obj_set_hidden(tui_obj_t * obj, bool able);
void tui_obj_set_x(tui_obj_t * obj, tui_coord_t x);
void tui_obj_set_y(tui_obj_t * obj, tui_coord_t y);
void tui_obj_set_width(tui_obj_t * obj, tui_coord_t w);
void tui_obj_set_height(tui_obj_t * obj, tui_coord_t h);
void tui_obj_set_click(tui_obj_t * obj, bool able);
void tui_obj_set_ext_click_area(tui_obj_t * obj, tui_coord_t left, tui_coord_t right, tui_coord_t top, tui_coord_t bottom);
void tui_obj_set_top(tui_obj_t * obj, bool able);
void tui_obj_set_drag_dir(tui_obj_t * obj, tui_drag_dir_e drag_dir);
void tui_obj_set_drag_throw(tui_obj_t * obj, bool able);
void tui_obj_set_border_radius(tui_obj_t * obj, int16_t radius);
void tui_obj_set_border_color(tui_obj_t * obj, uint32_t color);
void tui_obj_set_border_width(tui_obj_t * obj, uint32_t width);
void tui_obj_set_border_side(tui_obj_t *button, tui_border_side_e side);
void tui_obj_set_bg_color(tui_obj_t * obj, uint32_t color);
void tui_obj_set_glue_obj(tui_obj_t * obj, bool able);
void tui_obj_set_alpha(tui_obj_t * obj, uint8_t alpha);
void tui_obj_set_align(tui_obj_t * obj, const tui_obj_t * base, tui_align_e align, tui_coord_t x_ofs, tui_coord_t y_ofs);
/*------------------------
 *  object����get
 *------------------------*/
tui_obj_t * tui_obj_get_parent(const tui_obj_t * obj);
const char * tui_obj_get_typename(tui_obj_t * obj);
uint32_t tui_obj_get_id(tui_obj_t * obj);
bool tui_obj_get_hidden(tui_obj_t * obj);
tui_coord_t tui_obj_get_x(tui_obj_t * obj);
tui_coord_t tui_obj_get_y(tui_obj_t * obj);
tui_coord_t tui_obj_get_width(tui_obj_t * obj);
tui_coord_t tui_obj_get_height(tui_obj_t * obj);
tui_obj_t * tui_obj_get_child(const tui_obj_t * obj, const tui_obj_t * child);
uint32_t tui_get_obj_num(tui_obj_t * parent);
tui_obj_t * tui_get_obj_from_id(tui_obj_t * parent, uint32_t obj_id);
tui_obj_t * tui_search_obj_from_id(uint32_t obj_id);
void tui_obj_get_coords(const tui_obj_t * obj, tui_area_t * cords_p);
/*------------------------
 *  object���󶯻�
 *------------------------*/
typedef void(*tui_object_anim_cb_t)(tui_obj_t * obj);
typedef void(*tui_object_anim_value_cb_t)(tui_obj_t * obj, int32_t value);
void tui_obj_anim_stop(tui_obj_t * obj);
void tui_obj_anim_fade_in(tui_obj_t * obj, uint32_t need_time_ms, tui_object_anim_cb_t end_cb);
void tui_obj_anim_fade_out(tui_obj_t * obj, uint32_t need_time_ms, tui_object_anim_cb_t end_cb);
void tui_obj_anim_mov_x(tui_obj_t * obj, uint32_t need_time_ms, tui_coord_t start_x, tui_coord_t end_x, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_obj_anim_mov_y(tui_obj_t * obj, uint32_t need_time_ms, tui_coord_t start_y, tui_coord_t end_y, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_obj_anim_set_width(tui_obj_t * obj, uint32_t need_time_ms, tui_coord_t start_width, tui_coord_t end_width, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_obj_anim_set_height(tui_obj_t * obj, uint32_t need_time_ms, tui_coord_t start_height, tui_coord_t end_height, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_obj_anim_set_vaule(tui_obj_t * obj, uint32_t need_time_ms, int32_t start_value, int32_t end_value, tui_anim_path_e path_type, tui_object_anim_value_cb_t value_cb, tui_object_anim_cb_t end_cb);
void tui_screen_load_anim(tui_obj_t * new_scr, tui_obj_t * old_scr, tui_scr_load_anim_e anim_type, uint32_t need_time_ms, bool auto_del_old_scr, tui_object_anim_cb_t end_cb);
void tui_screen_load_anim_in_ext(tui_obj_t * new_scr, tui_obj_t * old_scr, tui_point_t anim_start_pt, uint32_t need_time_ms, bool auto_del_old_scr, tui_object_anim_cb_t end_cb);
void tui_screen_load_anim_out_ext(tui_obj_t * new_scr, tui_obj_t * old_scr, tui_point_t anim_start_pt, uint32_t need_time_ms, bool auto_del_old_scr, tui_object_anim_cb_t end_cb);

/*------------------------
 *  view��ͼ����
 *------------------------*/
tui_obj_t * tui_view_create(const char *layout_view_path, tui_map_cb_t map_cb[]);
void tui_view_reg_func(char *component_reg_cb_map[]);

/*------------------------
 *  container����
 *------------------------*/
typedef void (*tui_container_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
		/* ������� */
		void *attri_com;
        /* �����ص����������ص�ǰ�¼� */
        tui_container_cb_t cb;

        uint32_t bg_color;                      /* �ⲿ���ã������ı�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
} tui_container_attri_t;
tui_obj_t * tui_container_create(tui_obj_t * par);
int tui_container_set_attri(tui_obj_t *container, tui_container_attri_t *attri);
int tui_container_get_attri(tui_obj_t *container, tui_container_attri_t *attri);
int tui_container_set_cb(tui_obj_t *container, tui_container_cb_t cb);

/*------------------------
 *  pageҳ
 *------------------------*/
typedef void (*tui_page_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ҳ�ص����������ص�ǰ�¼� */
        tui_page_cb_t cb;

        uint32_t bg_color;                      /* �ⲿ���ã�ҳ����ı�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        tui_size_t window_size;                 /* �ⲿ���ã�ҳ����Ĵ��ڵĴ�С */
        tui_point_t window_pt;                  /* �ⲿ���ã�ҳ����Ĵ���λ�� */
        tui_scrollbar_mode_e mode;              /* �ⲿ���ã�ҳ����Ĺ���ģʽ���� */
        bool edge_arc_able;                     /* �ⲿ���ã�ҳ�����Ե�������� */
} tui_page_attri_t;
tui_obj_t * tui_page_create(tui_obj_t * par);
int tui_page_set_attri(tui_obj_t *page, tui_page_attri_t *attri);
int tui_page_get_attri(tui_obj_t *page, tui_page_attri_t *attri);
tui_obj_t * tui_page_get_window_obj(const tui_obj_t *page);
void tui_page_set_scrollbar_mode(tui_obj_t * page, tui_scrollbar_mode_e page_bar_mode);
void tui_page_set_edge_arc(tui_obj_t * page, bool able);

/*------------------------
 *  excel���
 *------------------------*/
typedef void(*tui_excel_cb_t)(tui_obj_t *obj, tui_event_e event, uint32_t column, uint32_t row);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ���ص����������ص�Ԫ��ǰ�¼� */
        tui_excel_cb_t cb;

        uint32_t bg_color;                      /* �ⲿ���ã��������ı�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t border_color;                  /* �ⲿ���ã��������ı߿���ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        tui_point_t window_pt;                  /* �ⲿ���ã��������Ĵ���λ�� */
        tui_scrollbar_mode_e mode;              /* �ⲿ���ã��������Ĺ���ģʽ���� */
        bool edge_arc_able;                     /* �ⲿ���ã���񵽴��Ե�������� */
        uint32_t rows;                          /* �ⲿ���ã��������� */
        uint32_t columns;                       /* �ⲿ���ã��������� */
        uint32_t cell_w;                        /* �ⲿ���ã����ĵ�Ԫ��� */
        uint32_t cell_h;                        /* �ⲿ���ã����ĵ�Ԫ��� */
        bool input_able;                        /* �ⲿ���ã�֧�ֵ�Ԫ���ַ����� */
        int32_t fnt_size;                       /* �ⲿ���ã�����Ĭ�������С */
        uint32_t fnt_color;                     /* �ⲿ���ã�����Ĭ���������ɫ ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B��*/

        /* �������Ķ��󼯺ϣ����ڲ�ʹ�� */
        uint32_t *cells;
        /* �������İ��������ڲ�ʹ�� */
        bool pressed;
} tui_excel_attri_t;
tui_obj_t * tui_excel_create(tui_obj_t * par);
int tui_excel_set_attri(tui_obj_t *excel, tui_excel_attri_t *attri);
int tui_excel_get_attri(tui_obj_t *excel, tui_excel_attri_t *attri);
tui_obj_t * tui_excel_get_window_obj(const tui_obj_t *excel);
void tui_excel_set_scrollbar_mode(tui_obj_t * excel, tui_scrollbar_mode_e excel_bar_mode);
void tui_excel_set_edge_arc(tui_obj_t * excel, bool able);
int tui_excel_set_cell_text(tui_obj_t *excel, uint32_t row, uint32_t column, const char* txt,
        uint16_t font_size, uint32_t font_color, tui_label_align_e align,
        tui_label_long_mode_e mode, uint32_t bg_color);

/*------------------------
 *  label��ǩ
 *------------------------*/
typedef void (*tui_label_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ���λص����������ص�ǰ�¼� */
        tui_label_cb_t cb;

        int32_t fnt_size;                       /* �ⲿ���ã���ǩ�����С */
        char* txt;                              /* �ⲿ���ã���ǩ���ı���Ϣ */
        uint32_t fnt_color;                     /* �ⲿ���ã���ǩ�������ɫ ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B��*/
        tui_label_long_mode_e mode;             /* �ⲿ���ã���ǩ��ʾģʽ�������й�����ʾ�� */
        tui_label_align_e align;                /* �ⲿ���ã���ǩ���뷽ʽ */
        bool input_able;                        /* �ⲿ���ã�֧�ֱ�ǩ�ַ����� */
        bool ttf_font;                          /* �ⲿ���ã�֧��TTF���� */
        uint32_t border_color;                  /* �ⲿ���ã���ǩ�ı߿���ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
} tui_label_attri_t;
tui_obj_t * tui_label_create(tui_obj_t * par);
int tui_label_set_attri(tui_obj_t *label, tui_label_attri_t *attri);
int tui_label_get_attri(tui_obj_t *label, tui_label_attri_t *attri);
int tui_label_set_txt(tui_obj_t *label, const char *txt);
void tui_label_set_txt_color(tui_obj_t *label, uint32_t color);
void tui_label_set_recolor(tui_obj_t * label, bool en);
void tui_label_set_long_mode(tui_obj_t * label, tui_label_long_mode_e long_mode);
void tui_label_set_align(tui_obj_t * label, tui_label_align_e align);
void tui_label_set_align_mid(tui_obj_t * label, bool able);
void tui_label_set_align_bottom(tui_obj_t * label, bool able);
void tui_label_set_input_able(tui_obj_t * label, bool able);

/*------------------------
 *  arc����
 *------------------------*/
/*       .0
 *
 *
 *.270           .90
 *
 *
 *       .180
 */
typedef void (*tui_arc_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ���λص����������ص�ǰ�¼� */
        tui_arc_cb_t cb;
        /* ���ڲ�ʹ�� */
        tui_timer_t * arc_loading;
        /* ���ڲ�ʹ�� */
        tui_style_t arc_fg_style;

        int16_t start_angle;                    /* �ⲿ���ã����εĿ�ʼ�Ƕ� */
        int16_t end_angle;                      /* �ⲿ���ã����εĽ����Ƕ� */
        int16_t bg_start_angle;                 /* �ⲿ���ã����α����Ŀ�ʼ�Ƕ� */
        int16_t bg_end_angle;                   /* �ⲿ���ã����α����Ľ����Ƕ� */
        int16_t line_width;                     /* �ⲿ���ã����ε��߿� */
        uint32_t bg_color;                      /* �ⲿ���ã����εĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t fg_color;                      /* �ⲿ���ã����ε�ǰ��ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        bool is_rounded;                        /* �ⲿ���ã��Ƿ��ζ�Բ������ */
} tui_arc_attri_t;
tui_obj_t * tui_arc_create(tui_obj_t * par);
int tui_arc_set_attri(tui_obj_t *arc, tui_arc_attri_t *attri);
int tui_arc_get_attri(tui_obj_t *arc, tui_arc_attri_t *attri);
void tui_arc_set_bg_angles(tui_obj_t * arc, uint16_t start, uint16_t end);
void tui_arc_set_angles(tui_obj_t * arc, uint16_t start, uint16_t end);
void tui_arc_set_rounded(tui_obj_t * arc, bool is_rounded);
void tui_arc_set_anim_loading(tui_obj_t * arc, uint32_t lap_need_time_ms, bool is_loading);
tui_point_t tui_arc_get_circle_point(int angle, int radius, tui_point_t pt0);

/*------------------------
 *  bar_progress������
 *------------------------*/
typedef void (*tui_bar_progress_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �������ص����������ص�ǰ�¼� */
        tui_bar_progress_cb_t cb;
        /* ���ڲ�ʹ�� */
        tui_style_t fg_style;

        int16_t value;                          /* �ⲿ���ã���������ֵ����Χ��0~100 */
        uint32_t bg_color;                      /* �ⲿ���ã��������ĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t fg_color;                      /* �ⲿ���ã���������ǰ��ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
} tui_bar_progress_attri_t;
tui_obj_t * tui_bar_progress_create(tui_obj_t * par);
int tui_bar_progress_set_attri(tui_obj_t *bar_progress, tui_bar_progress_attri_t *attri);
int tui_bar_progress_get_attri(tui_obj_t *bar_progress, tui_bar_progress_attri_t *attri);
int16_t tui_bar_progress_get_value(tui_obj_t *bar_progress);
void tui_bar_progress_set_value(tui_obj_t *bar_progress, int16_t vaule);

/*------------------------
 *  bar_slider����
 *------------------------*/
typedef void (*tui_bar_slider_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t value);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ���������ص����������ص�ǰֵ */
        tui_bar_slider_cb_t cb;
		tui_obj_t *bg_img_obj;
		tui_obj_t *fg_img_obj;
		tui_obj_t *knob_img_obj;
		bool is_img;
		bool is_hor;
        /* ���ڲ�ʹ�� */
        tui_style_t knob_style;
        /* ���ڲ�ʹ�� */
        tui_style_t fg_style;

        int16_t value;                          /* �ⲿ���ã�������ֵ����Χ��0~1000 */
        uint32_t bg_color;                      /* �ⲿ���ã������ĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t fg_color;                      /* �ⲿ���ã�������ǰ��ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t knob_color;                    /* �ⲿ���ã�����Ŀ�ťɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */

		char *bg_img_path;                   /* �ⲿ���ã������ĵ�ɫͼƬ */
		char *fg_img_path;                   /* �ⲿ���ã�������ǰ��ɫͼƬ */
		char *knob_img_path;                 /* �ⲿ���ã�����Ŀ�ťͼƬ */
} tui_bar_slider_attri_t;
tui_obj_t * tui_bar_slider_create(tui_obj_t * par);
tui_obj_t * tui_bar_slider_create_ext(tui_obj_t * par, bool is_img);
int tui_bar_slider_set_attri(tui_obj_t *bar_slider, tui_bar_slider_attri_t *attri);
int tui_bar_slider_get_attri(tui_obj_t *bar_slider, tui_bar_slider_attri_t *attri);
void tui_bar_slider_set_knob_disable_move(tui_obj_t *bar_slider);
int16_t tui_bar_slider_get_value(tui_obj_t *bar_slider);
void tui_bar_slider_set_value(tui_obj_t *bar_slider, int16_t vaule);

/*------------------------
 *  button����
 *------------------------*/
typedef void (*tui_button_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��������ص����������ذ�ť״̬�¼� */
        tui_button_cb_t cb;
        /* ���ڲ�ʹ�� */
        bool pressed;

        uint32_t bg_color;                      /* �ⲿ���ã������ı�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t border_color;                  /* �ⲿ���ã������ı߿���ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t border_width;                  /* �ⲿ���ã������ı߿��߿�� */
} tui_button_attri_t;
tui_obj_t * tui_button_create(tui_obj_t * par);
int tui_button_set_attri(tui_obj_t *button, tui_button_attri_t *attri);
int tui_button_get_attri(tui_obj_t *button, tui_button_attri_t *attri);
void tui_button_set_shadow(tui_obj_t *button, bool able);
void tui_button_set_click_zoom(tui_obj_t *button, bool able);

/*------------------------
 *  image_btnͼƬ����
 *------------------------*/
typedef void(*tui_image_btn_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��������ص����������ص�ǰ״̬��ֵ�¼� */
        tui_image_btn_cb_t cb;
        /* ���ڲ�ʹ�� */
        bool pressed;
        /* ����ͼƬbuffer���棬���ڲ�ʹ�� */
		void *img_pressed[16];
		int8_t img_pressed_type[16];
        /* ����ͼƬbuffer���棬���ڲ�ʹ�� */
		void *img_release[16];
		int8_t img_release_type[16];

        int16_t img_index;                      /* �ⲿ���ã�ͼƬ��������ǰͼƬ������ */
        int16_t img_num;                        /* �ⲿ���ã�ͼƬ�������ж�����ͼƬ�ܺ�, ��Ҫ����16��ͼƬ */
        bool hor_mirror;                        /* �ⲿ���ã�ͼƬ������ˮƽ���� */
        bool ver_mirror;                        /* �ⲿ���ã�ͼƬ�����Ĵ�ֱ���� */
} tui_image_btn_attri_t;
tui_obj_t * tui_image_btn_create(tui_obj_t * par);
int tui_image_btn_set_attri(tui_obj_t *image_btn, tui_image_btn_attri_t *attri);
int tui_image_btn_get_attri(tui_obj_t *image_btn, tui_image_btn_attri_t *attri);
int tui_image_btn_set_image_pressed(tui_obj_t *image_btn, int16_t img_index, char *path);
int tui_image_btn_set_image_release(tui_obj_t *image_btn, int16_t img_index, char *path);
int tui_image_btn_set_cur_img_index(tui_obj_t *image_btn, int16_t img_index);
void tui_image_btn_set_hor_mirror(tui_obj_t * image_btn, bool mirror_able);
void tui_image_btn_set_ver_mirror(tui_obj_t * image_btn, bool mirror_able);
void tui_image_btn_set_zoom(tui_obj_t * image_btn, uint16_t zoom);
uint16_t tui_image_btn_get_zoom(tui_obj_t * image_btn);
void tui_image_btn_anim_zoom(tui_obj_t * image_btn, uint32_t need_time_ms, uint16_t start_zoom, uint16_t end_zoom, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);

/*------------------------
 *  imageͼƬ
 *------------------------*/
/*       .0
 *
 *
 *.270           .90
 *
 *
 *       .180
 */
typedef void(*tui_image_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �����仯���лص����������ص�ǰͼƬֵ�¼� */
        tui_image_cb_t cb;
        /* ����ͼƬbuffer���棬���ڲ�ʹ�� */
        void *img[128];
        void *img_temp;
        void *img_temp_1;
        int8_t img_type[128];
        /* ����timer�����ڲ�ʹ�� */
        tui_timer_t *timer;
        /* ����timer����ʼ����ֵ�����ڲ�ʹ�� */
        int16_t start_index;
        /* ����timer����������ֵ�����ڲ�ʹ�� */
        int16_t end_index;
        /* ����timer����ת�Ƕȣ��ڲ�ʹ�� */
        int16_t rotate_offset;
        /* ����timer����ת�����ڲ�ʹ�� */
        double rotate_way;
        /* �ڲ�ʹ�� */
        int16_t rotate_angle_temp;

        int16_t img_index;                      /* �ⲿ���ã�ͼƬ�ؼ�����ǰͼƬ������ */
        int16_t img_num;                        /* �ⲿ���ã�ͼƬ�ؼ����ж�����ͼƬ�ܺ� , ��Ҫ����128��ͼƬ*/
        int16_t zoom;                           /* �ⲿ���ã�ͼƬ�ؼ��Ŵ���Сֵ ��256���Ŵ�С��256��С������256�Ŵ�512�Ŵ�������128��Сһ��*/
        int16_t rotate_angle;                   /* �ⲿ���ã�ͼƬ�ؼ���ת�Ƕȣ���Χ0~360 */
        tui_point_t rotate_pt;                  /* �ⲿ���ã�ͼƬ�ؼ���ת���������꣬Ĭ�������ĵ� */
        bool anim_start;                        /* �ⲿ���ã�ͼƬ�ؼ�ͼƬ����Ĭ���Ƿ�ʼ��0����1*/
        int32_t anim_time;                      /* �ⲿ���ã�ͼƬ�ؼ�ͼƬ�����л���ʱ�䣬���뵥λ*/
        tui_image_circulate_e mode;             /* �ⲿ���ã�ͼƬ�ؼ�ͼƬ�����л���ģʽ�����λ�������ѭ�� */
        tui_coord_t x_offset;                   /* �ⲿ���ã�ͼƬ��ԴXƫ�� */
        tui_coord_t y_offset;                   /* �ⲿ���ã�ͼƬ��ԴYƫ�� */
        bool hor_mirror;                        /* �ⲿ���ã�ͼƬ��ˮƽ���� */
        bool ver_mirror;                        /* �ⲿ���ã�ͼƬ�Ĵ�ֱ���� */
} tui_image_attri_t;
tui_obj_t * tui_image_create(tui_obj_t * par);
int tui_image_set_attri(tui_obj_t *image, tui_image_attri_t *attri);
int tui_image_get_attri(tui_obj_t *image, tui_image_attri_t *attri);
int tui_image_set_image_src(tui_obj_t *image, int16_t img_index, char *path);
int tui_image_set_image_argb_buf(tui_obj_t *image, int16_t img_index, const void *buf, int32_t img_w, int32_t img_h);
int tui_image_set_image_rgba_buf(tui_obj_t *image, int16_t img_index, const void *buf, int32_t img_w, int32_t img_h);
int tui_image_set_cur_img_index(tui_obj_t *image, int16_t img_index);
void tui_image_set_offset_x(tui_obj_t * image, tui_coord_t x);
void tui_image_set_offset_y(tui_obj_t * image, tui_coord_t y);
int tui_image_start_anim(tui_obj_t *image, uint32_t anim_time, tui_image_circulate_e mode);
int tui_image_stop_anim(tui_obj_t *image);
int tui_image_get_anim_state(tui_obj_t *image);
void tui_image_set_zoom(tui_obj_t * image, uint16_t zoom);
void tui_image_set_size(tui_obj_t * image, uint32_t new_width, uint32_t new_height);
void tui_image_set_angle(tui_obj_t * image, int16_t angle, bool is_anima);
void tui_image_set_hor_mirror(tui_obj_t * image, bool mirror_able);
void tui_image_set_ver_mirror(tui_obj_t * image, bool mirror_able);
void tui_image_set_rotation_center_coor(tui_obj_t * image, tui_coord_t pivot_x, tui_coord_t pivot_y);
void tui_image_anim_zoom(tui_obj_t * image, uint32_t need_time_ms, uint16_t start_zoom, uint16_t end_zoom, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_image_anim_angle(tui_obj_t * image, uint32_t need_time_ms, uint16_t start_angle, uint16_t end_angle, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_image_anim_width(tui_obj_t * image, uint32_t need_time_ms, uint16_t start_width, uint16_t end_width, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);
void tui_image_anim_height(tui_obj_t * image, uint32_t need_time_ms, uint16_t start_height, uint16_t end_height, tui_anim_path_e path_type, tui_object_anim_cb_t end_cb);

/*------------------------
 *  animation����
 *------------------------*/
typedef void(*tui_animation_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        char path[48];  /* ·����Ҫ����48���ַ� */
        int x;
        int y;
        int ms;
} tui_anima_img_attri_t;

typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �����仯���лص����������ص�ǰͼƬֵ */
        tui_animation_cb_t cb;
        /* ����image�����ڲ�ʹ�� */
        void *img_obj;
        /* buffer���棬���ڲ�ʹ�� */
        void *img_buff[2];
        int16_t img_buff_index;
        /* ����timer�����ڲ�ʹ�� */
        tui_timer_t *timer;
        /* ����timer����ʼ����ֵ�����ڲ�ʹ�� */
        int16_t start_index;
        /* ����timer����������ֵ�����ڲ�ʹ�� */
        int16_t end_index;

        uint32_t bg_color;                      /* �ⲿ���ã����������ı�����ɫ, Ĭ����0��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        int16_t img_index;                      /* �ⲿ���ã���������ǰͼƬ������ */
        int16_t img_num;                        /* �ⲿ���ã��������ж�����ͼƬ�ܺ�, ��Ҫ����128��ͼƬ */
        tui_anima_img_attri_t anima_img[128];   /* �ⲿ���ã����������ͼƬ���ϣ� ͼƬ��Ҫ����128�� */
        bool anim_start;                        /* �ⲿ���ã�����Ĭ���Ƿ�ʼ��0����1*/
        tui_image_circulate_e mode;             /* �ⲿ���ã������л���ģʽ�����λ�������ѭ�� */
        bool hor_mirror;                        /* �ⲿ���ã�������ˮƽ���� */
        bool ver_mirror;                        /* �ⲿ���ã������Ĵ�ֱ���� */
} tui_animation_attri_t;
tui_obj_t * tui_animation_create(tui_obj_t * par);
int tui_animation_set_attri(tui_obj_t *animation, tui_animation_attri_t *attri);
int tui_animation_get_attri(tui_obj_t *animation, tui_animation_attri_t *attri);
int tui_animation_set_cur_img_index(tui_obj_t *animation, int16_t img_index);
int tui_animation_start_anim(tui_obj_t *animation, tui_image_circulate_e mode);
int tui_animation_stop_anim(tui_obj_t *animation);
void tui_animation_set_hor_mirror(tui_obj_t *animation, bool mirror_able);
void tui_animation_set_ver_mirror(tui_obj_t *animation, bool mirror_able);

/*------------------------
 *  gifͼƬ����
 *------------------------*/
typedef void(*tui_gif_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �����仯���лص����������ص�ǰgifͼƬ����ֵ */
        tui_gif_cb_t cb;

        char gif_path[128];                     /* �ⲿ���ã�gif����·�� */
        tui_image_circulate_e mode;             /* �ⲿ���ã������л���ģʽ�����λ�������ѭ�� */
} tui_gif_attri_t;
tui_obj_t * tui_gif_create(tui_obj_t * par);
int tui_gif_set_attri(tui_obj_t *gif, tui_gif_attri_t *attri);
int tui_gif_get_attri(tui_obj_t *gif, tui_gif_attri_t *attri);
int tui_gif_pause(tui_obj_t *gif);
int tui_gif_play(tui_obj_t *gif);
int tui_gif_restart(tui_obj_t *gif);
int tui_gif_set_mode(tui_obj_t *gif, tui_image_circulate_e mode);

/*------------------------
 *  line��
 *------------------------*/
typedef void (*tui_line_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �߻ص����������ص��¼� */
		tui_line_cb_t cb;
		/* ����ߣ����ڲ�ʹ�� */
		tui_point_t *point_a[2];
		/* ����ߣ����ڲ�ʹ�� */
		uint16_t point_num;
		/* ����ߣ����ڲ�ʹ�� */
		uint16_t point_index;

        uint32_t width;                         /* �ⲿ���ã��ߵĿ�� */
        uint32_t color;                         /* �ⲿ���ã��ߵ���ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        tui_point_t pts[2];                     /* �ⲿ���ã��ߵ����꣬����һ�� */
} tui_line_attri_t;
tui_obj_t * tui_line_create(tui_obj_t * par);
int tui_line_set_attri(tui_obj_t *line, tui_line_attri_t *attri);
int tui_line_get_attri(tui_obj_t *line, tui_line_attri_t *attri);
void tui_line_set_points(tui_obj_t * line, tui_point_t point_a, tui_point_t point_b);
void tui_line_set_line_width(tui_obj_t * line, uint32_t width);
void tui_line_set_line_color(tui_obj_t * line, uint32_t color);
void tui_line_set_some_points_line(tui_obj_t * line, tui_point_t *point_a, uint16_t point_num, bool is_bezier);

/*------------------------
 *  switch_btn�л�����
 *------------------------*/
typedef void (*tui_switch_btn_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t value);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��������ص����������ص�ǰ״ֵ̬ */
        tui_switch_btn_cb_t cb;
        /* ���ڲ�ʹ�� */
        tui_style_t knob_style;
        /* ���ڲ�ʹ�� */
        tui_style_t fg_style;

		bool value;                             /* �ⲿ���ã��л����ص�ֵ ��0����1*/
        uint32_t bg_color;                      /* �ⲿ���ã��л����صĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t fg_color;                      /* �ⲿ���ã��л����ص�ǰ��ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t knob_color;                    /* �ⲿ���ã��л����صİ�ťɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
} tui_switch_btn_attri_t;
tui_obj_t * tui_switch_btn_create(tui_obj_t * par);
int tui_switch_btn_set_attri(tui_obj_t *switch_btn, tui_switch_btn_attri_t *attri);
int tui_switch_btn_get_attri(tui_obj_t *switch_btn, tui_switch_btn_attri_t *attri);
int tui_switch_btn_get_vaule(tui_obj_t *switch_btn);
void tui_switch_btn_set_vaule(tui_obj_t *switch_btn, bool value);

/*------------------------
 *  dropdown�����˵�
 *------------------------*/
typedef void (*tui_dropdown_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t index);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��������ص����������ص�ǰ����ֵ */
        tui_dropdown_cb_t cb;
        /* ���ڲ�ʹ�� */
        tui_style_t bar_style;
        /* ���ڲ�ʹ�� */
        tui_style_t list_style;

        int16_t cur_index;                      /* �ⲿ���ã���ǰ�����˵�������ֵ */
        int16_t options_num;                    /* �ⲿ���ã���ǰ�����˵��ĸ��� */
        char options[210][40];                  /* �ⲿ���ã������˵����ı����� */
        uint32_t bar_color;                     /* �ⲿ���ã������˵�bar�ĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t list_color;                    /* �ⲿ���ã������˵��б�ĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t text_color;                    /* �ⲿ���ã������˵��ַ�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        int16_t text_font_size;                 /* �ⲿ���ã������˵��ַ������С */
} tui_dropdown_attri_t;
tui_obj_t * tui_dropdown_create(tui_obj_t * par);
int tui_dropdown_set_attri(tui_obj_t *dropdown, tui_dropdown_attri_t *attri);
int tui_dropdown_get_attri(tui_obj_t *dropdown, tui_dropdown_attri_t *attri);
void tui_dropdown_add_option(tui_obj_t * dropdown, const char * option, int16_t index);
void tui_dropdown_set_selected_str(tui_obj_t *dropdown, const char * options[], int16_t options_num);
char ** tui_dropdown_get_selected_str(tui_obj_t *dropdown, int16_t *options_num);
uint16_t tui_dropdown_get_selected_index(tui_obj_t *dropdown);
void tui_dropdown_set_selected_index(tui_obj_t *dropdown, int16_t index);
void tui_dropdown_set_symbol(tui_obj_t *dropdown, bool able);
void tui_dropdown_set_max_height(tui_obj_t *dropdown, tui_coord_t h);

/*------------------------
 *  textbox�ı������
 *------------------------*/
typedef void (*tui_textbox_cb_t)(tui_obj_t *obj, tui_event_e event, const char * str);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ���봥���ص����������ص�ǰ�ַ��� */
        tui_textbox_cb_t cb;

        bool pwd_able;                  /* �ⲿ���ã��ı������ģʽ���Ƿ����������� */
        char *accepted_chars;                   /* �ⲿ���ã��ı���������������ַ����ƣ� ����֧�������ַ� */
} tui_textbox_attri_t;
tui_obj_t * tui_textbox_create(tui_obj_t * par);
int tui_textbox_set_attri(tui_obj_t *textbox, tui_textbox_attri_t *attri);
int tui_textbox_get_attri(tui_obj_t *textbox, tui_textbox_attri_t *attri);
const char * tui_textbox_get_text(const tui_obj_t * textbox);
void tui_textbox_set_text(tui_obj_t * textbox, const char * txt);
void tui_textbox_set_pwd_mode(tui_obj_t * textbox, bool pwd_able);
void tui_textarea_set_accepted_chars(tui_obj_t * textbox, const char * accepted_chars);

/*------------------------
 *  checkbox��ѡ��
 *------------------------*/
typedef void(*tui_checkbox_cb_t)(tui_obj_t *obj, tui_event_e event, int32_t value);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��������ص����������ص�ǰ״ֵ̬ */
        tui_checkbox_cb_t cb;

        int32_t value;                          /* �ⲿ���ã���ѡ���ֵ��0����1 */
} tui_checkbox_attri_t;
tui_obj_t * tui_checkbox_create(tui_obj_t * par);
int tui_checkbox_set_attri(tui_obj_t *checkbox, tui_checkbox_attri_t *attri);
int tui_checkbox_get_attri(tui_obj_t *checkbox, tui_checkbox_attri_t *attri);
bool tui_checkbox_get_vaule(tui_obj_t *checkbox);
void tui_checkbox_set_vaule(tui_obj_t *checkbox, bool value);

/*------------------------
 *  list�б�
 *------------------------*/
typedef void (*tui_list_cb_t)(tui_obj_t *obj_list, tui_event_e event, int32_t index);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �б�ص����������ص�ǰĳһ���б����¼� */
        tui_list_cb_t cb;
        /* �б�����ǣ����ڲ�ʹ�� */
        bool move_flag;
        /* ѡ�񣬹��ڲ�ʹ�� */
        tui_obj_t * select_img;

        uint32_t bg_color;                      /* �ⲿ���ã��б�ı�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t cur_index;                     /* �ⲿ���ã��б�ĵ�ǰ��������ֵ */
        tui_scrollbar_mode_e mode;              /* �ⲿ���ã��б�����Ĺ���ģʽ���� */

} tui_list_attri_t;
tui_obj_t * tui_list_create(tui_obj_t * par);
int tui_list_set_attri(tui_obj_t *list, tui_list_attri_t *attri);
int tui_list_get_attri(tui_obj_t *list, tui_list_attri_t *attri);
int tui_list_add_btn(tui_obj_t * btn);
bool tui_list_remove_index(const tui_obj_t * list, uint16_t index);
bool tui_list_remove_btn(tui_obj_t * btn);
bool tui_list_remove_all(const tui_obj_t * list);
void tui_list_set_focus_btn(tui_obj_t * btn);
void tui_list_set_focus_index(tui_obj_t * list, uint16_t index);
tui_obj_t * tui_list_get_focus_btn(const tui_obj_t * list);
int32_t tui_list_get_index_from_btn(const tui_obj_t * btn);
const tui_obj_t * tui_list_get_btn_from_index(const tui_obj_t * list, int32_t index);
uint16_t tui_list_get_size(const tui_obj_t * list);
void tui_list_set_scrollbar_mode(tui_obj_t * list, tui_scrollbar_mode_e mode);

/*------------------------
 *  multi_screen�����ؼ�
 *------------------------*/
typedef void (*tui_multi_screen_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t index);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��Ļ���������ص����������ص�ǰ��Ļ����ֵ */
        tui_multi_screen_cb_t cb;
        /* ����timer�����ڲ�ʹ�� */
        tui_timer_t *timer;
        /* ����timer����ʼ���꣬���ڲ�ʹ�� */
        int32_t start_x;
        /* ����timer���������꣬���ڲ�ʹ�� */
        int32_t end_x;
        /* ����timer�����������ڲ�ʹ�� */
        int32_t cnt;

        int32_t screen_w;                       /* �ⲿ���ã������ؼ��Ŀ�, ����Ļ�Ŀ���һ�� */
        int32_t screen_h;                       /* �ⲿ���ã������ؼ��ĸ� */
        uint8_t screen_num;                     /* �ⲿ���ã������ؼ��������� */
        uint8_t cur_screen_index;               /* �ⲿ���ã������ؼ��ĵ�ǰ�������� */
} tui_multi_screen_attri_t;
tui_obj_t * tui_multi_screen_create(tui_obj_t * par);
int tui_multi_screen_set_attri(tui_obj_t *multi_screen, tui_multi_screen_attri_t *attri);
int tui_multi_screen_get_attri(tui_obj_t *multi_screen, tui_multi_screen_attri_t *attri);
int tui_multi_screen_set_cur_screen_index(tui_obj_t *multi_screen, uint8_t cur_screen_index, bool is_anima);
uint8_t tui_multi_screen_get_cur_screen_index(tui_obj_t *multi_screen);

/*------------------------
 *  canvas����
 *------------------------*/
typedef void (*tui_canvas_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �����ص����������ص�ǰ�¼� */
        tui_canvas_cb_t cb;
        /* ������ARGB buffer�����ڲ�ʹ�� */
        uint32_t *argb_buf;

        uint32_t bg_color;                      /* �ⲿ���ã������ı�����ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
} tui_canvas_attri_t;
tui_obj_t * tui_canvas_create(tui_obj_t * par);
int tui_canvas_set_attri(tui_obj_t *canvas, tui_canvas_attri_t *attri);
int tui_canvas_get_attri(tui_obj_t *canvas, tui_canvas_attri_t *attri);
void tui_canvas_draw_pixel(tui_obj_t * canvas, int32_t x, int32_t y, uint32_t color);
void tui_canvas_draw_line(tui_obj_t * canvas, const tui_point_t points[], uint32_t point_cnt, uint16_t width, uint32_t line_color);
void tui_canvas_draw_rect(tui_obj_t * canvas, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t fill_color);
void tui_canvas_draw_polygon(tui_obj_t * canvas, const tui_point_t points[], uint32_t point_cnt, uint32_t fill_color);
void tui_canvas_draw_arc(tui_obj_t * canvas, int32_t x, int32_t y, int32_t r, int32_t start_angle, int32_t end_angle, uint16_t width, uint32_t line_color);
void tui_canvas_draw_text(tui_obj_t * canvas, int32_t x, int32_t y, const char * txt, uint16_t fnt_size, uint32_t color);
void tui_canvas_fill_bg(tui_obj_t * canvas, uint32_t color);
void tui_canvas_copy_buf(tui_obj_t * canvas, const void * buf, tui_coord_t canvas_x, tui_coord_t canvas_y, tui_coord_t buf_w, tui_coord_t buf_h);
void tui_canvas_draw_img(tui_obj_t * canvas, tui_coord_t x, tui_coord_t y, const char * path);
const uint32_t * tui_canvas_get_argb_buffer(tui_obj_t * canvas, uint32_t * out_width, uint32_t * out_height);

/*------------------------
 *  qrcode��ά��
 *------------------------*/
typedef void(*tui_qrcode_cb_t)(tui_obj_t *obj, tui_event_e event, const char * str);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* ��ά�봥���ص����������ص�ǰ��ά���ַ��� */
        tui_qrcode_cb_t cb;
        /* ������buffer�����ڲ�ʹ�� */
        uint32_t *cbuf;

        uint32_t bg_color;                      /* �ⲿ���ã���ά��ĵ�ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        uint32_t fg_color;                      /* �ⲿ���ã���ά���ǰ��ɫ��0xFF112233  FF��͸���ȣ�11��R��22��G��33��B�� */
        char *qrcode_chars;                     /* �ⲿ���ã���ά���ַ����� */
} tui_qrcode_attri_t;
tui_obj_t * tui_qrcode_create(tui_obj_t * par);
int tui_qrcode_set_attri(tui_obj_t *qrcode, tui_qrcode_attri_t *attri);
int tui_qrcode_get_attri(tui_obj_t *qrcode, tui_qrcode_attri_t *attri);
const char * tui_qrcode_get_text(const tui_obj_t * qrcode);
void tui_qrcode_set_text(tui_obj_t * qrcode, const char * qrcode_chars);

/*------------------------
 *  sound����
 *------------------------*/
void tui_sound_enable(bool able);
typedef void (*tui_sound_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* ͨ������ */
        tui_object_attri_t obj;
        /* �����ص����������ص�ǰ�¼� */
        tui_sound_cb_t cb;
        /* ����buffer���棬���ڲ�ʹ�� */
        int16_t *sound;
        /* ����buffer���棬���ڲ�ʹ�� */
        int32_t sound_len;
        /* �������������ڲ�ʹ�� */
        int32_t play_cnt;
        /* ������������ڲ�ʹ�� */
        tui_obj_t * me;

        int32_t play_mode;                      /* �ⲿ���ã������ؼ�����ģʽ�� 0�ǲ���һ�Σ�1��ѭ������  */
} tui_sound_attri_t;
tui_obj_t * tui_sound_create(tui_obj_t * par);
int tui_sound_set_attri(tui_obj_t *sound, tui_sound_attri_t *attri);
int tui_sound_get_attri(tui_obj_t *sound, tui_sound_attri_t *attri);
int tui_sound_set_sound_src(tui_obj_t *sound, const char *path);
int tui_sound_set_sound_src_one_hz(tui_obj_t *sound, const char *gb2312_one_zh);
int tui_sound_play(tui_obj_t *sound);
int tui_sound_stop(tui_obj_t *sound);
bool tui_sound_is_play(tui_obj_t *sound);


#endif /* __TUI_H__ */

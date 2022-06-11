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
        int sec;                                /* 秒 - [0,59] */
        int min;                                /* 分 - [0,59] */
        int hour;                               /* 时 - [0,23] */
        int mday;                               /* 日 - [1,31] */
        int mon;                                /* 月 - [0,11] */
        int year;                               /* 年  */
        int wday;                               /* 星期，0是星期日 - [0,6] */
} tui_time_t;

typedef enum tag_obj_event {
        TUI_EVENT_PRESSED             = 0,      /* 对象触摸按下 */
        TUI_EVENT_PRESSING            = 1,      /* 对象触摸持续按下 */
        TUI_EVENT_PRESS_LOST          = 2,      /* 对象触摸按下丢失 */
        TUI_EVENT_SHORT_CLICKED       = 3,      /* 对象短时间按下 */
        TUI_EVENT_LONG_PRESSED        = 4,      /* 对象长时间按下 */
        TUI_EVENT_LONG_PRESSED_REPEAT = 5,      /* 对象重复长时间按下 */
        TUI_EVENT_CLICKED             = 6,      /* 对象点击按下 */
        TUI_EVENT_RELEASED            = 7,      /* 对象触摸抬起 */
        TUI_EVENT_DRAG_BEGIN          = 8,      /* 对象触摸拖拽开始 */
        TUI_EVENT_DRAG_END            = 9,      /* 对象触摸拖拽结束 */
        TUI_EVENT_DRAG_THROW_BEGIN    = 10,     /* 对象触摸抛拽开始 */
        TUI_EVENT_GESTURE             = 11,     /* 对象的手势事件 */
        TUI_EVENT_KEY                 = 12,     /* 对象的键盘事件 */
        TUI_EVENT_FOCUSED             = 13,     /* 对象焦点状态事件 */
        TUI_EVENT_DEFOCUSED           = 14,     /* 对象失去焦点状态事件 */
        TUI_EVENT_LEAVE               = 15,     /* 对象离开事件 */
        TUI_EVENT_VALUE_CHANGED       = 16,     /* 对象的值发生改变事件 */
        TUI_EVENT_INSERT              = 17,     /* 对象插入事件 */
        TUI_EVENT_REFRESH             = 18,     /* 对象刷新事件 */
        TUI_EVENT_APPLY               = 19,     /* 对象应用事件 */
        TUI_EVENT_CANCEL              = 20,     /* 对象退出事件 */
        TUI_EVENT_DELETE              = 21,     /* 对象删除事件 */
        TUI_EVENT_LAST                = 22,     /* 保留事件 */
        TUI_EVENT_USER_DEF            = 23,     /* 保留事件 */
        TUI_EVENT_OBJECT_INIT         = 24,     /* 对象创建初始化事件 */
        TUI_EVENT_SOUND_PLAY_END      = 25,     /* 声音对象播放结束事件 */
        TUI_EVENT_IMAGE_ANIMATION_END = 26,     /* 对象动画播放结束事件 */
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
        TUI_TIMER_PRIO_LOWEST,                  /* 最低优先级 */
        TUI_TIMER_PRIO_LOW,                     /* 低优先级 */
        TUI_TIMER_PRIO_MID,                     /* 中等优先级 */
        TUI_TIMER_PRIO_HIGH,                    /* 高优先级 */
        TUI_TIMER_PRIO_HIGHEST,                 /* 最高优先级 */
        TUI_TIMER_PRIO_NUM,
} tui_timer_prio_e;

typedef enum tag_tui_align {
        TUI_ALIGN_CENTER = 0,                   /* 居中对齐 */
        TUI_ALIGN_IN_TOP_LEFT,                  /* 在对象内部顶端靠左对齐 */
        TUI_ALIGN_IN_TOP_MID,                   /* 在对象内部顶端中间对齐 */
        TUI_ALIGN_IN_TOP_RIGHT,                 /* 在对象内部顶端靠右对齐 */
        TUI_ALIGN_IN_BOTTOM_LEFT,               /* 在对象内部底端靠左对齐 */
        TUI_ALIGN_IN_BOTTOM_MID,                /* 在对象内部底端靠间对齐 */
        TUI_ALIGN_IN_BOTTOM_RIGHT,              /* 在对象内部底端靠右对齐 */
        TUI_ALIGN_IN_LEFT_MID,                  /* 在对象内部靠左居中对齐 */
        TUI_ALIGN_IN_RIGHT_MID,                 /* 在对象内部靠右居中对齐 */
        TUI_ALIGN_OUT_TOP_LEFT,                 /* 在对象外部顶端靠左对齐 */
        TUI_ALIGN_OUT_TOP_MID,                  /* 在对象外部顶端中间对齐 */
        TUI_ALIGN_OUT_TOP_RIGHT,                /* 在对象外部顶端靠右对齐 */
        TUI_ALIGN_OUT_BOTTOM_LEFT,              /* 在对象外部底端靠左对齐 */
        TUI_ALIGN_OUT_BOTTOM_MID,               /* 在对象外部底端靠间对齐 */
        TUI_ALIGN_OUT_BOTTOM_RIGHT,             /* 在对象外部底端靠右对齐 */
        TUI_ALIGN_OUT_LEFT_TOP,                 /* 在对象外部靠左顶部对齐 */
        TUI_ALIGN_OUT_LEFT_MID,                 /* 在对象外部靠左居中对齐 */
        TUI_ALIGN_OUT_LEFT_BOTTOM,              /* 在对象外部靠左底部对齐 */
        TUI_ALIGN_OUT_RIGHT_TOP,                /* 在对象外部靠右顶部对齐 */
        TUI_ALIGN_OUT_RIGHT_MID,                /* 在对象外部靠右居中对齐 */
        TUI_ALIGN_OUT_RIGHT_BOTTOM,             /* 在对象外部靠右底部对齐 */
} tui_align_e;

typedef enum tag_tui_label_long_mode {
        TUI_LABEL_LONG_EXPAND = 0,              /* 大小与文本一致 */
        TUI_LABEL_LONG_BREAK,                   /* 保持宽度，将文本过长的换行，增加高度 */
        TUI_LABEL_LONG_DOT,                     /* 过长则在结尾写”...” */
        TUI_LABEL_LONG_SROLL,                   /* 扩大大小并且文本在滚动 */
        TUI_LABEL_LONG_SROLL_CIRC,              /* 循环滚动 */
        TUI_LABEL_LONG_CROP,                    /* 裁剪文本 */
} tui_label_long_mode_e;

typedef enum tag_tui_label_align_t {
        TUI_LABEL_ALIGN_LEFT = 0,               /* 左对齐 */
        TUI_LABEL_ALIGN_CENTER,                 /* 中心对齐 */
        TUI_LABEL_ALIGN_RIGHT,                  /* 右对齐 */
        TUI_LABEL_ALIGN_AUTO,                   /* 视文本方向而定 */
} tui_label_align_e;

typedef enum tag_tui_border_side {
        TUI_BORDER_SIDE_NONE    = 0x00,         /* 无边框 */
        TUI_BORDER_SIDE_BOTTOM  = 0x01,         /* 下边边框 */
        TUI_BORDER_SIDE_TOP     = 0x02,         /* 上边边框 */
        TUI_BORDER_SIDE_LEFT    = 0x04,         /* 左边边框 */
        TUI_BORDER_SIDE_RIGHT   = 0x08,         /* 右边边框 */
        TUI_BORDER_SIDE_FULL    = 0x0F,         /* 全边边框 */
} tui_border_side_e;

typedef enum tag_tui_drag_dir {
        TUI_DRAG_NONE_DIR       = 0x0,          /* 不能拖动 */
        TUI_DRAG_DIR_HOR        = 0x1,          /* 只能水平拖动 */
        TUI_DRAG_DIR_VER        = 0x2,          /* 只能垂直拖动 */
        TUI_DRAG_DIR_BOTH       = 0x3,          /* 任意拖动 */
        TUI_DRAG_DIR_ONE        = 0x4,          /* 第一次拖动的方向拖动 */
} tui_drag_dir_e;

typedef enum tag_tui_scrollbar_mode {
        TUI_SCROLLBAR_MODE_OFF  = 0x0,          /* 不显示 */
        TUI_SCROLLBAR_MODE_ON   = 0x1,          /* 一直显示 */
        TUI_SCROLLBAR_MODE_DRAG = 0x2,          /* 拖拽的时候显示 */
        TUI_SCROLLBAR_MODE_AUTO = 0x3,          /* 自动 */
        TUI_SCROLLBAR_MODE_HIDE = 0x4,          /* 暂时隐藏 */
} tui_scrollbar_mode_e;

typedef enum tag_tui_image_circulate {
        TUI_IMAGE_ONCE = 0,                     /* 运行一次动画 */
        TUI_IMAGE_LOOP,                         /* 循环运行动画 */
} tui_image_circulate_e;

typedef enum tag_tui_scr_load_anim {
        TUI_SCR_LOAD_ANIM_NONE = 0,             /* 无动画 */
        TUI_SCR_LOAD_ANIM_OVER_LEFT,            /* 单向左移动 */
        TUI_SCR_LOAD_ANIM_OVER_RIGHT,           /* 单向右移动 */
        TUI_SCR_LOAD_ANIM_OVER_TOP,             /* 单向上移动 */
        TUI_SCR_LOAD_ANIM_OVER_BOTTOM,          /* 单向下移动 */
        TUI_SCR_LOAD_ANIM_MOVE_LEFT,            /* 双向左移动 */
        TUI_SCR_LOAD_ANIM_MOVE_RIGHT,           /* 双向右移动 */
        TUI_SCR_LOAD_ANIM_MOVE_TOP,             /* 双向上移动 */
        TUI_SCR_LOAD_ANIM_MOVE_BOTTOM,          /* 双向下移动 */
        TUI_SCR_LOAD_ANIM_FADE_ON,              /* 双淡入淡出 */
} tui_scr_load_anim_e;

typedef enum tag_tui_anim_path {
        TUI_ANIM_PATH_LINEAR = 0,               /* 线性效果 */
        TUI_ANIM_PATH_EASE_IN,                  /* 加速效果 */
        TUI_ANIM_PATH_EASE_OUT,                 /* 减速效果 */
        TUI_ANIM_PATH_EASE_IN_OUT,              /* 加速减速效果 */
        TUI_ANIM_PATH_OVERSHOOT,                /* 越界回来效果 */
        TUI_ANIM_PATH_BOUNCE,                   /* 反弹来回效果 */
        TUI_ANIM_PATH_STEP,                     /* 时间到了直接显示 */
} tui_anim_path_e;

/*------------------------
 *  TUI生命周期，初始化、运行、销毁
 *------------------------*/
void tui_start_init(const char * res_path);
void tui_run_loop(void);
void tui_end_uninit(void);

/*------------------------
 *  system message系统消息
 *------------------------*/
typedef int32_t (*tui_sys_msg_cb_t)(uint32_t cmd, void *param0, void *param1);
int32_t tui_sys_msg_reg(tui_sys_msg_cb_t cb);
int32_t tui_sys_msg_unreg(tui_sys_msg_cb_t cb);
int32_t tui_sys_msg_send(uint32_t cmd, void *param0, void *param1);
int32_t tui_sys_msg_send_dly(uint32_t cmd, uint32_t dly_ms, void *param0, void *param1);

/*------------------------
 *  timer定时器
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
 *  获取res.disk工程配置
 *------------------------*/
int tui_config_get_screen_resolution(int *screen_hor_res, int *screen_ver_res);
const char * tui_config_get_version(void);
int tui_config_password_compare(const char * password);
int tui_config_get_serial_port(int *baudrate, int *bytesize, int *parity, int *stopbits);
int tui_config_get_screen_rotate_angle(void);

/*------------------------
 *  language多国语言
 *------------------------*/
int tui_get_language_num(void);
void tui_set_language(int16_t lang_index);
const char * tui_get_language_utf8_string(const char *str_id);

/*------------------------
 *  获取res.disk下V盘文件
 *------------------------*/
void *tui_alloc_buffer_from_fs(const char *path, int *get_buf_len);
int tui_free_buffer_from_fs(void *buf);

/*------------------------
 *  gb2312和utf8码的转换
 *------------------------*/
int tui_utf8_to_gb2312(char *gb2312_str, int len_gb2312, char *utf8_str, int len_utf8);
int tui_gb2312_to_utf8(char *utf8_str, int len_utf8, char *gb2312_str, int len_gb2312);
int tui_gb2312_to_utf8_need_size(char *gb2312_str);

/*------------------------
 *  获取系统运行时间、RTC日期、休眠
 *------------------------*/
uint32_t tui_get_system_run_milliseconds(void);
tui_time_t tui_get_localtime(void);
void tui_set_localtime(tui_time_t *lt);
void tui_sleep(uint32_t ms);

/*------------------------
 *  串口接口，兼容PC驱动模拟
 *------------------------*/
typedef int(*tui_serial_port_read_cb_t)(const char *read_buff, int buf_len);
int tui_serial_port_open(char *com_name, int baudrate, int bytesize, int parity, int stopbits, tui_serial_port_read_cb_t read_cb);
void tui_serial_port_close(void);
int tui_serial_port_write(char *write_buff, int buf_len);

/*------------------------
 *  tui input获取触摸和按键值
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
 *  group按键组
 *------------------------*/
void tui_group_add_obj(tui_obj_t * obj);
void tui_group_remove_obj(tui_obj_t * obj);
void tui_group_remove_all_objs(void);
void tui_group_focus_obj(tui_obj_t * obj);
tui_obj_t * tui_group_get_focused(void);

/*------------------------
 *  调试信息
 *------------------------*/
void tui_dbg_core_information_dump(void);
void tui_pointer_run_auto_test(char *rec_path, int is_loop_run);

/*------------------------
 *  所有object对象的根节点
 *------------------------*/
tui_obj_t * tui_layer_normal(void);             /* 普通根节点对象图层 */
tui_obj_t * tui_layer_top(void);                /* 另外一个，置顶根节点对象图层 */
/*------------------------
 *  object对象属性
 *------------------------*/
typedef struct {
        /* 供内部使用style */
        tui_style_t style;

        tui_size_t size;                        /* 外部配置，对象的宽高设置 */
        tui_point_t pt;                         /* 外部配置，对象所在的位置 */
        bool hidden;                            /* 外部配置，对象是否隐藏 */
        uint32_t obj_id;                        /* 外部配置，对象的唯一ID值 */
        char type_name[32];                     /* 外部配置，对象的控件类型名字 ， 不要超过31个英文字符*/
} tui_object_attri_t;
/*------------------------
 *  创建和销毁object对象
 *------------------------*/
tui_obj_t * tui_obj_create(tui_obj_t * parent);
void tui_obj_del(tui_obj_t * obj);
/*------------------------
 *  object对象set
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
 *  object对象get
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
 *  object对象动画
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
 *  view视图容器
 *------------------------*/
tui_obj_t * tui_view_create(const char *layout_view_path, tui_map_cb_t map_cb[]);
void tui_view_reg_func(char *component_reg_cb_map[]);

/*------------------------
 *  container容器
 *------------------------*/
typedef void (*tui_container_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
		/* 组件属性 */
		void *attri_com;
        /* 容器回调函数，返回当前事件 */
        tui_container_cb_t cb;

        uint32_t bg_color;                      /* 外部配置，容器的背景颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
} tui_container_attri_t;
tui_obj_t * tui_container_create(tui_obj_t * par);
int tui_container_set_attri(tui_obj_t *container, tui_container_attri_t *attri);
int tui_container_get_attri(tui_obj_t *container, tui_container_attri_t *attri);
int tui_container_set_cb(tui_obj_t *container, tui_container_cb_t cb);

/*------------------------
 *  page页
 *------------------------*/
typedef void (*tui_page_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 页回调函数，返回当前事件 */
        tui_page_cb_t cb;

        uint32_t bg_color;                      /* 外部配置，页里面的背景颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        tui_size_t window_size;                 /* 外部配置，页里面的窗口的大小 */
        tui_point_t window_pt;                  /* 外部配置，页里面的窗口位置 */
        tui_scrollbar_mode_e mode;              /* 外部配置，页里面的滚条模式设置 */
        bool edge_arc_able;                     /* 外部配置，页到达边缘动画设置 */
} tui_page_attri_t;
tui_obj_t * tui_page_create(tui_obj_t * par);
int tui_page_set_attri(tui_obj_t *page, tui_page_attri_t *attri);
int tui_page_get_attri(tui_obj_t *page, tui_page_attri_t *attri);
tui_obj_t * tui_page_get_window_obj(const tui_obj_t *page);
void tui_page_set_scrollbar_mode(tui_obj_t * page, tui_scrollbar_mode_e page_bar_mode);
void tui_page_set_edge_arc(tui_obj_t * page, bool able);

/*------------------------
 *  excel表格
 *------------------------*/
typedef void(*tui_excel_cb_t)(tui_obj_t *obj, tui_event_e event, uint32_t column, uint32_t row);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 表格回调函数，返回单元格当前事件 */
        tui_excel_cb_t cb;

        uint32_t bg_color;                      /* 外部配置，表格里面的背景颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t border_color;                  /* 外部配置，表格里面的边框颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        tui_point_t window_pt;                  /* 外部配置，表格里面的窗口位置 */
        tui_scrollbar_mode_e mode;              /* 外部配置，表格里面的滚条模式设置 */
        bool edge_arc_able;                     /* 外部配置，表格到达边缘动画设置 */
        uint32_t rows;                          /* 外部配置，表格的行数 */
        uint32_t columns;                       /* 外部配置，表格的列数 */
        uint32_t cell_w;                        /* 外部配置，表格的单元格宽 */
        uint32_t cell_h;                        /* 外部配置，表格的单元格高 */
        bool input_able;                        /* 外部配置，支持单元格字符输入 */
        int32_t fnt_size;                       /* 外部配置，表格的默认字体大小 */
        uint32_t fnt_color;                     /* 外部配置，表格的默认字体的颜色 （0xFF112233  FF是透明度；11是R；22是G；33是B）*/

        /* 表格里面的对象集合，供内部使用 */
        uint32_t *cells;
        /* 表格里面的按键，供内部使用 */
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
 *  label标签
 *------------------------*/
typedef void (*tui_label_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 弧形回调函数，返回当前事件 */
        tui_label_cb_t cb;

        int32_t fnt_size;                       /* 外部配置，标签字体大小 */
        char* txt;                              /* 外部配置，标签的文本信息 */
        uint32_t fnt_color;                     /* 外部配置，标签字体的颜色 （0xFF112233  FF是透明度；11是R；22是G；33是B）*/
        tui_label_long_mode_e mode;             /* 外部配置，标签显示模式（其中有滚动显示） */
        tui_label_align_e align;                /* 外部配置，标签对齐方式 */
        bool input_able;                        /* 外部配置，支持标签字符输入 */
        bool ttf_font;                          /* 外部配置，支持TTF字体 */
        uint32_t border_color;                  /* 外部配置，标签的边框颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
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
 *  arc弧形
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
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 弧形回调函数，返回当前事件 */
        tui_arc_cb_t cb;
        /* 供内部使用 */
        tui_timer_t * arc_loading;
        /* 供内部使用 */
        tui_style_t arc_fg_style;

        int16_t start_angle;                    /* 外部配置，弧形的开始角度 */
        int16_t end_angle;                      /* 外部配置，弧形的结束角度 */
        int16_t bg_start_angle;                 /* 外部配置，弧形背景的开始角度 */
        int16_t bg_end_angle;                   /* 外部配置，弧形背景的结束角度 */
        int16_t line_width;                     /* 外部配置，弧形的线宽 */
        uint32_t bg_color;                      /* 外部配置，弧形的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t fg_color;                      /* 外部配置，弧形的前景色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        bool is_rounded;                        /* 外部配置，是否弧形端圆滑处理 */
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
 *  bar_progress进度条
 *------------------------*/
typedef void (*tui_bar_progress_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 进度条回调函数，返回当前事件 */
        tui_bar_progress_cb_t cb;
        /* 供内部使用 */
        tui_style_t fg_style;

        int16_t value;                          /* 外部配置，进度条的值，范围是0~100 */
        uint32_t bg_color;                      /* 外部配置，进度条的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t fg_color;                      /* 外部配置，进度条的前景色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
} tui_bar_progress_attri_t;
tui_obj_t * tui_bar_progress_create(tui_obj_t * par);
int tui_bar_progress_set_attri(tui_obj_t *bar_progress, tui_bar_progress_attri_t *attri);
int tui_bar_progress_get_attri(tui_obj_t *bar_progress, tui_bar_progress_attri_t *attri);
int16_t tui_bar_progress_get_value(tui_obj_t *bar_progress);
void tui_bar_progress_set_value(tui_obj_t *bar_progress, int16_t vaule);

/*------------------------
 *  bar_slider滑条
 *------------------------*/
typedef void (*tui_bar_slider_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t value);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 滑动触发回调函数，返回当前值 */
        tui_bar_slider_cb_t cb;
		tui_obj_t *bg_img_obj;
		tui_obj_t *fg_img_obj;
		tui_obj_t *knob_img_obj;
		bool is_img;
		bool is_hor;
        /* 供内部使用 */
        tui_style_t knob_style;
        /* 供内部使用 */
        tui_style_t fg_style;

        int16_t value;                          /* 外部配置，滑条的值，范围是0~1000 */
        uint32_t bg_color;                      /* 外部配置，滑条的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t fg_color;                      /* 外部配置，滑条的前景色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t knob_color;                    /* 外部配置，滑块的控钮色（0xFF112233  FF是透明度；11是R；22是G；33是B） */

		char *bg_img_path;                   /* 外部配置，滑条的底色图片 */
		char *fg_img_path;                   /* 外部配置，滑条的前景色图片 */
		char *knob_img_path;                 /* 外部配置，滑块的控钮图片 */
} tui_bar_slider_attri_t;
tui_obj_t * tui_bar_slider_create(tui_obj_t * par);
tui_obj_t * tui_bar_slider_create_ext(tui_obj_t * par, bool is_img);
int tui_bar_slider_set_attri(tui_obj_t *bar_slider, tui_bar_slider_attri_t *attri);
int tui_bar_slider_get_attri(tui_obj_t *bar_slider, tui_bar_slider_attri_t *attri);
void tui_bar_slider_set_knob_disable_move(tui_obj_t *bar_slider);
int16_t tui_bar_slider_get_value(tui_obj_t *bar_slider);
void tui_bar_slider_set_value(tui_obj_t *bar_slider, int16_t vaule);

/*------------------------
 *  button按键
 *------------------------*/
typedef void (*tui_button_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 点击触发回调函数，返回按钮状态事件 */
        tui_button_cb_t cb;
        /* 供内部使用 */
        bool pressed;

        uint32_t bg_color;                      /* 外部配置，按键的背景颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t border_color;                  /* 外部配置，按键的边框颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t border_width;                  /* 外部配置，按键的边框线宽度 */
} tui_button_attri_t;
tui_obj_t * tui_button_create(tui_obj_t * par);
int tui_button_set_attri(tui_obj_t *button, tui_button_attri_t *attri);
int tui_button_get_attri(tui_obj_t *button, tui_button_attri_t *attri);
void tui_button_set_shadow(tui_obj_t *button, bool able);
void tui_button_set_click_zoom(tui_obj_t *button, bool able);

/*------------------------
 *  image_btn图片按键
 *------------------------*/
typedef void(*tui_image_btn_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 点击触发回调函数，返回当前状态和值事件 */
        tui_image_btn_cb_t cb;
        /* 供内部使用 */
        bool pressed;
        /* 所有图片buffer保存，供内部使用 */
		void *img_pressed[16];
		int8_t img_pressed_type[16];
        /* 所有图片buffer保存，供内部使用 */
		void *img_release[16];
		int8_t img_release_type[16];

        int16_t img_index;                      /* 外部配置，图片按键，当前图片的索引 */
        int16_t img_num;                        /* 外部配置，图片按键，有多少张图片总和, 不要超过16张图片 */
        bool hor_mirror;                        /* 外部配置，图片按键的水平镜像 */
        bool ver_mirror;                        /* 外部配置，图片按键的垂直镜像 */
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
 *  image图片
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
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 动画变化后有回调函数，返回当前图片值事件 */
        tui_image_cb_t cb;
        /* 所有图片buffer保存，供内部使用 */
        void *img[128];
        void *img_temp;
        void *img_temp_1;
        int8_t img_type[128];
        /* 动画timer，供内部使用 */
        tui_timer_t *timer;
        /* 动画timer，开始索引值供，内部使用 */
        int16_t start_index;
        /* 动画timer，结束索引值供，内部使用 */
        int16_t end_index;
        /* 动画timer，旋转角度，内部使用 */
        int16_t rotate_offset;
        /* 动画timer，旋转方向，内部使用 */
        double rotate_way;
        /* 内部使用 */
        int16_t rotate_angle_temp;

        int16_t img_index;                      /* 外部配置，图片控件，当前图片的索引 */
        int16_t img_num;                        /* 外部配置，图片控件，有多少张图片总和 , 不要超过128张图片*/
        int16_t zoom;                           /* 外部配置，图片控件放大缩小值 ，256不放大，小于256缩小，大于256放大，512放大两倍，128缩小一半*/
        int16_t rotate_angle;                   /* 外部配置，图片控件旋转角度，范围0~360 */
        tui_point_t rotate_pt;                  /* 外部配置，图片控件旋转的中心坐标，默认是中心点 */
        bool anim_start;                        /* 外部配置，图片控件图片动画默认是否开始，0或者1*/
        int32_t anim_time;                      /* 外部配置，图片控件图片动画切换的时间，毫秒单位*/
        tui_image_circulate_e mode;             /* 外部配置，图片控件图片动画切换的模式，单次还是无限循环 */
        tui_coord_t x_offset;                   /* 外部配置，图片的源X偏移 */
        tui_coord_t y_offset;                   /* 外部配置，图片的源Y偏移 */
        bool hor_mirror;                        /* 外部配置，图片的水平镜像 */
        bool ver_mirror;                        /* 外部配置，图片的垂直镜像 */
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
 *  animation动画
 *------------------------*/
typedef void(*tui_animation_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        char path[48];  /* 路径不要超过48个字符 */
        int x;
        int y;
        int ms;
} tui_anima_img_attri_t;

typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 动画变化后有回调函数，返回当前图片值 */
        tui_animation_cb_t cb;
        /* 动画image，供内部使用 */
        void *img_obj;
        /* buffer保存，供内部使用 */
        void *img_buff[2];
        int16_t img_buff_index;
        /* 动画timer，供内部使用 */
        tui_timer_t *timer;
        /* 动画timer，开始索引值供，内部使用 */
        int16_t start_index;
        /* 动画timer，结束索引值供，内部使用 */
        int16_t end_index;

        uint32_t bg_color;                      /* 外部配置，动画容器的背景颜色, 默认是0（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        int16_t img_index;                      /* 外部配置，动画，当前图片的索引 */
        int16_t img_num;                        /* 外部配置，动画，有多少张图片总和, 不要超过128张图片 */
        tui_anima_img_attri_t anima_img[128];   /* 外部配置，动画里面的图片集合， 图片不要超过128张 */
        bool anim_start;                        /* 外部配置，动画默认是否开始，0或者1*/
        tui_image_circulate_e mode;             /* 外部配置，动画切换的模式，单次还是无限循环 */
        bool hor_mirror;                        /* 外部配置，动画的水平镜像 */
        bool ver_mirror;                        /* 外部配置，动画的垂直镜像 */
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
 *  gif图片动画
 *------------------------*/
typedef void(*tui_gif_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t img_index);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 动画变化后有回调函数，返回当前gif图片索引值 */
        tui_gif_cb_t cb;

        char gif_path[128];                     /* 外部配置，gif动画路径 */
        tui_image_circulate_e mode;             /* 外部配置，动画切换的模式，单次还是无限循环 */
} tui_gif_attri_t;
tui_obj_t * tui_gif_create(tui_obj_t * par);
int tui_gif_set_attri(tui_obj_t *gif, tui_gif_attri_t *attri);
int tui_gif_get_attri(tui_obj_t *gif, tui_gif_attri_t *attri);
int tui_gif_pause(tui_obj_t *gif);
int tui_gif_play(tui_obj_t *gif);
int tui_gif_restart(tui_obj_t *gif);
int tui_gif_set_mode(tui_obj_t *gif, tui_image_circulate_e mode);

/*------------------------
 *  line线
 *------------------------*/
typedef void (*tui_line_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 线回调函数，返回当事件 */
		tui_line_cb_t cb;
		/* 多点线，供内部使用 */
		tui_point_t *point_a[2];
		/* 多点线，供内部使用 */
		uint16_t point_num;
		/* 多点线，供内部使用 */
		uint16_t point_index;

        uint32_t width;                         /* 外部配置，线的宽度 */
        uint32_t color;                         /* 外部配置，线的颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        tui_point_t pts[2];                     /* 外部配置，线的坐标，两点一线 */
} tui_line_attri_t;
tui_obj_t * tui_line_create(tui_obj_t * par);
int tui_line_set_attri(tui_obj_t *line, tui_line_attri_t *attri);
int tui_line_get_attri(tui_obj_t *line, tui_line_attri_t *attri);
void tui_line_set_points(tui_obj_t * line, tui_point_t point_a, tui_point_t point_b);
void tui_line_set_line_width(tui_obj_t * line, uint32_t width);
void tui_line_set_line_color(tui_obj_t * line, uint32_t color);
void tui_line_set_some_points_line(tui_obj_t * line, tui_point_t *point_a, uint16_t point_num, bool is_bezier);

/*------------------------
 *  switch_btn切换开关
 *------------------------*/
typedef void (*tui_switch_btn_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t value);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 点击触发回调函数，返回当前状态值 */
        tui_switch_btn_cb_t cb;
        /* 供内部使用 */
        tui_style_t knob_style;
        /* 供内部使用 */
        tui_style_t fg_style;

		bool value;                             /* 外部配置，切换开关的值 ，0或者1*/
        uint32_t bg_color;                      /* 外部配置，切换开关的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t fg_color;                      /* 外部配置，切换开关的前景色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t knob_color;                    /* 外部配置，切换开关的按钮色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
} tui_switch_btn_attri_t;
tui_obj_t * tui_switch_btn_create(tui_obj_t * par);
int tui_switch_btn_set_attri(tui_obj_t *switch_btn, tui_switch_btn_attri_t *attri);
int tui_switch_btn_get_attri(tui_obj_t *switch_btn, tui_switch_btn_attri_t *attri);
int tui_switch_btn_get_vaule(tui_obj_t *switch_btn);
void tui_switch_btn_set_vaule(tui_obj_t *switch_btn, bool value);

/*------------------------
 *  dropdown下拉菜单
 *------------------------*/
typedef void (*tui_dropdown_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t index);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 点击触发回调函数，返回当前索引值 */
        tui_dropdown_cb_t cb;
        /* 供内部使用 */
        tui_style_t bar_style;
        /* 供内部使用 */
        tui_style_t list_style;

        int16_t cur_index;                      /* 外部配置，当前下拉菜单的索引值 */
        int16_t options_num;                    /* 外部配置，当前下拉菜单的个数 */
        char options[210][40];                  /* 外部配置，下拉菜单的文本设置 */
        uint32_t bar_color;                     /* 外部配置，下拉菜单bar的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t list_color;                    /* 外部配置，下拉菜单列表的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t text_color;                    /* 外部配置，下拉菜单字符的颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        int16_t text_font_size;                 /* 外部配置，下拉菜单字符字体大小 */
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
 *  textbox文本输入框
 *------------------------*/
typedef void (*tui_textbox_cb_t)(tui_obj_t *obj, tui_event_e event, const char * str);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 输入触发回调函数，返回当前字符串 */
        tui_textbox_cb_t cb;

        bool pwd_able;                  /* 外部配置，文本输入框模式，是否是密码输入 */
        char *accepted_chars;                   /* 外部配置，文本输入框可以输入的字符限制， 空是支持所有字符 */
} tui_textbox_attri_t;
tui_obj_t * tui_textbox_create(tui_obj_t * par);
int tui_textbox_set_attri(tui_obj_t *textbox, tui_textbox_attri_t *attri);
int tui_textbox_get_attri(tui_obj_t *textbox, tui_textbox_attri_t *attri);
const char * tui_textbox_get_text(const tui_obj_t * textbox);
void tui_textbox_set_text(tui_obj_t * textbox, const char * txt);
void tui_textbox_set_pwd_mode(tui_obj_t * textbox, bool pwd_able);
void tui_textarea_set_accepted_chars(tui_obj_t * textbox, const char * accepted_chars);

/*------------------------
 *  checkbox复选框
 *------------------------*/
typedef void(*tui_checkbox_cb_t)(tui_obj_t *obj, tui_event_e event, int32_t value);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 点击触发回调函数，返回当前状态值 */
        tui_checkbox_cb_t cb;

        int32_t value;                          /* 外部配置，复选框的值，0或者1 */
} tui_checkbox_attri_t;
tui_obj_t * tui_checkbox_create(tui_obj_t * par);
int tui_checkbox_set_attri(tui_obj_t *checkbox, tui_checkbox_attri_t *attri);
int tui_checkbox_get_attri(tui_obj_t *checkbox, tui_checkbox_attri_t *attri);
bool tui_checkbox_get_vaule(tui_obj_t *checkbox);
void tui_checkbox_set_vaule(tui_obj_t *checkbox, bool value);

/*------------------------
 *  list列表
 *------------------------*/
typedef void (*tui_list_cb_t)(tui_obj_t *obj_list, tui_event_e event, int32_t index);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 列表回调函数，返回当前某一个列表项事件 */
        tui_list_cb_t cb;
        /* 列表滑动标记，供内部使用 */
        bool move_flag;
        /* 选择，供内部使用 */
        tui_obj_t * select_img;

        uint32_t bg_color;                      /* 外部配置，列表的背景颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t cur_index;                     /* 外部配置，列表的当前索引焦点值 */
        tui_scrollbar_mode_e mode;              /* 外部配置，列表里面的滚条模式设置 */

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
 *  multi_screen多屏控件
 *------------------------*/
typedef void (*tui_multi_screen_cb_t)(tui_obj_t *obj, tui_event_e event, int16_t index);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 屏幕滑动结束回调函数，返回当前屏幕索引值 */
        tui_multi_screen_cb_t cb;
        /* 动画timer，供内部使用 */
        tui_timer_t *timer;
        /* 动画timer，开始坐标，供内部使用 */
        int32_t start_x;
        /* 动画timer，结束坐标，供内部使用 */
        int32_t end_x;
        /* 动画timer，计数，供内部使用 */
        int32_t cnt;

        int32_t screen_w;                       /* 外部配置，多屏控件的宽, 和屏幕的宽保存一致 */
        int32_t screen_h;                       /* 外部配置，多屏控件的高 */
        uint8_t screen_num;                     /* 外部配置，多屏控件的屏数量 */
        uint8_t cur_screen_index;               /* 外部配置，多屏控件的当前屏的索引 */
} tui_multi_screen_attri_t;
tui_obj_t * tui_multi_screen_create(tui_obj_t * par);
int tui_multi_screen_set_attri(tui_obj_t *multi_screen, tui_multi_screen_attri_t *attri);
int tui_multi_screen_get_attri(tui_obj_t *multi_screen, tui_multi_screen_attri_t *attri);
int tui_multi_screen_set_cur_screen_index(tui_obj_t *multi_screen, uint8_t cur_screen_index, bool is_anima);
uint8_t tui_multi_screen_get_cur_screen_index(tui_obj_t *multi_screen);

/*------------------------
 *  canvas画布
 *------------------------*/
typedef void (*tui_canvas_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 画布回调函数，返回当前事件 */
        tui_canvas_cb_t cb;
        /* 画布的ARGB buffer，供内部使用 */
        uint32_t *argb_buf;

        uint32_t bg_color;                      /* 外部配置，画布的背景颜色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
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
 *  qrcode二维码
 *------------------------*/
typedef void(*tui_qrcode_cb_t)(tui_obj_t *obj, tui_event_e event, const char * str);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 二维码触发回调函数，返回当前二维码字符串 */
        tui_qrcode_cb_t cb;
        /* 画布的buffer，供内部使用 */
        uint32_t *cbuf;

        uint32_t bg_color;                      /* 外部配置，二维码的底色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        uint32_t fg_color;                      /* 外部配置，二维码的前景色（0xFF112233  FF是透明度；11是R；22是G；33是B） */
        char *qrcode_chars;                     /* 外部配置，二维码字符内容 */
} tui_qrcode_attri_t;
tui_obj_t * tui_qrcode_create(tui_obj_t * par);
int tui_qrcode_set_attri(tui_obj_t *qrcode, tui_qrcode_attri_t *attri);
int tui_qrcode_get_attri(tui_obj_t *qrcode, tui_qrcode_attri_t *attri);
const char * tui_qrcode_get_text(const tui_obj_t * qrcode);
void tui_qrcode_set_text(tui_obj_t * qrcode, const char * qrcode_chars);

/*------------------------
 *  sound声音
 *------------------------*/
void tui_sound_enable(bool able);
typedef void (*tui_sound_cb_t)(tui_obj_t *obj, tui_event_e event);
typedef struct {
        /* 通用属性 */
        tui_object_attri_t obj;
        /* 声音回调函数，返回当前事件 */
        tui_sound_cb_t cb;
        /* 声音buffer保存，供内部使用 */
        int16_t *sound;
        /* 声音buffer保存，供内部使用 */
        int32_t sound_len;
        /* 声音计数，供内部使用 */
        int32_t play_cnt;
        /* 声音句柄，供内部使用 */
        tui_obj_t * me;

        int32_t play_mode;                      /* 外部配置，声音控件播放模式， 0是播放一次，1是循环播放  */
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

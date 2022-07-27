#include "tui.h"

/*
 * 局部变量声明
 */
static tui_obj_t * this_app_obj;


/*
 * 视图函数声明
 */
extern tui_obj_t * logo_logo_view_view_create(void);


/*
 * APP系统消息接收回调函数
 */
static int32_t logo_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	switch (cmd)
	{
	// TODO
	default:
		break;
	}
	return 0;
}


/*
 * APP退出回调函数
 */
static void logo_exit(void)
{
	/* 卸载注册的消息接收函数，视图删除后清空句柄 */
	tui_sys_msg_unreg(logo_sys_msg_cb);
	this_app_obj = NULL;
}


/*
 * APP入口函数，供外部调用，返回当前object。
 */
tui_obj_t * logo_enter(void)
{
	/* 注册消息接收函数 */
	tui_sys_msg_reg(logo_sys_msg_cb);

	/* 创建视图，绑定视图删除后的执行回调函数 */
	this_app_obj = logo_logo_view_view_create();
	tui_obj_set_del_cb(this_app_obj, logo_exit);

	/* 返回视图句柄 */
	return this_app_obj;
}


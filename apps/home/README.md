<h1 align="center"> 应用多屏主界面 </h1>

## 介绍：
该界面是所有app的入口界面，home同时也管理所有app应用的生死存亡，home应用采用一个多屏控件容器，将所有应用的app放入控件里面。

<p align="center">
<img src="https://github.com/TUISYS/image/blob/main/home.gif">
</p>
<p align="center">
多屏主界面例子展示
</p>

## TUI框架逻辑接口介绍：
在home应用里面体现了TUI里面的内核接口流程，如消息的注册，发送和接收，定时器的使用，动画的操作，以及TUI的整个生命周期的“三部曲”，界面的创建和销毁等。

### * TUI生命“三部曲”
TUI初始化系统资源、循环处理TUI内部机器运转、退出TUI内部运转机器，释放所有资源。
``` c

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
```
如上，在进行TUI资源初始化后，应用创建了一个LOGO视图，并且使能了一个动画。然后应用通过```tui_sys_msg_reg(home_sys_msg_cb);```注册消息接收回调函数，来处理应用的逻辑流程。最后TUI开始内核机器运转，整个GUI就跑起来了。如果GUI需要退出，就结束循环，释放TUI所有系统资源。

### * 对象的生命“三部曲”
TUI里面所有控件都是从基础对象（object）继承而来，所有控件也有“三部曲”，第一步创建控件；第二步设置控件属性，及其操作；第三步是销毁控件。每个对象都有其唯一的创建函数（xxx_create），但是销毁接口函数只有一个接口```tui_obj_del()```，由于所有控件对象都是从object继承而来，所以object的设置属性和相关的操作函数，也可以被控件对象使用。请查看```tui.h```里面的相关函数如下：
```
/*------------------------
 *  object对象set
 *------------------------*/
 ...
 
 /*------------------------
 *  object对象get
 *------------------------*/
 ...
 
 /*------------------------
 *  object对象动画
 *------------------------*/
 ...
 
```

### * TUI的逻辑处理助手（消息机制、控件回调函数、定时器）
消息机制、控件回调函数、定时器能处理复杂的应用逻辑，控件之间的信息传递，以及控件的实时触发相应，精准的时间控制管理。请查看```tui.h```里面的相关函数如下：
```
/*------------------------
 *  system message系统消息
 *------------------------*/
 ...
 
 /*------------------------
 *  timer定时器
 *------------------------*/
 ...
 
```
以上接口使用及其简单，都能在应用找到使用的demo。




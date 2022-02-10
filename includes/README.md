<h1 align="center"> TUI“系统”提供接口头文件 </h1>

## 介绍：
里面存放了所有系统和应用需要的接口头文件，用户在应用开发的时候，只需要包含`tui.h`头文件，就可以正常编写程序。<br>
`tui.h`里面包含：TUI所有控件接口函数；用户自定义消息枚举`sys_msg_def.h`；UIStudio工具生成的控件ID文件`tui_id.h`；跨平台系统函数接口头文件`stdxxx.h`（包含stdio.h、string.h、stdlib.h）。

## TUI内核接口（tui.h）
里面的分类接口如下，每一类都是按照如下注释分类，下面按照顺序说明：
```
/*------------------------
 *  xxxxxxxxxxxxxxxxx
 *------------------------*/
 ```
* tui生命周期三部曲，初始化、循环运行、销毁，相关例子查看<br>
`apps/home/home.c`里面`int home_create(void)`函数。
``` c
void tui_start_init(const char * res_path, int screen_hor_res, int screen_ver_res);
void tui_run_loop(void);
void tui_end_uninit(void);
```
* TUI系统消息函数，应用需要获取系统广播发送的消息，然后做相关的应用处理。提供了消息注册，消息发送等接口。
* TUI定时器函数，提供定时器的创建、销毁和参数设置，各个应用都有相关的例子使用。
* 获取uistudio工具配置信息接口函数，如屏幕分辨率、版本号、密码对比、串口参数设置。
* TUI多国语言接口。
* 获取UIStudio工具制作的`V盘`镜像文件。
* gb2312和utf8的编码转换
* 系统运行时间接口、休眠接口等
* 串口模拟接口函数
* 触摸和按键接口钩子函数，可以设置回调函数实时获取。
* 按键操作函数接口。
* 调试信息输出，输出所有内核消息，查看是否内存泄漏。
* 以下所有都是控件接口，都是从object派生出来。

## TUI内核接口（stdxxx.h）
里面的接口是模拟了`stdio.h`、`string.h`、`stdlib.h`标准库里面大部分常用函数，可以满足大部分应用开发需求。<br>
如果在开发中不想用这些，可以注释掉，使用传统的标准库函数。（如果不注释掉stdxxx.h会导致编译报错，函数重定义）

## TUI应用消息枚举（sys_msg_def.h）
为了统一管理系统的广播消息，这里提供了一个消息枚举头文件，主要是方便应用开发的消息管理。<br>
开发者在开发的过程中可以编辑，增加枚举。（如果开发者不习惯这种，也可以在其它地方定义消息枚举）

## UIStudio创建控件时产生的唯一ID集合（tui_id.h）
里面的所有宏定义ID都是由UIStudio工具自动生成的唯一ID，用在开发的过程中，通过下面两个函数中的一个，都可以获得控件句柄，然后操做控件。
``` c
tui_obj_t * tui_get_obj_from_id(tui_obj_t * parent, uint32_t obj_id);//快速搜索
tui_obj_t * tui_search_obj_from_id(uint32_t obj_id);//全局搜索
```



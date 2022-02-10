<h1 align="center"> TUI是一套人机交互的GUI系统 </h1>

## TUI概述：
* TUI是一款小巧精致的GUI，可以用于HMI、智能家居、工业控制、教育类学习机、广告机、游戏机等应用场景。
* TUI作为嵌入式GUI，致力于软件跨平台的开发，不同平台间代码满足99%的兼容性，目前tui_project支持Windows、Melis、eos嵌入式平台。
* TUI提供了uistudio工具，通过工具可以实现界面的可视化编辑。整个应用的UI开发类似搭积木的拖拽控件，并且实现了视图、资源和逻辑的分离。
* TUI内核不单单包含了GUI的相关功能和丰富控件，里面还实现了消息机制、定时器、多国语言、资源的盘符打包、编码转换、串口封装接口，时间等。
* TUI的设计非常严谨，可以把它看成一个非常独立的模块，TUI整个生命周期由三步，初始化（*tui_start_init*）、运行（*tui_run_loop*）、销毁（*tui_end_uninit*）三个函数控制。里面有完整地调试debug功能，退出的时候不会有内存泄漏和异常问题。

## 结构目录：
* :file_folder:**“apps”**&ensp;&ensp;&ensp;&ensp;文件夹，里面存放了用户的逻辑代码，其中每个app里面的view视图代码是uistudio工具自动生成。
* :file_folder:**“includes”**&ensp;文件夹，里面存放了TUI所有接口函数头文件[“查看相关详细说明”](./includes/)。
* :file_folder:**“platform”**&ensp;文件夹，里面存放各个OS系统平台的工程编译入口文件夹（*melis、eos、vc++*）。
* :file_folder:**“res”**&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;文件夹，里面存放app开发的资源字体、图片、多国语言、视图布局结构、声音等其它应用资源。
* :file_folder:**“uistudio”**&ensp;&ensp;文件夹，里面存放所见即所得工具所需要的工程文件。
* :handbag:**“res.disk”**&ensp;&ensp;镜像包，该文件是uistudio工具，把res里面的资源处理后打包制作成一个**镜像资源文件**。<br>
                       最后被映射到tui内核里面，成为一个**V:盘符**。

## 应用APP介绍：
由于不是专业美工、开发时间有限，应用里面的所有图片均来自互联网，没有经过特殊处理（不用于商业用途），图片稍加利用，来实现TUI的接口功能。<br>
下面我们对每个app做个简单的介绍，然后结合tui.h里面的接口，做相关说明。<br><br>
<p align="center">
<img src="https://gitee.com/tuisys/image/raw/main/home.gif">
</p>
<p align="center">
所有APP应用例子展示
</p>

### 弧形应用（arc_app0）
* 跳转到对应的目录查看[“弧形应用说明”](./apps/arc_app0/)
### 按钮应用（button_app1）
* 跳转到对应的目录查看[“按钮应用说明”](./apps/button_app1/)
### 直线应用（line_app2）
* 跳转到对应的目录查看[“直线应用说明”](./apps/line_app2/)
### 滑条应用（bar_app3）
* 跳转到对应的目录查看[“滑条应用说明”](./apps/bar_app3/)
### 动画应用（animation_app4）
* 跳转到对应的目录查看[“动画应用说明”](./apps/animation_app4/)
### 表盘应用（dashboard_app5）
* 跳转到对应的目录查看[“表盘应用说明”](./apps/dashboard_app5/)
### 窗口应用（window_app6）
* 跳转到对应的目录查看[“窗口应用说明”](./apps/window_app6/)
### 串口应用（serial_app7）
* 跳转到对应的目录查看[“串口应用说明”](./apps/uart_app7/)
### 页容器应用（page_app8）
* 跳转到对应的目录查看[“页容应用说明”](./apps/page_app8/)
### 画板应用（draw_app9）
* 跳转到对应的目录查看[“画板应用说明”](./apps/draw_app9/)
### 设置应用（setting_app10）
* 跳转到对应的目录查看[“设置应用说明”](./apps/setting_app10/)
### 登陆应用（logon_app11）
* 跳转到对应的目录查看[“登陆应用说明”](./apps/logon_app11/)

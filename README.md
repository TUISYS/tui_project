<h1 align="center"> TUI是一套人机交互的GUI系统 </h1>

## TUI特性：
* TUI是一款小巧精致的GUI，采用纯C语言编写，可以用于HMI、智能家居、工业控制、教育类学习机、广告机、游戏机等应用场景。
* TUI作为嵌入式GUI，致力于软件跨平台的开发，不同平台间代码满足99%的兼容性，目前tui_project支持系统如下：<br>
  **Windows**系统；<br>
  **Linux**系统；<br>
  **allwinner全志**系列芯片支持，如**全志Tina系统**、**全志Melis4系统**、**全志Melis2系统**嵌入式平台。  
* TUI内核不单单包含GUI相关的功能和丰富控件，里面还实现了消息机制、定时器、多国语言、图片（jpg、bmp、png、gif、svg矢量图）、声音（wav、mp3）、各种资源的压缩打包最后映射成`V盘`。
* TUI内核还包含gb2312和utf8的编码转换、跨平台串口封装接口，时间、中文输入法、665KB的中文矢量字体、动画等。
* TUI内核扩展特性包括：复杂组件、`.xls`表格文件的读取、`.xlsx`表格文件的创建、`TTS`中文语音合成播报、`.jpg`文件解码、`JSON`文件解析等。
* TUI提供了上位机uistudio工具，通过工具可以实现界面的可视化编辑，整个界面视图的UI开发，类似搭积木的拖拽控件，并且实现了视图、资源和逻辑的分离。
* TUI提供的上位机uistudio工具，还支持工程逆向，通过UStudio.Rever可以修改`res.disk`，方便不懂编程的人员，替换图片和更改坐标，完成固件修改。
* TUI的设计非常严谨，可以把它看成一个非常独立的模块，TUI整个生命周期有三步，初始化函数（ *tui_start_init()* ）、运行函数（ *tui_run_loop()* ）、销毁函数（ *tui_end_uninit()* ）三个函数控制，TUI提供界面DEBUG显示和debug调试函数（ *tui_dbg_core_information_dump()* 导出所有内核资源信息 ），退出的时候不会有内存泄漏和异常问题。
* TUI支持自动化测试，在PC端记录轨迹坐标，保存文件后，可以通过 *tui_pointer_run_auto_test()* 函数自动循环执行

## 结构目录：
* :file_folder:**“apps”**&ensp;&ensp;&ensp;&ensp;文件夹，里面存放了用户的逻辑代码，代码兼容各个系统平台。其中每个app里面的view视图代码是uistudio工具自动生成。
* :file_folder:**“includes”**&ensp;文件夹，里面存放了TUI所有接口函数头文件[“查看相关详细说明”](./includes/)。
* :file_folder:**“platform”**&ensp;文件夹，里面存放各个OS系统平台的工程编译入口文件夹（*melis、vc++、tina、linux*）。
* ~~:file_folder:**“component”**&ensp;文件夹，里面存放开源的组件代码，都是TUI内核函数和基础控件实现的组件。**（可选）**~~
* :file_folder:**“res”**&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;文件夹被uistudio使用，里面存放app开发的资源字体、图片、多国语言、视图布局结构、声音等其它应用资源。
* :file_folder:**“uistudio”**&ensp;&ensp;文件夹里面存放所见即所得工具所需要的工程文件。
* :handbag:**“res.disk”**&ensp;&ensp;镜像包，该文件是uistudio工具，把res里面的资源处理后打包制作成一个**镜像资源文件**。<br>
                       最后被映射到tui内核里面，成为一个**V:盘符**，应用在加载资源的时候需要用到。

## 应用APP介绍：
由于不是专业美工、开发时间有限，应用里面的所有图片均来自互联网，没有经过特殊处理（不用于商业用途），图片稍加利用，来实现TUI的接口功能。<br>
下面我们对每个app做个简单的介绍，然后结合tui.h里面的接口，做相关说明。<br><br>
<p align="center">
<img src="https://s1.imagehub.cc/images/2023/09/28/home.gif">
</p>
<p align="center">
主界面应用例子展示 
</p>

### 弧形应用（arc_app0）
* 跳转到弧形应用的目录查看[“./apps/arc_app0”](./apps/arc_app0/)
### 按钮应用（button_app1）
* 跳转到按钮应用的目录查看[“./apps/button_app1”](./apps/button_app1/)
### 直线应用（line_app2）
* 跳转到直线应用的目录查看[“./apps/line_app2”](./apps/line_app2/)
### 滑条应用（bar_app3）
* 跳转到滑条应用的目录查看[“./apps/bar_app3”](./apps/bar_app3/)
### 动画应用（animation_app4）
* 跳转到动画应用的目录查看[“./apps/animation_app4”](./apps/animation_app4/)
### 表盘应用（dashboard_app5）
* 跳转到表盘应用的目录查看[“./apps/dashboard_app5”](./apps/dashboard_app5/)
### 窗口应用（window_app6）
* 跳转到窗口应用的目录查看[“./apps/window_app6”](./apps/window_app6/)
### 串口应用（uart_app7）
* 跳转到串口应用的目录查看[“./apps/uart_app7”](./apps/uart_app7/)
### 页容器应用（page_app8）
* 跳转到页容器应用的目录查看[“./apps/page_app8”](./apps/page_app8/)
### 画板应用（draw_app9）
* 跳转到画板应用的目录查看[“./apps/draw_app9”](./apps/draw_app9/)
### 设置应用（setting_app10）
* 跳转到设置应用的目录查看[“./apps/setting_app10”](./apps/setting_app10/)
### 登陆应用（logon_app11）
* 跳转到登陆应用的目录查看[“./apps/logon_app11”](./apps/logon_app11/)

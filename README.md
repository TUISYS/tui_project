<h1 align="center"> TUI是一套人机交互的GUI系统 </h1>

## 介绍：
* TUI是一款小巧精致的GUI，可以由于HMI、教育类故事机、广告机、游戏机等应用场景。
* TUI作为嵌入式GUI，致力于软件夸平台的开发，不同平台间代码需要99%的兼容性，目前tui_project支持Windows、Melis、eos嵌入式平台。
* TUI提供了uistudio工具，通过工具可以实现界面的可视化编辑。整个应用的开发，实现了视图和逻辑的分离。
* TUI内核不单单包含了GUI的相关功能和丰富控件，里面实现了消息机制、定时器、多国语言、资源的打包、编码转换、串口接口，时间等。
* TUI的设计非常严谨，可以把它看成一个非常独立的模块，TUI整个生命周期由三步，初始化（tui_start_init）、运行（tui_run_loop）、销毁（tui_end_uninit）三个函数控制。

---

## 目录介绍：
* apps			文件夹，里面存放了用户的逻辑代码，其中每个app里面的view视图代码是uistudio工具自动生成。
* includes	文件夹，里面存放了TUI接口函数头文件tui.h；用户自定义消息枚举sys_msg_def.h；uistudio工具生成的空间ID文件tui_id.h；跨平台头文件stdxxx.h。
* platform	文件夹，里面存放各个平台的工程编译入口文件夹（melis、eos、vc++）。
* res				文件夹，里面存放app开发的资源 字体、图片、多国语言、视图布局结构、声音等其它应用资源。
* uistudio	文件夹，里面存放所见即所得工具所需要的文件。
* res.disk	文件	，该文件是把uistudio工具把res里面的资源处理、打包后的一个资源集合，最后被映射到tui内核里面，成为一个V:盘符。

## 应用介绍：
由于个人开发时间比较仓促，应用里面的所有图片均来自互联网，没有经过特殊处理（不用于商业用途），图片稍加利用，来实现TUI的接口功能。下面我们队每个app一一做个简单的介绍，然后结合tui.h里面的接口做相关说明。
<p align="center">
<img src="https://github.com/TUISYS/image/blob/main/home.gif">
</p>
<p align="center">
所有APP应用例子展示
</p>

### 弧形应用（arc_app0）
todo
### 按钮应用（button_app1）
todo
### 直线应用（line_app2）
todo
### 滑条应用（bar_app3）
todo
### 动画应用（animation_app4）
todo
### 表盘应用（dashboard_app5）
todo
### 窗口应用（window_app6）
todo
### 串口应用（serial_app7）
todo
### 页容器应用（page_app8）
todo
### 画板应用（draw_app9）
todo
### 设置应用（setting_app10）
todo
### 登陆应用（logon_app11）
todo

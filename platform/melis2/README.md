<h1 align="center"> 全志MELIS2.0嵌入式平台说明 </h1>

## 注意事项：
* 将:file_folder:tui_project工程文件夹，放到melis应用路径下面`.\livedesk\beetles`。
* 支持`F1C100s`、`F1C200s`等平台
* 通过`cygwin`，`cd`进入`.\tui_project\platform\melis`执行命令`make clean;make`。
* 在根目录`tui_project`下会生成`app_tui.axf`，该文件是melis嵌入式系统的可执行文件。
* 在app_tui()函数调用应用接口的时候会把res.disk资源路径传进去
* 把生成的`app_tui.axf`和`res.disk`放进U盘，执行命令`run F:/app_tui.axf`，就可以运行看到效果了。<br>
（注意`home_create`函数里面对资源路径的设置`tui_start_init("F:\\res.disk", -1, -1);`）。

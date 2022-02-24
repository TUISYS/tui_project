<h1 align="center"> 微软Windows系统平台说明 </h1>

## 注意事项：
* 保证安装了`VS2013`或者以上平台的`Visual Studio`。
* 将:file_folder:tui_project工程文件夹，放到Windows盘符里面。
* 双击VC++工程文件`tui_project/platform/vc++/tui_demo.vcxproj`
* 默认工程视图里面有基础文件`main.c`、`stdxxx.h`、`sys_msg_def.h`、`tui.h`、`tui_id.h`。<br>
开发者可以根据UIStudio创建视图和逻辑代码，自己手动添加代码`.c`文件进入工程视图里面。
* 几个关键的库文件：TUI内核库`tui.lib`；Windows显示和输入库`SDL2.lib、SDL2main.lib`。
* 最后正常编译调试。
* 在使用`VS2015`编译的时候会报这样的错误`tui.lib(stdxxx.obj) : error LNK2001: 无法解析的外部符号 __imp__vprintf`，<br>
这时候需要在`属性`->`链接器`->`输入`->`附加依赖项`里面添加`legacy_stdio_definitions.lib`即可

## 演示操作动画：
<br>
<br>
<p align="center">
<img src="https://raw.githubusercontent.com/TUISYS/image/main/hello_vc.gif">
</p>
<br>
<p align="center">
动画链接：（https://gitee.com/tuisys/image/raw/main/hello_vc.gif）
</p>


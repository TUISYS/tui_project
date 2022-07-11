<h1 align="center"> 全志MELIS4.0 小系统平台说明 </h1>

## 注意事项：
* 将:file_folder:tui_project工程文件夹，放到melis4 SDK路径下面`.\source\emodules\`。
* 注意查看`MakeFile`对应的路径修改，需要根据自己平台的SDK适当调整；
* `melis4/lib/libtui.a`库文件需要放到Melis4 SDK存放库文件夹的目录`source\elibrary\bin`
* 把生成的`app_tui.mod`和`res.disk`放进盘符执行；
* 在tui_run()函数调用应用接口的时候会把res.disk资源路径传进去；
* 全志`F133`芯片验证通过；
* 记得把系统的`logo图层`删除了，不然UI图层申请失败，不能显示。
```
#头文件路径，定义AW_MELIS和AW_MELIS4宏定义
ccflags-y   +=  -I$(srctree)/emodules/tui_project/includes\
                -DAW_MELIS
ccflags-y   +=  -DAW_MELIS4

#定义生成的文件路径
MOD_NAME := ftest
SUF_NAME := mod
PRJ_PATH := $(srctree)/projects/${TARGET_BOARD}/data/UDISK/mod/
TEMP_PATH := $(srctree)/emodules/staging
```

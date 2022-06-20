<h1 align="center"> 全志MELIS4.0 小系统平台说明 </h1>

## 注意事项：
* 注意查看`MakeFile`对应的路径修改，需要根据自己平台的SDK适当调整
* 支持`F133`芯片
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

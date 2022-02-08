<h1 align="center"> 直线控件app </h1>

## 介绍：
这个app里面有直线控件、按钮控件动画的使用。

<p align="center">
<img src="https://gitee.com/tuisys/image/raw/main/line.gif">
</p>
<p align="center">
各个控件应用例子展示
</p>

## TUI接口介绍：
该应用比较简单，通过按钮改变线的位置，粗细等。

### * 直线控件
TUI提供的直线由抗锯齿的算法，直线控件的使用比较简单，开发者可以根据自的需求，设置直线控件的属性，线宽、颜色和位置。

### * 图片按钮控件
主要用了设置线的粗细，通过对应的接口函数设置可移动，来移动线的位置
``` c
tui_obj_set_ext_click_area(btn1_obj, 20, 20, 20, 20);
tui_obj_set_border_radius(btn1_obj, 0x7fff);
tui_obj_set_drag_dir(btn1_obj, TUI_DRAG_DIR_BOTH);
```
上面三个接口函数设置按钮的属性，第一个扩大触摸范围，第二个设置角弧度，第三设置按钮可以拖拽移动，从而设置线的坐标。



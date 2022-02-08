<h1 align="center"> 表盘动画控件app </h1>

## 介绍：
这个app里面有图片控件、按钮控件、标签控件的使用。

<p align="center">
<img src="https://gitee.com/tuisys/image/raw/main/dashboard.gif">
</p>
<p align="center">
各个控件应用例子展示
</p>

## TUI接口介绍：
该应用大量使用图片控件的动画接口，图片指针的旋转、缩放、宽缩放动画，高缩放动画等

### * 图片控件
``` c
img_obj = tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_60);
if (img_obj) {
	tui_image_set_angle(img_obj, (int16_t)param0, true);
}
//tui_image_set_rotation_center_coor(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 250, 191);
//tui_image_anim_zoom(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 64, 256, TUI_ANIM_PATH_OVERSHOOT, NULL);
//tui_image_anim_angle(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 360, 0, TUI_ANIM_PATH_OVERSHOOT, NULL);
//tui_image_anim_width(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 1000, 500, TUI_ANIM_PATH_OVERSHOOT, NULL);
tui_image_anim_height(tui_get_obj_from_id(this_app_obj, DASHBOARD_APP5_DASHBOARD_VIEW_IMAGE_59), 1500, 766, 383, TUI_ANIM_PATH_OVERSHOOT, NULL);
```
上面大量调用了图片动画接口，当开发过程中需要查看相关的效果，可以打开其中的注释就会看到对应的动画效果。



<h1 align="center"> 窗口控件app </h1>

## 介绍：
这个app里面有视图控件、控件动画、标签控件、以及定时器的使用。

<p align="center">
<img src="https://s1.imagehub.cc/images/2022/06/16/windows.gif">
</p>
<p align="center">
各个控件应用例子展示
</p>

## TUI接口介绍：
该应用是窗口的创建以及使用，TUI内核没有提供专一的窗口控件，因为作者考虑到窗口的复杂和多样性，无法做一个集所有功能的窗口控件。TUI的核心是积木化编程，这样更加自由，扩展性很强。该应用就极好的体现了窗口灵活使用，创建和操作都比较简单

### * 创建窗口视图控件
这里需要注意的是，创建特殊置顶的窗口，其它控件disable
``` c
this_wind1_obj = window_app6_window1_view_view_create();
tui_obj_set_parent(this_wind1_obj, tui_layer_top());
tui_obj_set_click(tui_layer_top(), 1);
tui_obj_set_alpha(this_app_obj, 128);
```
窗口销毁的时候需要恢复原始状态
``` c
tui_obj_del(this_wind1_obj);
this_wind1_obj = NULL;
tui_obj_set_click(tui_layer_top(), 0);
tui_obj_set_alpha(this_app_obj, 255);
```

### * 触摸监控
通过注册回调函数```indev_point_trigger_cb_reg(window_app6_indev_point_trigger_cb);```，可以实时回去触摸的坐标和状态。
``` c
static void window_app6_indev_point_trigger_cb(uint8_t state, int32_t x, int32_t y)
{
	if (this_wind4_obj && state == 1) {
		tui_area_t cords;

		tui_obj_get_coords(this_wind4_obj, &cords);

		if (!(x > cords.x1 && x < cords.x2 && y > cords.y1 && y < cords.y2)) {
			tui_obj_del(this_wind4_obj);
			this_wind4_obj = NULL;
		}
	}
}
```



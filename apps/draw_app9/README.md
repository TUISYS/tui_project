<h1 align="center"> 画板控件app </h1>

## 介绍：
这个app里面只有画板控件的使用。

<p align="center">
<img src="https://github.com/TUISYS/image/blob/main/draw.gif">
</p>
<p align="center">
画板控件应用例子展示
</p>

## TUI接口介绍：
该应用提供了画板的接口使用，主要是由于绘画

### * 画板控件
画板控件提供了丰富的绘画接口，能画各种几何图形，能改变颜色，线条的粗细等
``` c
tui_canvas_fill_bg(this_draw_obj, TUI_ARGB_COLOR_MAKE(0x3f, 0xff, 0xff, 0));
tui_canvas_draw_pixel(this_draw_obj, 15, 15, TUI_ARGB_COLOR_MAKE(0xff, 0, 0, 0));
tui_canvas_draw_line(this_draw_obj, points, 3, 2, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0, 0));
tui_canvas_draw_line(this_draw_obj, points_r, 5, 10, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0, 0));
tui_canvas_draw_rect(this_draw_obj, 50, 150, 150, 150, TUI_ARGB_COLOR_MAKE(0xff, 0, 0xff, 0));
tui_canvas_draw_polygon(this_draw_obj, points_t, 3, TUI_ARGB_COLOR_MAKE(0xff, 0, 0, 0xff));
tui_canvas_draw_arc(this_draw_obj, 200, 100, 100, 0, 360, 2, TUI_ARGB_COLOR_MAKE(0xff, 0, 0xff, 0xff));
tui_canvas_draw_text(this_draw_obj, 100, 200, "hello2345", 60, TUI_ARGB_COLOR_MAKE(0xff, 0xff, 0xff, 0));
tui_canvas_draw_img(this_draw_obj, 20, 20, "V:/image/10.bin");
```




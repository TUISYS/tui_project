<h1 align="center"> 弧形控件和图片控件app </h1>

## 介绍：
这个app里面有弧形控件、图片控件动画、标签控件、以及定时器的使用。

<p align="center">
<img src="https://github.com/TUISYS/image/blob/main/arc.gif">
</p>
<p align="center">
各个控件应用例子展示
</p>

## TUI接口介绍：

### 弧形控件
```c
static void arc_loader(tui_timer_t * t);
static void arc_loader2(tui_timer_t * t);
```
通过定时器，每10ms执行一次，最后通过TUI接口函数
```c
void tui_arc_set_angles(tui_obj_t * arc, uint16_t start, uint16_t end);
```
设置弧形的开始和结束的角度，其中角度的顺序如下：
```c
          .0
 
 
 .270            .90
 
 
          .180
 ```
 
### 标签控件
```c
tui_label_set_txt(txt_obj, txt_str);
```
通过TUI标签接口函数，实现标签的文本动态变化

### 定时器
```c
this_timer = tui_timer_create(arc_loader, 10, TUI_TIMER_PRIO_LOWEST, NULL);
this_timer2 = tui_timer_create(arc_loader2, 10, TUI_TIMER_PRIO_LOWEST, NULL);
this_timer3 = tui_timer_create(num_anim, 2000, TUI_TIMER_PRIO_LOWEST, NULL);
```
进入APP里面创建了3个定时器，前两个分别用于弧形旋转，最后一个用于数字图片翻页动画

### 数字图片翻页动画
```c
static void arc_app0_show_num2(int num)
```
该函数实现了翻页动画，传进来的参数num是要显示的数字
```c
tui_image_anim_height(img_0u_2, 800, 135, 0, TUI_ANIM_PATH_LINEAR, arc_app0_anim2_cb);
tui_obj_anim_mov_y(img_0u_2, 800, 300, 300 + 135, TUI_ANIM_PATH_LINEAR, NULL);
```
这两个TUI接口函数，配合使用，实现了图片的翻页效果


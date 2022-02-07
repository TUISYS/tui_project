<h1 align="center"> 动画控件app </h1>

## 介绍：
这个app里面有三种动画效果图片控件动画、animation控件动画、以及gif控件的使用。

<p align="center">
<img src="https://raw.githubusercontent.com/TUISYS/image/main/animation.gif">
</p>
<p align="center">
各个动画控件应用例子展示
</p>

## TUI接口介绍：
TUI提供了丰富的动画接口函数和动画控件对象，可以做很多动画效果。

### * 图片控件动画
图片控件很简单，设置好不同图片到数组里面和时间间隔，就可以通过对应的接口控制。
``` c
tui_image_stop_anim(img_obj);
tui_image_start_anim(img_obj, attri.anim_time, attri.mode);
```

### * animation控件动画
animation控件和图片控件类似，但是功能更强大，它可以编译每一帧的时间和坐标，animation类似一个容器，里面每一帧播放对应的图片，可以通过对应的接口控制。
``` c
tui_animation_start_anim(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_ANIMATION_207), 1);
tui_animation_stop_anim(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_ANIMATION_207));
```

### * gif文件控件动画
tui支持gif动画文件，并且支持动画里面关键颜色“绿色”透明的处理、同样也支持播放、暂停、循环播放等
``` c
tui_gif_play(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_228));
tui_gif_pause(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_228));
tui_gif_restart(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_229));
```

### * object移动动画效果
tui里面所有对象是基础object的，所以也可以通过object的动画接口函数实现控件的动画，在这个应用中通过控制x、y的坐标实现动画
``` c
tui_obj_anim_mov_x(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_229), 1000, -80, 90, TUI_ANIM_PATH_OVERSHOOT, NULL);
tui_obj_anim_mov_y(tui_get_obj_from_id(this_app_obj, ANIMATION_APP4_ANIMATION_VIEW_GIF_229), 1000, -80, 280, TUI_ANIM_PATH_OVERSHOOT, NULL);
```




<h1 align="center"> 页控件app </h1>

## 介绍：
这个app里面有页控件，里面嵌套了不同的控件，展示其效果。

<p align="center">
<img src="https://s1.imagehub.cc/images/2022/06/16/page.gif">
</p>
<p align="center">
各个控件应用例子展示
</p>

## TUI接口介绍：
页控件可以理解是一个容器，里面可以存放不同类型的控件

### * 页控件
页控件里面如果放置按钮，需要通过函数``` c tui_obj_set_glue_obj(tui_get_obj_from_id(this_app_obj, PAGE_APP8_PAGE_VIEW_IMAGE_BTN_236), 1); ```设置和页控件进行粘连。不然拖拽移动到按钮上的时候会出现断层。

### * 二维码控件
二维码控件比较简单，可以查看其接口函数，设置二维码的颜色、大小、和内容等。



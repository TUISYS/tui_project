<h1 align="center"> 登陆界面、输入法和表格控件app </h1>

## 介绍：
这个app里面使用了比较多得控件主要有文本输入框控件、复选框控件、表格控件、以及标签中文输入发的使用。

<p align="center">
<img src="https://i.postimg.cc/SN2GW316/logon.gif">
</p>
<p align="center">
各个控件应用例子展示
</p>

## TUI接口介绍：
该应用有普通输入框和密码输入框，然后还支持中文输入法，表格控件功能也很丰富。

### * 文本输入框控件
文本输入框控件，支持英文的输入，通过控制```pwd_able```属性设置是否是密码输入模式；还可以通过```accepted_chars```属性设置可以输入的字符串限制。
该控件比较简单，可以查看其接口函数，实际操作使用。

### * 复选框控件
TUI提供了常用得复选框控件，点击触发改变值得时候，会调用其回调函数，应用就可以判断0、1知道其状态。
该控件比较简单，可以查看其接口函数，实际操作使用。

### * 表格控件
变格控件是一个比较复杂的控件，控件里面的每一个单元格是一个标签，可以通过其接口设置不同单元格的属性。
``` c
excel_obj = tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_EXCEL_208);
tui_excel_get_attri(excel_obj, &excel_attri);
tui_excel_set_cell_text(excel_obj, 0, 0, "", 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
tui_excel_set_cell_text(excel_obj, 0, 1, "A", 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
tui_excel_set_cell_text(excel_obj, 0, 2, "B", 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
for (i = 1; i < excel_attri.rows; i++) {
	sprintf(str, "%d", i);
	tui_excel_set_cell_text(excel_obj, i, 0, str, 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
}
```

### * 标签中文输入发
标签控件（label），可以是静态的控件，也可以是动态的。如果是动态的需要设置其属性```input_able```，如果这个属性是1，点击label的时候，会触发输入法，这时可以用用来做中英文输入。





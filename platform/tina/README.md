<h1 align="center"> 全志TINA系统平台说明 </h1>

## 注意事项：
* 注意查看`MakeFile`编译链路径，需要根据自己的SDK路径修改，需改好后就可以`make clean`或者`make`，就可以得到相应的可执行文件`tui_demo`
当前编译链的路径是~~“CC        = /home/tina/f133/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc”~~（根据自己的SDK，要修改成自己对应的）
* 目前编译链使用`全志D1`平台的`RISCV64芯片`的编译链工具
* 在main()函数调用应用接口的时候会把res.disk资源路径传进去
* 显示部分采用`"/dev/fb0"`
* 触摸部分采用`"/dev/input/event0"`

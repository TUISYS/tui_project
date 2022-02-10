<h1 align="center"> 串口收发功能 </h1>

## 串口概述：
TUI实现了串口跨平台的接口函数，通过下面的函数可以实现不同平台的串口收发：
``` c
typedef int(*serial_port_read_cb_t)(const char *read_buff, int buf_len);
int serial_port_open(char *com_name, int baudrate, int bytesize, int parity, int stopbits, serial_port_read_cb_t read_cb);
void serial_port_close(void);
int serial_port_write(char *write_buff, int buf_len);
```

## 应用说明：
重点说明下`serial_port_open`函数，打开串口驱动。其中参数`COM6`主要是兼容Windows里面的设备名，默认`-1`是UIStudio工具里面填写的串口参数，`serial_port_read_cb`是串口读回调函数。
``` c
serial_port_open("COM6", -1, -1, -1, -1, serial_port_read_cb);
```

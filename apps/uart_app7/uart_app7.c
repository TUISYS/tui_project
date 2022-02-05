#include "tui.h"

static tui_obj_t * this_app_obj;
static char * uart_string;
char send_txt[256] = { 0 };

static void uart_app7_exit(void);
tui_obj_t * uart_app7_uart_view_view_create(void);

/*
* 串口接收数据回调函数
*/
static int serial_port_read_cb(const char *read_buff, int buf_len)
{
	tui_obj_t * obj;
	int i, len, cnt;

	len = strlen(uart_string);
	cnt = 0;
	for (i = 0; i < buf_len; i++) {
		if (read_buff[i] != '\0' && read_buff[i] != '\r') {
			uart_string[len + cnt] = read_buff[i];
			uart_string[len + cnt + 1] = '\0';
			cnt++;
		}
	}
	obj = tui_get_obj_from_id(this_app_obj, UART_APP7_UART_VIEW_LABEL_241);
	tui_label_set_txt(obj, uart_string);

	return 0;
}

static int32_t uart_app7_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_obj_t * obj;

	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		uart_app7_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;

	case TUI_USER_MSG_APP7_SEND:
		obj = tui_get_obj_from_id(this_app_obj, UART_APP7_UART_VIEW_TEXTBOX_242);
		send_txt[0] = '\0';
		strcpy(send_txt, tui_textbox_get_text((const tui_obj_t *)obj));
		strcat(send_txt, "\n");

		tui_textbox_set_text(obj, "");
		obj = tui_get_obj_from_id(this_app_obj, UART_APP7_UART_VIEW_LABEL_241);
		strcat(uart_string, send_txt);
		tui_label_set_txt(obj, uart_string);

		serial_port_write(send_txt, strlen(send_txt));
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * uart_app7_enter(void)
{
	uart_string = malloc(1024*1024);
	if (uart_string) {
		uart_string[0] = '\0';
	}
	/* 初始化硬件串口 */
	serial_port_open("COM6", -1, -1, -1, -1, serial_port_read_cb);

	tui_sys_msg_reg(uart_app7_sys_msg_cb);

	this_app_obj = uart_app7_uart_view_view_create();

	return this_app_obj;
}

static void uart_app7_exit(void)
{
	tui_sys_msg_unreg(uart_app7_sys_msg_cb);

	/* 关闭硬件串口 */
	serial_port_close();

	if (uart_string) {
		free(uart_string);
	}
}

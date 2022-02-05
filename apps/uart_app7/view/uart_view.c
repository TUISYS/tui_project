#include "tui.h"



tui_obj_t *uart_app7_uart_view_view_obj;

static void button_243_cb_243(tui_obj_t *obj, tui_event_e event) {
	 /* obj 按键对象 */
	 /* event 按键按下和抬起的状态事件值 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP7_SEND, NULL, NULL);
}

static tui_map_cb_t cb_map[] = {
	{ UART_APP7_UART_VIEW_BUTTON_243, (void*)button_243_cb_243 },
	{ 0, (void*)0 }
};

tui_obj_t * uart_app7_uart_view_view_create(void){
	uart_app7_uart_view_view_obj = 0;
	uart_app7_uart_view_view_obj = tui_view_create("V:/layout/uart_app7/uart_view.bin", cb_map);
	return uart_app7_uart_view_view_obj;
}

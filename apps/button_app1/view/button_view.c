#include "tui.h"



tui_obj_t *button_app1_button_view_view_obj;
static void image_btn_212_cb_212(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj ͼƬ�������� */
	 /* event ͼƬ�������¼������¡�̧���Լ��仯��״ֵ̬ */
	 /* img_index ��ǰͼƬ������ֵ */
}

 

static void button_34_cb_34(tui_obj_t *obj, tui_event_e event) {
	 /* obj �������� */
	 /* event �������º�̧���״̬�¼�ֵ */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP1_BTN1, NULL, NULL);
}


static void button_35_cb_35(tui_obj_t *obj, tui_event_e event) {
	 /* obj �������� */
	 /* event �������º�̧���״̬�¼�ֵ */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP1_BTN2, NULL, NULL);
}


static void button_36_cb_36(tui_obj_t *obj, tui_event_e event) {
	 /* obj �������� */
	 /* event �������º�̧���״̬�¼�ֵ */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP1_BTN3, NULL, NULL);
}


static void image_btn_38_cb_38(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj ͼƬ�������� */
	 /* event ͼƬ�������¼������¡�̧���Լ��仯��״ֵ̬ */
	 /* img_index ��ǰͼƬ������ֵ */
	if (event == TUI_EVENT_RELEASED || TUI_EVENT_LONG_PRESSED_REPEAT == event)
		tui_sys_msg_send(TUI_USER_MSG_APP1_BTN_IMG1, NULL, NULL);
}


static void image_btn_39_cb_39(tui_obj_t *obj, tui_event_e event, int16_t img_index) {
	 /* obj ͼƬ�������� */
	 /* event ͼƬ�������¼������¡�̧���Լ��仯��״ֵ̬ */
	 /* img_index ��ǰͼƬ������ֵ */
	if (event == TUI_EVENT_RELEASED || TUI_EVENT_LONG_PRESSED_REPEAT == event)
		tui_sys_msg_send(TUI_USER_MSG_APP1_BTN_IMG2, NULL, NULL);
}

static void switch_btn_42_cb_42(tui_obj_t *obj, tui_event_e event, int16_t value) {
	 /* obj �л����ض��� */
	 /* event �л����ص��¼�ֵ*/
	 /* value �л����ص�ֵ��ֵ��0����1 */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP1_SWITCH, (void*)value, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ BUTTON_APP1_BUTTON_VIEW_BUTTON_34, (void*)button_34_cb_34 },
	{ BUTTON_APP1_BUTTON_VIEW_BUTTON_35, (void*)button_35_cb_35 },
	{ BUTTON_APP1_BUTTON_VIEW_BUTTON_36, (void*)button_36_cb_36 },
	{ BUTTON_APP1_BUTTON_VIEW_IMAGE_BTN_38, (void*)image_btn_38_cb_38 },
	{ BUTTON_APP1_BUTTON_VIEW_IMAGE_BTN_39, (void*)image_btn_39_cb_39 },
	{ BUTTON_APP1_BUTTON_VIEW_SWITCH_BTN_42, (void*)switch_btn_42_cb_42 },
	{ BUTTON_APP1_BUTTON_VIEW_IMAGE_BTN_212, (void*)image_btn_212_cb_212 },
	{ 0, (void*)0 }
};

tui_obj_t * button_app1_button_view_view_create(void){
	button_app1_button_view_view_obj = 0;
	button_app1_button_view_view_obj = tui_view_create("V:/layout/button_app1/button_view.bin", cb_map);
	return button_app1_button_view_view_obj;
}

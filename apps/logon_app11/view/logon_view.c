#include "tui.h"



tui_obj_t *logon_app11_logon_view_view_obj;

static void excel_208_cb_208(tui_obj_t *obj, tui_event_e event, uint32_t column, uint32_t row) {
	 /* obj ������ */
	 /* event ����¼�ֵ */
	 /* column �� */
	 /* row��  */
}



static void checkbox_178_cb_178(tui_obj_t *obj, tui_event_e event, int32_t value) {
	 /* obj ��ѡ����� */
	 /* event ��ѡ����¼�ֵ*/
	 /* value ��ѡ���ֵ��0����1 */
	tui_obj_t *textbox_obj;

	textbox_obj = tui_get_obj_from_id(logon_app11_logon_view_view_obj, LOGON_APP11_LOGON_VIEW_TEXTBOX_177);
	if (textbox_obj)
		tui_textbox_set_pwd_mode(textbox_obj, !value);
}



static void button_180_cb_180(tui_obj_t *obj, tui_event_e event) {
	 /* obj �������� */
	 /* event �������º�̧���״̬�¼�ֵ */
	if (event == TUI_EVENT_RELEASED)
		tui_sys_msg_send(TUI_USER_MSG_APP11_SUBMIT, NULL, NULL);
}
static tui_map_cb_t cb_map[] = {
	{ LOGON_APP11_LOGON_VIEW_CHECKBOX_178, (void*)checkbox_178_cb_178 },
	{ LOGON_APP11_LOGON_VIEW_BUTTON_180, (void*)button_180_cb_180 },
	{ LOGON_APP11_LOGON_VIEW_EXCEL_208, (void*)excel_208_cb_208 },
	{ 0, (void*)0 }
};

tui_obj_t * logon_app11_logon_view_view_create(void){
	logon_app11_logon_view_view_obj = 0;
	logon_app11_logon_view_view_obj = tui_view_create("V:/layout/logon_app11/logon_view.bin", cb_map);
	return logon_app11_logon_view_view_obj;
}

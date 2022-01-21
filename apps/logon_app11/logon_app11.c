#include "tui.h"

static tui_obj_t * this_app_obj;
static uint32_t submit_cnt;

static void logon_app11_exit(void);
tui_obj_t * logon_app11_logon_view_view_create(void);

static int32_t logon_app11_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	tui_excel_attri_t excel_attri;
	tui_obj_t *excel_obj;

	printf("logon_app11 system message:0x%x\n", cmd);
	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		logon_app11_exit();
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP11_SUBMIT:
		excel_obj = tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_EXCEL_208);
		tui_excel_get_attri(excel_obj, &excel_attri);
		if (submit_cnt < excel_attri.rows) {
			tui_excel_set_cell_text(excel_obj, submit_cnt, 1, tui_textbox_get_text(tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_TEXTBOX_176)), 30, TUI_ARGB_COLOR_MAKE(0xff, 0, 0, 0), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0);
			tui_textbox_set_text(tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_TEXTBOX_176), "");
			tui_excel_set_cell_text(excel_obj, submit_cnt, 2, tui_textbox_get_text(tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_TEXTBOX_177)), 30, TUI_ARGB_COLOR_MAKE(0xff, 0, 0, 0), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0);
			tui_textbox_set_text(tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_TEXTBOX_177), "");
			submit_cnt++;
		}
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * logon_app11_enter(void)
{
	uint32_t i;
	tui_excel_attri_t excel_attri;
	tui_obj_t *excel_obj;
	char str[10];

	tui_sys_msg_reg(logon_app11_sys_msg_cb);

	this_app_obj = logon_app11_logon_view_view_create();

	tui_label_set_align_mid(tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_LABEL_230), 1);

	submit_cnt = 1;
	excel_obj = tui_get_obj_from_id(this_app_obj, LOGON_APP11_LOGON_VIEW_EXCEL_208);
	tui_excel_get_attri(excel_obj, &excel_attri);
	tui_excel_set_cell_text(excel_obj, 0, 0, "", 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
	tui_excel_set_cell_text(excel_obj, 0, 1, "A", 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
	tui_excel_set_cell_text(excel_obj, 0, 2, "B", 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
	for (i = 1; i < excel_attri.rows; i++) {
		sprintf(str, "%d", i);
		tui_excel_set_cell_text(excel_obj, i, 0, str, 30, TUI_ARGB_COLOR_MAKE(0xff, 0x7f, 0x7f, 0x7f), TUI_LABEL_ALIGN_CENTER, TUI_LABEL_LONG_SROLL_CIRC, 0xFFDFDFDF);
	}

	return this_app_obj;
}

static void logon_app11_exit(void)
{
	tui_sys_msg_unreg(logon_app11_sys_msg_cb);
}
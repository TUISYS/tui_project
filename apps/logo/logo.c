#include "tui.h"

/*
 * �ֲ���������
 */
static tui_obj_t * this_app_obj;


/*
 * ��ͼ��������
 */
extern tui_obj_t * logo_logo_view_view_create(void);


/*
 * APPϵͳ��Ϣ���ջص�����
 */
static int32_t logo_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	switch (cmd)
	{
	// TODO
	default:
		break;
	}
	return 0;
}


/*
 * APP�˳��ص�����
 */
static void logo_exit(void)
{
	/* ж��ע�����Ϣ���պ�������ͼɾ������վ�� */
	tui_sys_msg_unreg(logo_sys_msg_cb);
	this_app_obj = NULL;
}


/*
 * APP��ں��������ⲿ���ã����ص�ǰobject��
 */
tui_obj_t * logo_enter(void)
{
	/* ע����Ϣ���պ��� */
	tui_sys_msg_reg(logo_sys_msg_cb);

	/* ������ͼ������ͼɾ�����ִ�лص����� */
	this_app_obj = logo_logo_view_view_create();
	tui_obj_set_del_cb(this_app_obj, logo_exit);

	/* ������ͼ��� */
	return this_app_obj;
}


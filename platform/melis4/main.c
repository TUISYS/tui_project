#ifdef AW_MELIS4

#include <kapi.h>

int home_create(char *res_path);

void tui_run(void)
{
	home_create("F:\\res.disk");

	/* kill app_tui self */
	esEXEC_PDel(EXEC_pidself);

	/* del app_tui main thread */
	eLIBs_printf("app_tui thread: Bye Bye!\n");

	esKRNL_TDel(OS_PRIO_SELF);

	esKRNL_TimeDly(100);
}
#endif

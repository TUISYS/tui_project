#ifdef AW_MELIS4
#include "tui.h"

int home_create(void);
void tui_run(void)
{
	home_create();
	
	/* kill app_tui self */
	esEXEC_PDel(EXEC_pidself);

	/* del app_tui main thread */
	printf("app_tui thread: Bye Bye!\n");

	esKRNL_TDel(OS_PRIO_SELF);

	esKRNL_TimeDly(100);
}
#endif

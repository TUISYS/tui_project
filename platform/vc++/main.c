#ifdef WIN32
#include "tui.h"

extern int home_create(void);

int main(int argc, char** argv)
{
	/* 为UIStudio模拟显示使用 */
	if (argc > 2) {
		tui_start_init(argv[1]);

		tui_view_create(argv[2], NULL);

		while (1) {
			tui_run_loop();
		}

		tui_end_uninit();
	}

	home_create("../../res.disk");

	return 0;
}
#endif

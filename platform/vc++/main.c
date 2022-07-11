#ifdef WIN32
#include "tui.h"

extern int home_create(char *res_path);

int main(int argc, char** argv)
{
	/* 为UIStudio模拟显示使用 */
	if (argc > 2) {
		/* 使能TUI组件，用户不用关心 */
#ifdef TUI_COMPONENT_ENABEL
		tui_com_reg_func_map();
#endif
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

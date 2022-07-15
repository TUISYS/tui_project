#include "tui.h"

#define LIST_MAX	512

typedef struct fs_item_info_tag {
	int type;
	char name[64];
} fs_item_info_t;

static tui_obj_t * this_app_obj;
static tui_obj_t * this_app_list_obj;
static tui_timer_t * this_app_fs_timer;
static char cur_path[256];
static fs_item_info_t fs_items[LIST_MAX];
static int fs_items_num;
static int fs_items_cnt;

static void setting_app10_exit(void);
tui_obj_t * setting_app10_setting_view_view_create(void);

static int setting_get_fs_item_cmp(fs_item_info_t item1, fs_item_info_t item2)
{
	int len1, len2;

	if (item1.type > item2.type)
		return 1;
	else if (item1.type < item2.type)
		return 0;
	else {
		len1 = strlen(item1.name);
		len2 = strlen(item2.name);
		if (len1 < len2)
			return 1;
		else if (len1 > len2)
			return 0;
		else {
			if (strcmp(item1.name, item2.name) < 0)
				return 1;
			else
				return 0;
		}
	}
}

static int setting_get_fs_items(char *path)
{
	int ret = -1;
	STD_DIR *dir = NULL;
	STD_DIRENT *ptr = NULL;
	int i, j;
	fs_item_info_t temp;

	dir = opendir(path);
	if (dir == NULL) {
		return -1;
	}

	fs_items_num = 0;

	while ((ptr = readdir(dir)) != NULL) {
		if (strcmp(ptr->d_name, "..") == 0)
			continue;
		else if (strcmp(ptr->d_name, ".") == 0)
			continue;

		strncpy(fs_items[fs_items_num].name, ptr->d_name, 47);

		if (ptr->fatdirattr == 0x10)
			fs_items[fs_items_num].type = 1;
		else
			fs_items[fs_items_num].type = 0;

		fs_items_num++;

		if (fs_items_num >= LIST_MAX) {
			printf("setting_get_fs_items over %d\n", LIST_MAX);
			break;
		}
	}

	closedir(dir);

	for (i = 0; i < fs_items_num - 1; i++) {
		for (j = 0; j < fs_items_num - 1 - i; j++) {
			if (setting_get_fs_item_cmp(fs_items[j], fs_items[j + 1]) == 0) {
				memcpy(&temp, &fs_items[j], sizeof(fs_item_info_t));
				memcpy(&fs_items[j], &fs_items[j + 1], sizeof(fs_item_info_t));
				memcpy(&fs_items[j + 1], &temp, sizeof(fs_item_info_t));
			}
		}
	}

	return ret;
}

static int setting_refresh_list_files(tui_obj_t * list_obj, char *path)
{
	tui_list_remove_all(list_obj);

	setting_get_fs_items(path);

	fs_items_cnt = 0;
	
	return 0;
}

static void setting_fs_items_loader(tui_timer_t * t)
{
	tui_obj_t * btn;
	tui_obj_t * label;
	tui_obj_t * image;
	tui_button_attri_t attri = { 0 };
	tui_label_attri_t attri_label = { 0 };
	tui_image_attri_t attri_img = { 0 };
	char utf8_str[128];
	tui_obj_t * list_obj;

	list_obj = (tui_obj_t *)tui_timer_get_user_data(t);

	if (fs_items_cnt < fs_items_num) {
		btn = tui_button_create(list_obj);
		attri.obj.size.width = 305;
		attri.obj.size.height = 60;
		tui_button_set_attri(btn, &attri);

		label = tui_label_create(btn);
		attri_label.obj.pt.x = 38;
		attri_label.obj.pt.y = 15;
		attri_label.obj.size.width = 305 - 80;
		attri_label.obj.size.height = 60;
		tui_gb2312_to_utf8(utf8_str, 128, fs_items[fs_items_cnt].name, strlen(fs_items[fs_items_cnt].name));
		attri_label.txt = utf8_str;
		attri_label.ttf_font = 1;
		attri_label.fnt_size = 30;
		attri_label.mode = TUI_LABEL_LONG_DOT;

		if (fs_items[fs_items_cnt].type) {
			image = tui_image_create(btn);
			attri_img.obj.pt.x = 1;
			attri_img.obj.pt.y = 10;
			tui_image_set_attri(image, &attri_img);
			tui_image_set_image_src(image, 0, "V:/image/32.bin");		/* 确保加载了res.iso，并且路径文件存在 */
			tui_image_set_cur_img_index(image, 0);
			attri_label.fnt_color = 0xff0000ff;
		}
		else {
			image = tui_image_create(btn);
			attri_img.obj.pt.x = 1;
			attri_img.obj.pt.y = 10;
			tui_image_set_attri(image, &attri_img);
			tui_image_set_image_src(image, 0, "V:/image/42.bin");		/* 确保加载了res.iso，并且路径文件存在 */
			tui_image_set_cur_img_index(image, 0);
			attri_label.fnt_color = 0xff000000;
		}

		tui_label_set_attri(label, &attri_label);
		tui_list_add_btn(btn);

		fs_items_cnt++;
	} else {
		tui_timer_del(this_app_fs_timer);
		this_app_fs_timer = NULL;
	}
}

static int32_t setting_app10_sys_msg_cb(uint32_t cmd, void *param0, void *param1)
{
	char *tmp_str;
	int index;

	switch (cmd)
	{
	case TUI_USER_MSG_APP_BACK:
	case TUI_USER_MSG_APP_HOME:
		tui_sys_msg_send(TUI_USER_MSG_APP_ENTER_HOME, NULL, NULL);
		break;
	case TUI_USER_MSG_APP10_LANG:
		tui_label_set_txt(tui_get_obj_from_id(this_app_obj, SETTING_APP10_SETTING_VIEW_LABEL_194), tui_get_language_utf8_string("STR_SETTINGS_SYSTEM"));
		tui_label_set_txt(tui_get_obj_from_id(this_app_obj, SETTING_APP10_SETTING_VIEW_LABEL_198), tui_get_language_utf8_string("STR_SETTINGS_BRIGHT"));
		break;
	case TUI_USER_MSG_APP10_FS:
		index = (int)param0;
		if (fs_items[index].type == 1) {
			strcat(cur_path, "\\");
			strcat(cur_path, fs_items[index].name);
			setting_refresh_list_files(this_app_list_obj, cur_path);
			if (this_app_fs_timer) {
				tui_timer_del(this_app_fs_timer);
				this_app_fs_timer = NULL;
			}
			this_app_fs_timer = tui_timer_create(setting_fs_items_loader, 1, TUI_TIMER_PRIO_MID, (void *)this_app_list_obj); /* 定时器加载列表项，避免500以上文件长时间卡住 */
		} else {
			printf("select file path : %s\\%s\n", cur_path, fs_items[index].name);
		}
		break;
	case TUI_USER_MSG_APP10_FS_BACK:
		tmp_str = strrchr(cur_path, '\\');
		if (tmp_str) {
			*tmp_str = '\0';
			setting_refresh_list_files(this_app_list_obj, cur_path);
			if (this_app_fs_timer) {
				tui_timer_del(this_app_fs_timer);
				this_app_fs_timer = NULL;
			}
			this_app_fs_timer = tui_timer_create(setting_fs_items_loader, 1, TUI_TIMER_PRIO_MID, (void *)this_app_list_obj); /* 定时器加载列表项，避免500以上文件长时间卡住 */
		}
		break;
	default:
		break;
	}
	return 0;
}

tui_obj_t * setting_app10_enter(void)
{
	tui_sys_msg_reg(setting_app10_sys_msg_cb);

	this_app_obj = setting_app10_setting_view_view_create();
	tui_obj_set_del_cb(this_app_obj, setting_app10_exit);

	this_app_list_obj = tui_get_obj_from_id(this_app_obj, SETTING_APP10_SETTING_VIEW_LIST_245);

	strcpy(cur_path, "D:");

	setting_refresh_list_files(this_app_list_obj, cur_path);
	if (this_app_fs_timer) {
		tui_timer_del(this_app_fs_timer);
		this_app_fs_timer = NULL;
	}
	this_app_fs_timer = tui_timer_create(setting_fs_items_loader, 1, TUI_TIMER_PRIO_MID, (void *)this_app_list_obj); /* 定时器加载，避免500以上文件会卡住 */
	
	return this_app_obj;
}

static void setting_app10_exit(void)
{
	if (this_app_fs_timer) {
		tui_timer_del(this_app_fs_timer);
		this_app_fs_timer = NULL;
	}

	tui_sys_msg_unreg(setting_app10_sys_msg_cb);
}

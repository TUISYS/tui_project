
#ifdef LINUX_TINA

extern int home_create(char *res_path);

int main(int argc, char** argv)
{
	home_create("/mnt/data/res.disk");

	return 0;
}
#endif

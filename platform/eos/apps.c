#ifdef __EOS__

#include <stdio.h>
#include <stdlib.h>
#include "apps.h"
#include <dfs_posix.h>
#include <pthread.h>
#include <app_manage.h>
#include <dfs_posix.h>

static int32_t apps_start(app_t  *ap);
static int32_t apps_stop(app_t *ap);
static int32_t apps_suspend(app_t *ap);
static int32_t apps_resume(app_t *ap);
static int32_t apps_ctrl(app_t *ap, uint32_t cmd, int32_t aux0, void *aux1);

/* init app plugin interface struct */
static app_if_t appx = {
	apps_start,
	apps_stop,
	apps_suspend,
	apps_resume,
	apps_ctrl,
};

int home_create(void);
void home_destorty(void);

static void *thread_entry(void *parameter)
{
	home_create();
	return NULL;
}

static int32_t apps_start(app_t  *ap)
{
	int ret = 0;
	pthread_attr_t tmp_attr;
	pthread_t play_thread;
	struct sched_param shed_param = {0};

	pthread_attr_init(&tmp_attr);
	pthread_attr_setstacksize(&tmp_attr, 0x80000);
	shed_param.sched_priority = 15;
	pthread_attr_setschedparam(&tmp_attr, &shed_param);

	ret = pthread_create(&play_thread, &tmp_attr, thread_entry, NULL);
	if (ret < 0) {
		rt_kprintf("pthread_create fail.\n", ret);
		return -1;
	}

	return 0;
}

static int32_t apps_suspend(app_t *ap)
{
	printf("\n");

	return 0;
}

static int32_t apps_resume(app_t *ap)
{
	printf("\n");

	return 0;
}

static int32_t apps_ctrl(app_t *ap, uint32_t cmd, int32_t aux0, void *aux1)
{
	printf("cmd:%d,aux0 %x\n", cmd, aux0);

	return 0;
}

static int32_t apps_stop(app_t *ap)
{
	home_destorty();
	return 0;
}

app_if_t *get_app_if()
{
	return &appx;
}

#endif

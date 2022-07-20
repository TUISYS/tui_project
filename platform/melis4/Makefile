ccflags-y   +=  -I$(srctree)/emodules/tui_project/includes\
                -DAW_MELIS
ccflags-y   +=  -DAW_MELIS4

MOD_NAME := app_tui
SUF_NAME := mod
PRJ_PATH := $(srctree)/emodules/tui_project/
TEMP_PATH := $(srctree)/emodules/staging

usrlibs-y += -L$(srctree) \
			   --start-group \
			   -lsyscall -lminic\
			   -ltui\
			   --end-group






objy += ./magic.o
objy += ./main.o

objy  += ../../apps/home/view/login_view.o
objy  += ../../apps/uart_app7/uart_app7.o
objy  += ../../apps/uart_app7/view/uart_view.o
objy  += ../../apps/adjust/adjust.o
objy  += ../../apps/adjust/view/adjust_view.o
objy  += ../../apps/animation_app4/animation_app4.o
objy  += ../../apps/animation_app4/view/animation_view.o
objy  += ../../apps/arc_app0/arc_app0.o
objy  += ../../apps/arc_app0/view/arc_view.o
objy  += ../../apps/bar_app3/bar_app3.o
objy  += ../../apps/bar_app3/view/bar_view.o
objy  += ../../apps/button_app1/button_app1.o
objy  += ../../apps/button_app1/view/button_view.o
objy  += ../../apps/dashboard_app5/dashboard_app5.o
objy  += ../../apps/dashboard_app5/view/dashboard_view.o
objy  += ../../apps/draw_app9/draw9_app.o
objy  += ../../apps/draw_app9/view/draw_view.o
objy  += ../../apps/global_bar/view/status_bar.o
objy  += ../../apps/home/home.o
objy  += ../../apps/home/view/main_view.o
objy  += ../../apps/line_app2/line_app2.o
objy  += ../../apps/line_app2/view/line_view.o
objy  += ../../apps/logon_app11/logon_app11.o
objy  += ../../apps/logon_app11/view/logon_view.o
objy  += ../../apps/logo/view/logo_view.o
objy  += ../../apps/page_app8/page_app8.o
objy  += ../../apps/page_app8/view/page_view.o
objy  += ../../apps/setting_app10/setting_app10.o
objy  += ../../apps/setting_app10/view/setting_view.o
objy  += ../../apps/window_app6/view/window1_view.o
objy  += ../../apps/window_app6/view/window2_view.o
objy  += ../../apps/window_app6/view/window3_view.o
objy  += ../../apps/window_app6/view/window4_view.o
objy  += ../../apps/window_app6/view/window_view.o
objy  += ../../apps/window_app6/window_app6.o

#SRC_DIRS  =  $(shell find ./../.. -maxdepth 6 -type d)
#SRC_C = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
#SRC_O = $(SRC_C:.c=.o)
#objy += $(SRC_O)
#modtest:
#	@echo $(objy)

$(MOD_NAME)-objs := $(objy)

include $(MELIS_BASE)/scripts/Makefile.mods

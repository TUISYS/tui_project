
ROOT    = .

INCLUDES =  -I$(ROOT)/../../includes\


LOCALTARGET = tui_demo

CC        = gcc
CFLAGS    = -DLINUX $(INCLUDES)
TUI_LIB   = ./lib/libtui.a


SRCCS += ./main.c

SRCCS += ../../component/calendar.c
SRCCS += ../../component/chart.c
SRCCS += ../../component/clock.c
SRCCS += ../../component/component_reg.c
SRCCS += ../../component/dial.c
SRCCS += ../../component/msgbox.c
SRCCS += ../../component/template.c
SRCCS += ../../component/volti.c

SRCCS  += ../../apps/home/view/login_view.c
SRCCS  += ../../apps/uart_app7/uart_app7.c
SRCCS  += ../../apps/uart_app7/view/uart_view.c
SRCCS  += ../../apps/adjust/adjust.c
SRCCS  += ../../apps/adjust/view/adjust_view.c
SRCCS  += ../../apps/animation_app4/animation_app4.c
SRCCS  += ../../apps/animation_app4/view/animation_view.c
SRCCS  += ../../apps/arc_app0/arc_app0.c
SRCCS  += ../../apps/arc_app0/view/arc_view.c
SRCCS  += ../../apps/bar_app3/bar_app3.c
SRCCS  += ../../apps/bar_app3/view/bar_view.c
SRCCS  += ../../apps/button_app1/button_app1.c
SRCCS  += ../../apps/button_app1/view/button_view.c
SRCCS  += ../../apps/dashboard_app5/dashboard_app5.c
SRCCS  += ../../apps/dashboard_app5/view/dashboard_view.c
SRCCS  += ../../apps/draw_app9/draw9_app.c
SRCCS  += ../../apps/draw_app9/view/draw_view.c
SRCCS  += ../../apps/global_bar/view/status_bar.c
SRCCS  += ../../apps/home/home.c
SRCCS  += ../../apps/home/view/main_view.c
SRCCS  += ../../apps/line_app2/line_app2.c
SRCCS  += ../../apps/line_app2/view/line_view.c
SRCCS  += ../../apps/logon_app11/logon_app11.c
SRCCS  += ../../apps/logon_app11/view/logon_view.c
SRCCS  += ../../apps/logo/view/logo_view.c
SRCCS  += ../../apps/page_app8/page_app8.c
SRCCS  += ../../apps/page_app8/view/page_view.c
SRCCS  += ../../apps/setting_app10/setting_app10.c
SRCCS  += ../../apps/setting_app10/view/setting_view.c
SRCCS  += ../../apps/window_app6/view/window1_view.c
SRCCS  += ../../apps/window_app6/view/window2_view.c
SRCCS  += ../../apps/window_app6/view/window3_view.c
SRCCS  += ../../apps/window_app6/view/window4_view.c
SRCCS  += ../../apps/window_app6/view/window_view.c
SRCCS  += ../../apps/window_app6/window_app6.c

#SRC_DIRS  =  $(shell find ./../.. -maxdepth 6 -type d)
#SRCCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))


OBJS = $(SRCCS:.c=.o)



all:$(LOCALTARGET)
	@echo -------------------------------
	@echo tui build finish!
	@echo -------------------------------
    
$(OBJS) : %o: %c
	@$(CC) -c $< -lm -o $@ $(CFLAGS)

$(LOCALTARGET):$(OBJS)
	$(CC) -o $(LOCALTARGET) $(filter %.o ,$+) $(TUI_LIB) -lm 

# 删除生成的中间文件
clean:
	-rm $(OBJS) $(LOCALTARGET)


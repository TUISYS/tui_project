
ROOT    = .

INCLUDES =  -I$(ROOT)/../../includes\


LOCALTARGET = $(ROOT)/../../app_tui

CC        = gcc
CFLAGS    = -DLINUX_GCC $(INCLUDES)
TUI_LIB   = ./lib/libtui.a


SRC_DIRS  =  $(shell find ./../.. -maxdepth 6 -type d)
SRCCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))


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


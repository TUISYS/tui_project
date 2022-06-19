
ROOT    = .

INCLUDES =  -I$(ROOT)/../../includes\


LOCALTARGET = tui_demo

CC        = /home/tina/f133/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc
CFLAGS    = -DLINUX_TINA $(INCLUDES)
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


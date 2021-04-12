include ../src/config.mk

.PHONY: libs includes

all: includes libs vipclub

includes:
	make -C ../src includes

libs:
	make -C ../src libs

vipclub: libs includes vipclub-gui.h vipclub-gui.c vipclub-gui.xml
	$(TSC_CC) $(CFLAGS) -I. -I $(TSC_Incl) -D _GNU_SOURCE -L ../lib vipclub-gui.c -o vipclub -rdynamic -lsymbiot $(GLIBFLAGS) $(GTKFLAGS)

clean:
	rm -f vipclub
	rm -f vipclub-gui.error*
	rm -f vipclub-gui_dbg*
	rm -f vipclub-gui.*~

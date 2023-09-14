include ../config.mk

.PHONY: $(TSC_PRJG_PHONY)

all: includes libs vipclub

includes:
	$(TSC_SBP_SILENTMK)$(TSC_SBP_ECHOE) $(TSC_SBP_MKI) ../src includes

libs:
	$(TSC_SBP_SILENTMK)$(TSC_SBP_ECHOE) $(TSC_SBP_MKI) ../src libs

vipclub: libs includes vipclub-gui.h vipclub-gui.c vipclub-gui.xml
	$(TSC_SBP_CC) $(CFLAGS_GLIB) $(CLFAGS_GTK) -D _GNU_SOURCE vipclub-gui.c -o vipclub-gui -rdynamic -lsymbiot $(LIBS_GLIB) $(GTKFLAGS)

clean:
	rm -f vipclub
	rm -f vipclub-gui.error*
	rm -f vipclub-gui_dbg*
	rm -f vipclub-gui.*~

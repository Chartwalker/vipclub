include ../../../src/config.mk

.PHONY: update install clean

all: install

libsymbiot.a: libsymbiot.h libsymbiot.c tb_libsymbiot.c
	$(TSC_CC) -I. -I $(TSC_Incl) -c libsymbiot.c $(CFLAGS)
	$(TSC_AR) libsymbiot.a libsymbiot.o
	
tb_libsymbiot: libsymbiot.a tb_libsymbiot.c
	$(TSC_CC) $(CFLAGS) -I. -I $(TSC_Incl) -L $(TSC_Libs)  tb_libsymbiot.c -o tb_libsymbiot -lsymbiot

install: libsymbiot.a tb_libsymbiot
	$(TSC_MK) update 

update:
	$(TSC_CP) libsymbiot.h $(TSC_Incl)/libsymbiot/libsymbiot.h 
	$(TSC_CP) libsymbiot.a $(TSC_Libs)/libsymbiot.a 

clean:
	$(TSC_RM) libsymbiot.a
	$(TSC_RM) libsymbiot.o
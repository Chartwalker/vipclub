include ../../../src/config.mk

.PHONY: clean includes libs install test clean

all: clean includes libs install

libsymbiot.a: libsymbiot.h libsymbiot.c tb_libsymbiot.c
	$(TSC_CC) -I. -I $(TSC_Incl) -c libsymbiot.c $(CFLAGS)
	$(TSC_AR) libsymbiot.a libsymbiot.o
	
tb_libsymbiot: libsymbiot.a tb_libsymbiot.c
	$(TSC_CC) $(CFLAGS) -I. -I $(TSC_Incl) -L $(TSC_Libs)  tb_libsymbiot.c -o tb_libsymbiot -lsymbiot

install: includes libs test

includes:
	$(TSC_CP) ./libsymbiot.h $(TSC_Incl)/libsymbiot/libsymbiot.h
	$(TSC_CP) ./bitops.h $(TSC_Incl)/libsymbiot/bitops.h

libs: includes libsymbiot.a
	$(TSC_CP) libsymbiot.a $(TSC_Libs)/libsymbiot.a 

clean:
	$(TSC_RM) ./libsymbiot.a
	$(TSC_RM) $(TSC_Incl)/libsymbiot/libsymbiot.a
	$(TSC_RM) $(TSC_Incl)/libsymbiot/libsymbiot.h
	$(TSC_RM) $(TSC_Incl)/libsymbiot/bitops.h

test: tb_libsymbiot
	./tb_libsymbiot

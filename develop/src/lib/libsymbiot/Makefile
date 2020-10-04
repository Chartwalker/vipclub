include ../../../src/config.mk

.PHONY: config clean includes libs install test doc

all: config clean includes libs install doc

libsymbiot.a: libsymbiot.h libsymbiot.c tb_libsymbiot.c
	$(TSC_CC) -I. -I $(TSC_Incl) -c libsymbiot.c $(CFLAGS)
	$(TSC_AR) libsymbiot.a libsymbiot.o
	
tb_libsymbiot: libsymbiot.a tb_libsymbiot.c
	$(TSC_CC) $(CFLAGS) -I. -I $(TSC_Incl) -L $(TSC_Libs)  tb_libsymbiot.c -o tb_libsymbiot -lsymbiot

install: includes libs test

includes:
	$(TSC_MKDIR) $(TSC_Incl)/libsymbiot/
	$(TSC_CP) ./libsymbiot.h $(TSC_Incl)/libsymbiot/libsymbiot.h
	$(TSC_CP) ./bitops.h $(TSC_Incl)/libsymbiot/bitops.h

libs: includes libsymbiot.a
	$(TSC_CP) libsymbiot.a $(TSC_Libs)/libsymbiot.a

doc:
	dot -Tpdf < tb_libsymbiot1.dot  > tb_libsymbiot1.pdf

clean:
	$(TSC_RM) ./libsymbiot.a
	$(TSC_RM) ./libsymbiot.o
	$(TSC_RM) ./tb_libsymbiot
	$(TSC_RM) ./tb_libsymbiot.log
	$(TSC_RM) ./tb_libsymbiot1.dot
	$(TSC_RM) ./tb_libsymbiot1.pdf
	$(TSC_RM) $(TSC_Libs)/libsymbiot.a
	$(TSC_RM) $(TSC_Incl)/libsymbiot/libsymbiot.h
	$(TSC_RM) $(TSC_Incl)/libsymbiot/bitops.h
	$(TSC_RMDIRI) $(TSC_Incl)/libsymbiot/
	

test: tb_libsymbiot
	./tb_libsymbiot

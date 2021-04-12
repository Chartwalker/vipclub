include ../../../src/config.mk

.PHONY: config clean includes libs install test doc

all: clean includes libs install doc

libsymbiot.a: libsymbiot.h libsymbiot.c tb_libsymbiot.c
	$(TSC_CC) -I. -I $(TSC_Incl) -c libsymbiot.c $(CFLAGS)
	$(TSC_AR) libsymbiot.a libsymbiot.o
	
tb_libsymbiot: libsymbiot.a tb_libsymbiot.c
	$(TSC_CC) $(CFLAGS) -I. -I $(TSC_Incl) -L $(TSC_Libs)  tb_libsymbiot.c -o tb_libsymbiot -lsymbiot

install: includes libs test

includes:
	@if [ ! -d $(TSC_Incl)/libsymbiot/ ]; then $(TSC_MKDIR) $(TSC_Incl)/libsymbiot/; fi
	@if [ ! -d $(TSC_Projdir) ]; then $(TSC_MKDIR) $(TSC_Projdir); fi
	@if [ -f ./libsymbiot.h ]; then $(TSC_CP) ./libsymbiot.h $(TSC_Incl)/libsymbiot/libsymbiot.h; fi
	@if [ -f ./bitops.h ]; then $(TSC_CP) ./bitops.h $(TSC_Incl)/libsymbiot/bitops.h; fi
	@if [ -f $(TSC_H) ]; then $(TSC_CP) $(TSC_H) $(TSC_Incl); fi
	@if [ -f $(TSC_CMK) ]; then $(TSC_CP) $(TSC_CMK) $(TSC_Incl); fi

libs: includes libsymbiot.a
	$(TSC_CP) libsymbiot.a $(TSC_Libs)/libsymbiot.a

doc:
	dot -Tpdf < tb_libsymbiot.dot  > tb_libsymbiot_dot.pdf

clean:
	@if [ -f ./libsymbiot.a ]; then $(TSC_RM) ./libsymbiot.a; fi 
	@if [ -f ./libsymbiot.o ]; then $(TSC_RM) ./libsymbiot.o; fi 
	@if [ -f ./tb_libsymbiot ]; then $(TSC_RM) ./tb_libsymbiot; fi 
	@if [ -f ./tb_libsymbiot_log.txt ]; then $(TSC_RM) ./tb_libsymbiot_log.txt; fi 
	@if [ -f ./tb_libsymbiot_dbg.txt ]; then $(TSC_RM) ./tb_libsymbiot_dbg.txt; fi 
	@if [ -f ./tb_libsymbiot_dot.pdf ]; then $(TSC_RM) ./tb_libsymbiot_dot.pdf; fi 
	@if [ -f ./tb_libsymbiot.html ]; then $(TSC_RM) ./tb_libsymbiot.html; fi 
	@if [ -f ./tb_libsymbiot.dot ]; then $(TSC_RM) ./tb_libsymbiot.dot; fi 
	@if [ -f ./tb_libsymbiot.json ]; then $(TSC_RM) ./tb_libsymbiot.json; fi 
	@if [ -f $(TSC_Libs)/libsymbiot.a ]; then $(TSC_RM) $(TSC_Libs)/libsymbiot.a; fi 
	@if [ -f $(TSC_Incl)/libsymbiot/libsymbiot.h ]; then $(TSC_RM) $(TSC_Incl)/libsymbiot/libsymbiot.h; fi
	@if [ -f $(TSC_Incl)/libsymbiot/bitops.h ]; then $(TSC_RM) $(TSC_Incl)/libsymbiot/bitops.h; fi


test: tb_libsymbiot
	./tb_libsymbiot

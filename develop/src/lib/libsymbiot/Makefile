include ../../config.mk

.PHONY: $(TSC_PRJG_PHONY)

#MKSILENT=$(TSC_XOR_MKSILENT)
MKSILENT=

all: clean includes libsymbiot.a libs doc

libsymbiot.a: libsymbiot.h libsymbiot.cc libsymbiot_tb.cc
	$(MKSILENT)$(TSC_SBP_CPP) $(CFLAGS_GLIB) $(CFLAGS_GTK) $(TSC_XOR_CPPWARN) -c libsymbiot.cc $(LIBS_GLIB)
	$(MKSILENT)$(TSC_SBP_AR) libsymbiot.a libsymbiot.o

test: libsymbiot_tb
	#./libsymbiot_tb > libsymbiot_tb.$(TSC_SBP_TS).log 
	./libsymbiot_tb


libsymbiot_tb: libsymbiot.a libsymbiot_tb.cc
	$(MKSILENT)$(TSC_SBP_CPP) $(CFLAGS_GLIB) $(CFLAGS_GTK) $(TSC_XOR_CPPWARN) -o libsymbiot_tb libsymbiot_tb.cc $(LIBS_GLIB) $(LIBS_GTK) -lsymbiot

dist: includes libs test

includes:
	$(MKSILENT)$(TSC_SBP_MKDIRI) $(TSC_CDPA_INCL)
	$(MKSILENT)$(TSC_SBP_MKDIRI) $(TSC_CDPA_INCL)/libsymbiot
	@if [ -f ./libsymbiot.h ]; then $(TSC_SBP_CP) ./libsymbiot.h $(TSC_CDPA_INCL)/libsymbiot/libsymbiot.h; fi
	@if [ -f ./bitops.h ]; then $(TSC_SBP_CP) ././bitops.h $(TSC_CDPA_INCL)/libsymbiot/bitops.h; fi

libs: includes libsymbiot.a
	$(TSC_SBP_CP) libsymbiot.a $(TSC_CDPA_LIB)/libsymbiot.a

doc:
	#dot -Tpdf < tb_libsymbiot.dot  > tb_libsymbiot_dot.pdf

clean:
	@if [ -f ./libsymbiot.a ]; then $(TSC_SBP_RM) ./libsymbiot.a; fi 
	@if [ -f ./libsymbiot.o ]; then $(TSC_SBP_RM) ./libsymbiot.o; fi 
	@if [ -f ./libsymbiot_tb ]; then $(TSC_SBP_RM) ./libsymbiot_tb; fi 
	@if [ -f ./tb_libsymbiot_log.txt ]; then $(TSC_SBP_RM) ./tb_libsymbiot_log.txt; fi 
	@if [ -f ./tb_libsymbiot_dbg.txt ]; then $(TSC_SBP_RM) ./tb_libsymbiot_dbg.txt; fi 
	@if [ -f ./tb_libsymbiot_dot.pdf ]; then $(TSC_SBP_RM) ./tb_libsymbiot_dot.pdf; fi 
	@if [ -f ./tb_libsymbiot.html ]; then $(TSC_SBP_RM) ./tb_libsymbiot.html; fi 
	@if [ -f ./tb_libsymbiot.dot ]; then $(TSC_SBP_RM) ./tb_libsymbiot.dot; fi 
	@if [ -f ./tb_libsymbiot.json ]; then $(TSC_SBP_RM) ./tb_libsymbiot.json; fi 
	@if [ -f $(TSC_CDPA_LIB)/libsymbiot.a ]; then $(TSC_SBP_RM) $(TSC_CDPA_LIB)/libsymbiot.a; fi 
	@if [ -f $(TSC_CDPA_INCL)/libsymbiot/libsymbiot.h ]; then $(TSC_SBP_RM) $(TSC_CDPA_INCL)/libsymbiot/libsymbiot.h; fi
	@if [ -f $(TSC_CDPA_INCL)/libsymbiot/bitops.h ]; then $(TSC_SBP_RM) $(TSC_CDPA_INCL)/libsymbiot/bitops.h; fi

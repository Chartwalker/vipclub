include ../../../src/config.mk

.PHONY: install libs clean

globincls = libsymbiot.h bitops.h
cpglobincls = $(foreach globincl,$(globincls),$(TSC_CP) $(globincl) $(TSC_Incl)/libsymbiot/$(globincl))
rmglobincls = $(foreach globincl,$(globincls),$(TSC_RM) $(TSC_Incl)/libsymbiot/$(globincl))

globlibs = libsymbiot.a 
cpgloblibs = $(foreach globlib,$(globlibs),$(TSC_CP) $(globlib) $(TSC_Libs)/$(globlib))
rmgloblibs = $(foreach globlib,$(globlibs),$(TSC_RM) $(globlib) $(TSC_Libs)/$(globlib) )

all: clean libs install

libsymbiot.a: libsymbiot.h libsymbiot.c tb_libsymbiot.c
	$(TSC_CC) -I. -I $(TSC_Incl) -c libsymbiot.c $(CFLAGS)
	$(TSC_AR) libsymbiot.a libsymbiot.o
	
tb_libsymbiot: libsymbiot.a tb_libsymbiot.c
	$(TSC_CC) $(CFLAGS) -I. -I $(TSC_Incl) -L $(TSC_Libs)  tb_libsymbiot.c -o tb_libsymbiot -lsymbiot

install: libsymbiot.a tb_libsymbiot
	$(cpglobincls)
	$(cpgloblibs)

libs: libsymbiot.a
	$(TSC_CP) libsymbiot.a $(TSC_Libs)/libsymbiot.a 

clean:
	echo $(rmglobincls)
	echo $(rmgloblibs)

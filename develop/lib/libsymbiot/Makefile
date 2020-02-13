include ../../src/config.mk

TSC_PWD= `pwd`

all: libsymbiot.a

libsymbiot.a: libsymbiot.h libsymbiot.c
	$(CC) -I ../. -c libsymbiot.c $(CFLAGS)
	$(AR) -s libsymbiot.o
	$(RANLIB) -t libsymbiot.a 

clean:
	rm -f libsymbiot.[ao]
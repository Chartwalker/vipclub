include ./config.mk

.PHONY: includes libs clean

all:
	make -C ./lib/libsymbiot/ all

includes:
	make -C ./lib/libsymbiot/ includes

libs:
	make -C ./lib/libsymbiot/ libs

clean:
	make -C ./lib/libsymbiot/ clean

doc:
	make -C ./lib/libsymbiot/ doc

test:
	make -C ./lib/libsymbiot/ test


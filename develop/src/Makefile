include ./config.mk

.PHONY: includes libs clean

all: clean includes libs doc test
	make -C ./lib/libsymbiot/ all

includes:
	make -C ./lib/libsymbiot/ includes

libs:
	make -C ./lib/libsymbiot/ libs

clean:
	make -C ./lib/libsymbiot/ clean
	make -C ../develdoc/ clean

doc:
	make -C ./lib/libsymbiot/ doc
	make -C ../develdoc/ doc

test:
	make -C ./lib/libsymbiot/ test


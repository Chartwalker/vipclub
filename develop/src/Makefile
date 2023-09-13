include ./config.mk

.PHONY: $(TSC_PRJG_PHONY)

TARGETS=$(TSC_PRJG_TARGETS)

all: clean includes libs guis docs tests
	#make -C ./lib/libsymbiot/ all

includes:
	#make -C includes

clis:
	#make -C ./gui clis

guis:
	#make -C ./gui guis

cgis:
	#make -C ./cgi cgis

libs:
	#make -C ./lib libs

clean:
	#make -C ./lib/libsymbiot/ clean
	#make -C ../develdoc/ clean

docs:
	#make -C ./lib/libsymbiot/ docs
	#make -C ../develdoc/ docs

tests:
	#make -C ./lib/libsymbiot/ tests


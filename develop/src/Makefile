include ./config.mk

.PHONY: $(TSC_PRJG_PHONY)

TARGETS=$(TSC_PRJG_TARGETS)

all: clean includes libs guis docs tests
	#make -C ./lib/libsymbiot/ all

includes:
	$(TSC_SBP_ECHOE) make $(TSC_CDPA_INCL)
	$(TSC_SBP_MKDIRI) $(TSC_CDPA_INCL)/$(TSC_PRJG_FNAME)/$(TSC_CDN_GUI)
	$(TSC_SBP_CP) $(TSC_CDPA_GUI)/vipclub-gui.h  $(TSC_CDPA_INCL)/$(TSC_PRJG_FNAME)/vipclub-gui.h

clis:
	#make -C ./gui clis

guis:
	#make -C ./gui guis

cgis:
	#make -C ./cgi cgis

libs:
	$(TSC_SBP_ECHOE) make $(TSC_CDPA_LIB)
	$(TSC_SBP_MKDIRI) $(TSC_CDPA_LIB)/$(TSC_PRJG_FNAME)
	$(TSC_SBP_CP) $(TSC_CDPA_GUI)/libvipclub-gui.a  $(TSC_CDPA_LIB)/$(TSC_PRJG_FNAME)/libvipclub-gui.a

clean:
	#make -C ./lib/libsymbiot/ clean
	#make -C ../develdoc/ clean

docs:
	#make -C ./lib/libsymbiot/ docs
	#make -C ../develdoc/ docs

tests:
	#make -C ./lib/libsymbiot/ tests


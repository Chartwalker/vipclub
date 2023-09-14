include src/config.mk

.PHONY: all cgis clean clis distclean distrib docs includes guis libs tests

all: config
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src all

cgis:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src cgis

clean:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src clean

config:
	./configure.sh

distclean:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src distclean

distrib:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src distrib

docs: ;
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src docs

includes:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src includes

guis:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src guis

libs:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src libs

tests:
	$(TSC_SBP_MKSILENT)$(TSC_SBP_MKI) ./src tests

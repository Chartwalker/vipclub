#!/bin/bash

# CAUTION! keep the config script clean!
# mostly alphabetical, but only  if there is no technical or logical depencies
# and if so then add an empty line

# projekt global settings - name of the game :-) as strings

# don't downgrade tsc-levels, only upgrade tsc-levels 
# bc. there is no real backward compatibilty, update always the tsc_write_env() and bellow
TSC_PRJG_LEVEL="6"

TSC_PRJG_COPYR="Copyright: Kaiserrundfunk.com / Jonacast 2019-2023"
TSC_PRJG_DEDIT="Created by Configure at compiling - do not edit this file"

TSC_PRJG_TS=`date "+%d.%m.%Y %H:%M:%S" `
TSC_PRJG_TS_S=\"$TSC_PRJG_TS\"

TSC_PRJG_COMP_S=\"`uname -s`" ("`uname -n`") "`uname -i`" at "$TSC_PRJG_TS\"

TSC_PRJG_FNAME="vipclub"
TSC_PRJG_PNAME="Vipclub"
TSC_PRJG_PSUMS="a club-maintenance addon"
TSC_PRJG_PSUML="a club-maintenance addon"
TSC_PRJG_PGRP="Applications/Productivity"
TSC_PRJG_PLIC="MIT"

TSC_PRJG_LANG_DE="de"
TSC_PRJG_LANG_EN="en"

TSC_PRJG_MAJOR="0"
TSC_PRJG_MINOR="1"
TSC_PRJG_RELEASE="5"
TSC_PRJG_PATCH="6"
TSC_PRJG_TSCFG=`date "+%Y%m%d%H%M%S" `

TSC_PRJG_PHONY="all cgis clean clis config distclean distrib docs includes install guis libs tests"
TSC_PRJG_TARGET="vipclub vipclub_tb vipclub_dbg vipclub_gui vipclub_gui_tb vipclub_gui_dbg"

TSC_PRJG_VERSION=$TSC_PRJG_FNAME-$TSC_PRJG_MAJOR.$TSC_PRJG_MINOR.$TSC_PRJG_RELEASE-$TSC_PRJG_PATCH
TSC_PRJG_VERSION_S=\"$TSC_PRJG_VERSION\"



# config directory names

TSC_CDN_CLI="cli"
TSC_CDN_CGI="cgi"
TSC_CDN_DIST="dist"
TSC_CDN_DOC="doc"
TSC_CDN_DOCDEVEL="develdoc"
TSC_CDN_DOCUSER="userdoc"
TSC_CDN_GUI="gui"
TSC_CDN_HW="hardware"
TSC_CDN_INCL="include"
TSC_CDN_INSTALL="install"
TSC_CDN_LIB="lib"
TSC_CDN_RPM="rpm"
TSC_CDN_SNAP="snap"
TSC_CDN_SRC="src"
TSC_CDN_SRPM="srpm"
TSC_CDN_LIBSYMBIOT="libsymbiot"
TSC_CDN_STABLE="stable"
TSC_CDN_TESTING="testing"

# config file names

TSC_CFN_CFG="configure.sh"
TSC_CFN_CMK="config.mk"
TSC_CFN_CH="config.h"
TSC_CFN_LIBSYMBIOT="libsymbiot"
TSC_CFN_MF="Makefile"
TSC_CFN_SNAPYAML="snapcraft.yaml"
TSC_CFN_SPEC=$TSC_PRJG_VERSION".spec"

# config directory path absolute and relative to configure

TSC_CDPA_CONF=`pwd`
TSC_CDPR_CONF="."

# config directory paths absolute
# absolute under the install-tree

TSC_CDPA_DIST=$TSC_CDPA_CONF"/"$TSC_CDN_DIST
TSC_CDPA_DOC=$TSC_CDPA_CONF"/"$TSC_CDN_DOC
TSC_CDPA_INCL=$TSC_CDPA_CONF"/"$TSC_CDN_INCL
TSC_CDPA_INSTALL=$TSC_CDPA_CONF"/"$TSC_CDN_INSTALL
TSC_CDPA_LIB=$TSC_CDPA_CONF"/"$TSC_CDN_LIB
TSC_CDPA_RPM=$TSC_CDPA_CONF"/"$TSC_CDN_RPM
TSC_CDPA_SNAP=$TSC_CDPA_CONF"/"$TSC_CDN_SNAP
TSC_CDPA_SRPM=$TSC_CDPA_CONF"/"$TSC_CDN_SRPM

# absolute under the src-tree

TSC_CDPA_SRC=$TSC_CDPA_CONF"/"$TSC_CDN_SRC
TSC_CDPA_CLI=$TSC_CDPA_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_CLI
TSC_CDPA_GUI=$TSC_CDPA_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_GUI
TSC_CDPA_LIBSYMBIOT=$TSC_CDPA_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_LIB"/"$TSC_CFN_LIBSYMBIOT


# config directory path relative
# relative under the install-tree

TSC_CDPR_DIST=$TSC_CDPR_CONF"/"$TSC_CDN_DIST
TSC_CDPR_DOC=$TSC_CDPR_CONF"/"$TSC_CDN_DOC
TSC_CDPR_INCL=$TSC_CDPR_CONF"/"$TSC_CDN_INCL
TSC_CDPR_INSTALL=$TSC_CDPR_CONF"/"$TSC_CDN_INSTALL
TSC_CDPR_LIB=$TSC_CDPR_CONF"/"$TSC_CDN_LIB
TSC_CDPR_RPM=$TSC_CDPR_CONF"/"$TSC_CDN_RPM
TSC_CDPR_SNAP=$TSC_CDPR_CONF"/"$TSC_CDN_SNAP
TSC_CDPR_SRPM=$TSC_CDPR_CONF"/"$TSC_CDN_SRPM

# relative under the src-tree

TSC_CDPR_SRC=$TSC_CDPR_CONF"/"$TSC_CDN_SRC
TSC_CDPR_CLI=$TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_CLI
TSC_CDPR_GUI=$TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_GUI
TSC_CDPR_LIBSYMBIOT=$TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_LIB"/"$TSC_CFN_LIBSYMBIOT

# config directory paths absolute with filenames

TSC_CDPAFN_CH=$TSC_CDPA_CONF"/"$TSC_CFN_CH
TSC_CDPAFN_CMK=$TSC_CDPA_CONF"/"$TSC_CFN_CMK
TSC_CDPAFN_MK=$TSC_CDPA_CONF"/"$TSC_CFN_MF
TSC_CDPAFN_SNAPYAML=$TSC_CDPA_CONF"/"$TSC_CDN_SNAP"/"$TSC_CFN_SNAPYAML
TSC_CDPAFN_SPEC=$TSC_CDPA_CONF"/"$TSC_CDN_SRPM"/"$TSC_CFN_SPEC

# config directory paths reltative with filenames

TSC_CDPRFN_CH=$TSC_CDPR_SRC"/"$TSC_CFN_CH
TSC_CDPRFN_CMK=$TSC_CDPR_SRC"/"$TSC_CFN_CMK
TSC_CDPRFN_MK=$TSC_CDPR_SRC"/"$TSC_CFN_MF
TSC_CDPRFN_SNAPYAML=$TSC_CDPR_CONF"/"$TSC_CDN_SNAP"/"$TSC_CFN_SNAPYAML
TSC_CDPRFN_SPEC=$TSC_CDPR_CONF"/"$TSC_CDN_SRPM"/"$TSC_CFN_SPEC

# system depended binaries with path

TSC_SBP_AR=`which ar`" -rs"
TSC_SBP_BISON=`which bison`
TSC_SBP_CC=`which gcc`
TSC_SBP_CP=`which cp`
TSC_SBP_CPP=`which g++`
TSC_SBP_DOT=`which dot`
TSC_SBP_ECHO=`which echo`
TSC_SBP_ECHOE=`which echo`" -e"
TSC_SBP_LEX=`which flex`
TSC_SBP_MK=`which make`
TSC_SBP_MKI=`which make`" -sC"
TSC_SBP_MKDIR=`which mkdir`
TSC_SBP_MKDIRI=`which mkdir`" -p"
TSC_SBP_RM=`which rm`" -f"
TSC_SBP_RMDIR=`which rmdir`
TSC_SBP_RMDIRI=`which rmdir`" --ignore-fail-on-non-empty"
TSC_SBP_TS="\`date \"+%d.%m.%Y_%H:%M:%S\"\`"

#
# switch with "XOR-uncomment" as needed 
#
# see make command or not
#TSC_XOR_MKSILENT=
TSC_XOR_MKSILENT=@
#
# get warings or not
TSC_XOR_CCWARN="-Wall -Wstrict-prototypes"
#TSC_XOR_CCWARN=
#

# debug xor switches "blank" or "1"
# global on / off
TSC_XOR_DBG_GLOBAL=1
#TSC_XOR_DBG_GLOBAL=
TSC_XOR_DBG_PRINT=1
#TSC_XOR_DBG_PRINT=
TSC_XOR_DBG_CTRL=1
#TSC_XOR_DBG_CTRL=
TSC_XOR_DBG_CB=1
#TSC_XOR_DBG_CB=
TSC_XOR_DBG_SIZE=1
#TSC_XOR_DBG_SIZE=
TSC_XOR_DBG_PTR=1
#TSC_XOR_DBG_PTR=

if [ "$TSC_XOR_DBG_GLOBAL" = "" ] 
then 
    echo debugging is off 
    TSC_XOR_DBG_PRINT=
    TSC_XOR_DBG_CTRL=
    TSC_XOR_DBG_CB=
    TSC_XOR_DBG_SIZE=
    TSC_XOR_DBG_PTR=
else
    $TSC_SBP_ECHOE debugging is on with dbg_print=$TSC_XOR_DBG_PRINT dbg_ctrl=$TSC_XOR_DBG_CTRL \
dbg_cb=$TSC_XOR_DBG_CB dbg_size=$TSC_XOR_DBG_SIZE dbg_ptr=$TSC_XOR_DBG_PTR
fi


TSC_SBP_YACC=$TSC_SBP_BISON

# linker and compiler flags

CFLAGS_GLIB=`pkg-config --cflags glib-2.0 glibmm-2.68 giomm-2.68 sigc++-3.0`" "$TSC_XOR_CCWARN" -I /usr/lib64 -I /usr/include/gtkmm-4.0 -I /usr/include/giomm-4.0 -I /usr/include/gtk-4.0 -I "$TSC_CDPA_INCL
CFLAGS_GTK=`pkg-config --cflags gtk+-3.0 gtkmm-4.0 pangomm-2.48 cairomm-1.16`
LIBS_GLIB=`pkg-config --libs glib-2.0 glibmm-2.68 giomm-2.68`" -L /usr/lib64 -L "$TSC_CDPA_LIB" -lglib-2.0 -lsymbiot"
LIBS_GTK=`pkg-config --libs gtk+-3.0 gtkmm-4.0`

# debug defines

TSC_DBG_LANG=$TSC_PRJG_LANG_DE

# create dirs relative to configure - no error if exist

$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_DOC
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_DOC"/"$TSC_CDN_HW
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_DOC"/"$TSC_CDN_DEVELDOC
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_DOC"/"$TSC_CDN_USERDOC

$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_INCL
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_INCL"/"$TSC_PRJG_FNAME
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_INCL"/"$TSC_PRJG_FNAME"/"$TSC_CDN_GUI

$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_INSTALL

$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_LIB
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_LIB"/"$TSC_PRJG_FNAME

$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SRC
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_GUI
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_CLI
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_LIB
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SRC"/"$TSC_CDN_LIB"/"$TSC_CDN_LIBSYMBIOT

$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_RPM
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SNAP
$TSC_SBP_MKDIRI $TSC_CDPR_CONF"/"$TSC_CDN_SRPM

# parameter assignment

# $1 start definition line #define or empty
# $2 start remark line
# $3 start action line
# $4 assignment operator or empty
# $5 outputfile

tsc_write_env(){

	$TSC_SBP_ECHOE "write" $5
	$TSC_SBP_ECHOE $2" "$TSC_PRJG_COPYR > $5
	$TSC_SBP_ECHOE $2" "$TSC_PRJG_COMP >> $5
	$TSC_SBP_ECHOE $2" "$TSC_PRJG_DEDIT >> $5

	$TSC_SBP_ECHOE "\n"$2"  debug defines" >> $5

	if [[ $TSC_DBG_LANG == $TSC_PRJG_LANG_DE ]]
	then
		$TSC_SBP_ECHOE $1"__TSC_PRJG_LANG_DE__$4"$TSC_PRJG_LANG_DE  >> $5
	fi
	if [[ $TSC_DBG_LANG == $TSC_PRJG_LANG_EN ]]
	then
		$TSC_SBP_ECHOE $1"__TSC_PRJG_LANG_EN__S4"$TSC_PRJG_LANG_DE  >> $5
	fi

	$TSC_SBP_ECHOE "\n"$2" projekt global settings - name of the game :-) as strings" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_LEVEL$4"$TSC_PRJG_LEVEL >> $5 >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PSUMS$4"$TSC_PRJG_PSUMS >> $5 >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PSUML$4"$TSC_PRJG_PSUML >> $5 >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PGRP$4"$TSC_PRJG_PGRP >> $5 >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PLIC$4"$TSC_PRJG_PLIC >> $5 >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_COPYR$4"$TSC_PRJG_COPYR >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_DEDIT$4"$TSC_PRJG_DEDIT >> $5
	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_COPYR$4"$TSC_PRJG_COPYR >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_DEDIT$4"$TSC_PRJG_DEDIT >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_COPYR$4"$TSC_PRJG_COPYR >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_DEDIT$4"$TSC_PRJG_DEDIT >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_TS$4"$TSC_PRJG_TS >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_TS_S$4"$TSC_PRJG_TS_S >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_COMP_S$4"$TSC_PRJG_COMP_S >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_FNAME$4"$TSC_PRJG_FNAME >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PNAME$4"$TSC_PRJG_PNAME >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_LANG_DE$4"$TSC_PRJG_LANG_DE >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_LANG_EN$4"$TSC_PRJG_LANG_EN >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_MAJOR$4"$TSC_PRJG_MAJOR >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_MINOR$4"$TSC_PRJG_MINOR >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_RELAESE$4"$TSC_PRJG_RELEASE >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PATCH$4"$TSC_PRJG_PATCH >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_TSCFG$4"$TSC_PRJG_TSCFG >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_PHONY$4"$TSC_PRJG_PHONY >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_TARGET$4"$TSC_PRJG_TARGET >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_PRJG_VERSION$4"$TSC_PRJG_VERSION >> $5
	$TSC_SBP_ECHOE $1"TSC_PRJG_VERSION_S$4"$TSC_PRJG_VERSION_S >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory names" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CDN_CLI$4"$TSC_CDN_CLI >> $5
	$TSC_SBP_ECHOE $1"TSC_CGI_CGI$4"$TSC_CDN_CGI >> $5
	$TSC_SBP_ECHOE $1"TSC_CGI_DIST$4"$TSC_CDN_DIST >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_DOC$4"$TSC_CDN_DOC >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_DOCDEVEL$4"$TSC_CDN_DOCDEVEL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_DOCUSER$4"$TSC_CDN_DOCUSER >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_GUI$4"$TSC_CDN_GUI >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_HW$4"$TSC_CDN_HW >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_INCL$4"$TSC_CDN_INCL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_INSTALL$4"$TSC_CDN_INSTALL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_LIB$4"$TSC_CDN_LIB >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_RPM$4"$TSC_CDN_RPM >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_SNAP$4"$TSC_CDN_SNAP >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_SRC$4"$TSC_CDN_SRC >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_SRPM$4"$TSC_CDN_SRPM >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_LIBSYMBIOT$4"$TSC_CDN_LIBSYMBIOT >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_STABLE$4"$TSC_CDN_STABLE >> $5
	$TSC_SBP_ECHOE $1"TSC_CDN_TESTING$4"$TSC_CDN_TESTING >> $5

	$TSC_SBP_ECHOE "\n"$2" config file names" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CFN_CFG$4"$TSC_CFN_CFG>> $5	
	$TSC_SBP_ECHOE $1"TSC_CFN_CMK$4"$TSC_CFN_CMK>> $5
	$TSC_SBP_ECHOE $1"TSC_CFN_CH$4"$TSC_CFN_CH >> $5
	$TSC_SBP_ECHOE $1"TSC_CFN_LIBSYMBIOT$4"$TSC_CFN_LIBSYMBIOT >> $5
	$TSC_SBP_ECHOE $1"TSC_CFN_MF$4"$TSC_CFN_MF >> $5
	$TSC_SBP_ECHOE $1"TSC_CFN_SNAPYAML$4"$TSC_CFN_SNAPYAML >> $5
	$TSC_SBP_ECHOE $1"TSC_CFN_SPEC$4"$TSC_CFN_SPEC >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory path absolute and relative to configure" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CDPA_CONF$4"$TSC_CDPA_CONF >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_CONF$4"$TSC_CDPR_CONF >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory paths absolute" >> $5
	$TSC_SBP_ECHOE "\n"$2" absolute under the install-tree" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CDPA_DIST$4"$TSC_CDPA_DIST >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_DOC$4"$TSC_CDPA_DOC >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_INCL$4"$TSC_CDPA_INCL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_INSTALL$4"$TSC_CDPA_INSTALL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_LIB$4"$TSC_CDPA_LIB >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_RPM$4"$TSC_CDPA_RPM >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_SNAP$4"$TSC_CDPA_SNAP >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_SRPM$4"$TSC_CDPA_SRPM >> $5


	$TSC_SBP_ECHOE "\n"$1"TSC_CDPA_SRC$4"$TSC_CDPA_SRC >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_CLI$4"$TSC_CDPA_CLI >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_GUI$4"$TSC_CDPA_GUI >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPA_LIBSYMBIOT$4"$TSC_CDPA_LIBSYMBIOT >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory path relative" >> $5
	$TSC_SBP_ECHOE "\n"$2" relative under the install-tree" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CDPR_DIST$4"$TSC_CDPR_DIST >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_DOC$4"$TSC_CDPR_DOC >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_INCL$4"$TSC_CDPR_INCL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_INSTALL$4"$TSC_CDPR_INSTALL >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_LIB$4"$TSC_CDPR_LIB >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_RPM$4"$TSC_CDPR_RPM >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_SNAP$4"$TSC_CDPR_SNAP >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_SRPM$4"$TSC_CDPR_SRPM >> $5

	$TSC_SBP_ECHOE "\n"$2" relative under the install-tree" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CDPR_SRC$4"$TSC_CDPR_SRC >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_CLI$4"$TSC_CDPR_CLI >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_GUI$4"$TSC_CDPR_GUI >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPR_LIBSIOT$4"$TSC_CDPR_LIBSYMBIOT >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory paths absolute with filenames" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_CDPAFN_CH$4"$TSC_CDPAFN_CH >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPAFN_CMK$4"$TSC_CDPAFN_CMK >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPAFN_MK$4"$TSC_CDPAFN_MK >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPAFN_SNAPYAML$4"$TSC_CDPAFN_SNAPYAML >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPAFN_SPEC$4"$TSC_CDPAFN_SPEC >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory paths reltative with filenames" >> $5
	
	$TSC_SBP_ECHOE "\n"$1"TSC_CDPRFN_CH$4"$TSC_CDPRFN_CH >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPRFN_CMK$4"$TSC_CDPRFN_CMK >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPRFN_MK$4"$TSC_CDPRFN_MK >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPRFN_SNAPYAML$4"$TSC_CDPRFN_SNAPYAML >> $5
	$TSC_SBP_ECHOE $1"TSC_CDPRFN_SPEC$4"$TSC_CDPRFN_SPEC >> $5

	$TSC_SBP_ECHOE "\n"$2" config directory path relative" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_SBP_AR$4"$TSC_SBP_AR >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_BISON$4"$TSC_SBP_BISON >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_CC$4"$TSC_SBP_CC >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_CP$4"$TSC_SBP_CP >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_CPP$4"$TSC_SBP_CPP >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_DOT$4"$TSC_SBP_DOT >> $5
	$TSC_SBP_ECHO $1"TSC_SBP_ECHO$4"$TSC_SBP_ECHO >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_ECHOE$4"$TSC_SBP_ECHOE >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_LEX$4"$TSC_SBP_LEX >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_MK$4"$TSC_SBP_MK >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_MKI$4"$TSC_SBP_MKI >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_MKDIR$4"$TSC_SBP_MKDIR >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_MKDIRI$4"$TSC_SBP_MKDIRI >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_RM$4"$TSC_SBP_RM >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_RMDIR$4"$TSC_SBP_RMDIR >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_RMDIRI$4"$TSC_SBP_RMDIRI >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_MKSILENT$4"$TSC_SBP_MKSILENT >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_TS$4"$TSC_SBP_TS >> $5
	$TSC_SBP_ECHOE $1"TSC_SBP_YACC$4"$TSC_SBP_YACC >> $5

	$TSC_SBP_ECHOE "\n"$2" linker and compiler flags" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_XOR_MKSILENT$4"$TSC_XOR_MKSILENT >> $5
	$TSC_SBP_ECHOE $1"TSC_XOR_CCWARN$4"$TSC_XOR_CCWARN >> $5

	$TSC_SBP_ECHOE "\n"$1"CFLAGS_GLIB$4"$CFLAGS_GLIB >> $5
	$TSC_SBP_ECHOE "\n"$1"CFLAGS_GTK$4"$CFLAGS_GTK >> $5
	$TSC_SBP_ECHOE "\n"$1"LIBS_GLIB$4"$LIBS_GLIB >> $5
	$TSC_SBP_ECHOE "\n"$1"LIBS_GTK$4"$LIBS_GTK >> $5

	$TSC_SBP_ECHOE "\n"$2" debugger flags" >> $5

	$TSC_SBP_ECHOE "\n"$1"TSC_XOR_DBG_GLOBAL$4"$TSC_XOR_DBG_GLOBAL >> $5
	$TSC_SBP_ECHOE $1"TSC_XOR_DBG_PRINT$4"$TSC_XOR_DBG_PRINT >> $5
	$TSC_SBP_ECHOE $1"TSC_XOR_DBG_CTRL$4"$TSC_XOR_DBG_CTRL >> $5
	$TSC_SBP_ECHOE $1"TSC_XOR_DBG_CB$4"$TSC_XOR_DBG_CB >> $5
	$TSC_SBP_ECHOE $1"TSC_XOR_DBG_SIZE$4"$TSC_XOR_DBG_SIZE >> $5
	$TSC_SBP_ECHOE $1"TSC_XOR_DBG_PTR$4"$TSC_XOR_DBG_PTR >> $5

	$TSC_SBP_ECHOE "\n"$2" end of config\n" >> $5

}

tsc_write_env "" "#" "" "=" $TSC_CDPRFN_CMK
tsc_write_env "#define " "//" "" " " $TSC_CDPRFN_CH

# parameter assignment
# $1 start remark line
# $2 language
# $3 assignment operator or empty
# $4 outputfile

tsc_write_spec(){

	$TSC_SBP_ECHOE "write" $4
	$TSC_SBP_ECHOE $1"\n"$1" Spec-File("$2") for "$2"\n"$1 > $4
	$TSC_SBP_ECHOE "Summary: "$TSC_PRJG_PNAME"("$2") "$TSC_PRJG_PSUMS >> $4
	$TSC_SBP_ECHOE "Version: "$TSC_PRJG_MAJOR"."$TSC_PRJG_MINOR >> $4
	$TSC_SBP_ECHOE "Release: "$TSC_PRJG_RELEASE"-"$TSC_PRJG_PATCH >> $4
	$TSC_SBP_ECHOE "License: "$TSC_PRJG_PLIC >> $4
	$TSC_SBP_ECHOE "Group: "$TSC_PRJG_PGRP >> $4
	$TSC_SBP_ECHOE "Source: https://github.com/Chartwalker/"$TSC_PRJG_FNAME$TSC_PRJG_VERSION".src.tgz" >> $4
	$TSC_SBP_ECHOE "URL: https://github.com/Chartwalker/"$TSC_PRJG_FNAME"/stable/doc/index.html" >> $4
	$TSC_SBP_ECHOE "\n%description: see manual pdf at "$TSC_CDPR_CONF"/"$TSC_CDN_DOC >> $4
}

tsc_write_spec "#" "de" $TSC_PRJG_LANG_DE $TSC_CDPRFN_SPEC

# parameter assignment
# $1 start remark line
# $2 language
# $3 assignment operator or empty
# $4 outputfile

tsc_write_snap_yaml(){
	$TSC_SBP_ECHOE "write" $4
	$TSC_SBP_ECHOE "name: "$TSC_PRJG_FNAME > $4
	$TSC_SBP_ECHOE "summary: "$TSC_PRJG_PSUMS >> $4
	$TSC_SBP_ECHOE "description: |" >> $4
	$TSC_SBP_ECHOE "   "$TSC_PRJG_PSUML >> $4
	$TSC_SBP_ECHOE "adopt-info: "$TSC_PRJG_FNAME >> $4
	$TSC_SBP_ECHOE "base: core22" >> $4
	$TSC_SBP_ECHOE "grade: devel" >> $4
	$TSC_SBP_ECHOE "confinement: devmode" >> $4
}

tsc_write_snap_yaml "#" "de" $TSC_PRJG_LANG_DE $TSC_CDPRFN_SNAPYAML
$TSC_SBP_CP $TSC_CDPRFN_SNAPYAML ../$TSC_CFN_SNAPYAML

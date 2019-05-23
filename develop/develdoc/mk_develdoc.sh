#!/bin/bash

tsc_man2pdf(){
    man -t $1 $2 > $2-$1.ps
    ps2pdf $2-$1.ps $2-$1.pdf
}

tsc_man2pdf 7 groff
tsc_man2pdf 1 man
tsc_man2pdf 1 groff

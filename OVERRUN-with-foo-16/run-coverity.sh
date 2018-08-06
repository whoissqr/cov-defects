#!/bin/sh
rm -rf idir
cov-make-library -of foo.xmldb model.c
cov-build --dir idir gcc -c test.c
cov-analyze --dir idir  --disable-default -en OVERRUN --model-file foo.xmldb 
cov-format-errors --dir idir  --emacs-style

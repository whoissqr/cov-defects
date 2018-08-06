#!/bin/sh
rm -rf idir
cov-make-library --security --output-file coverity/models.xmldb coverity/models.c
cov-build --dir idir gcc -c test.cpp
cov-analyze --dir idir  --disable-default -en PATH_MANIPULATION -en TAINTED_STRING --model-file coverity/models.xmldb 
cov-format-errors --dir idir  --emacs-style

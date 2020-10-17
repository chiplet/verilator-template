#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 project-name"
    exit 1
fi

MODULENAME=$1

cp -r TEMPLATE $MODULENAME
cd $MODULENAME && \
    mv MODULENAME.v $MODULENAME.v && \
    mv tb_MODULENAME.cpp tb_$MODULENAME.cpp
    sed -i '' "s/MODULENAME/$MODULENAME/g" Makefile $MODULENAME.v tb_$MODULENAME.cpp


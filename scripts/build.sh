#!/bin/bash

target_release() {
    cd release
    cmake -DCMAKE_BUILD_TYPE=Release ../..
    make
    echo "Built target in bin/release/"
    cd ../..
}

target_debug() {
    cd debug 
    cmake -DCMAKE_BUILD_TYPE=Debug ../..
    make
    echo "Built target in bin/debug/"
    cd ../..
}

# Create folder for distribution
if [ "$1" = "release" ]
then
    if [ -d "$GAME_NAME" ]
    then
        rm -rf -d GAME_NAME
    fi

    mkdir -p GAME_NAME
fi

# Creates the folder for the binaries
mkdir -p bin
cd bin 
mkdir -p release
mkdir -p debug

# Builds target
if [ "$1" = "release" ]
then
    target_release
    cp bin/release/GAME_NAME GAME_NAME/GAME_NAME
    cp -R res GAME_NAME/res
else
    target_debug
fi


#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/GAME_NAME 
else
    ./bin/debug/GAME_NAME 
fi
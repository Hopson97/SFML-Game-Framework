#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/sfml_framework 
else
    ./bin/debug/sfml_framework 
fi
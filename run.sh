#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Available maps:"
    ls -1 maps/
    echo ""
    read -p "Enter the name of the map you want to load: " map_name
    ./fdf "maps/$map_name"
else
    ./fdf "$1"
fi

#!/bin/bash

if [ -d "door_managment_fi" ]; then
	mv "door_managment_fi" "door_managment_files";
fi

mkdir -p door_managment_files/{door_configuration,door_map,door_logs}

find door_managment_files -type f -name "*.log" -maxdepth 1 -exec mv {} door_managment_files/door_logs/ \;
find door_managment_files -type f -name "*.conf" -maxdepth 1 -exec mv {} door_managment_files/door_configuration/ \;
find door_managment_files -type f -name "door_map*" -maxdepth 1 -exec mv {} door_managment_files/door_map/ \;

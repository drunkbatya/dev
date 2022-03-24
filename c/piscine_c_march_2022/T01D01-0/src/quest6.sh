#!/bin/bash

chmod +x ai_help/*

cd ai_help
./keygen.sh

find key -type f -name "file*" -delete

./unifier.sh

#!/bin/bash

./install.sh

echo "Creating build directory..."
mkdir -p "build-linux"
cd "build-linux"

echo "Gathering system information..."
NUM_CORES=$(grep -c ^processor /proc/cpuinfo)
echo "Number of cores: $NUM_CORES"
echo "Cmake version: $(cmake --version)"
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release -- -j"$NUM_CORES"
cp r-type_client ../
cp r-type_server ../
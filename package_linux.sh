#!/bin/bash

./install.sh

echo "Creating release directory..."
mkdir -p release-linux
cd release-linux

echo "Gathering system information..."
NUM_CORES=$(grep -c ^processor /proc/cpuinfo)
echo "Number of cores: $NUM_CORES"
echo "Cmake version: $(cmake --version)"
cmake ..
make -j"$NUM_CORES"
sudo make install

cp -r ../assets .
cp -r ../maps .
tar -czvf ../release-linux.tar.gz ../release-linux
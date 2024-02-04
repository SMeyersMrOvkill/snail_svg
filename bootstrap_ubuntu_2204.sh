#!/bin/bash
sudo apt-get install build-essential cmake libsdl2-dev libboost1.74-all-dev libboost-1.74-json-dev
mkdir cmk
cd cmk && cmake .. && make -j 12


#!/usr/bin/bash
cwd=$(pwd)
mkdir /VSARM
cd /VSARM
sudo apt update
sudo apt-get install git -y
git clone -b master --recurse-submodules https://github.com/raspberrypi/pico-sdk.git
cd $cwd

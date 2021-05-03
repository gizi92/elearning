#!/usr/bin/env bash

# repository for Criterion Unit Testing Framework
# Documentation: https://criterion.readthedocs.io/en/master/intro.html
# the repository of snaipewastaken doesn't support focal as distro..
touch /etc/apt/sources.list.d/snaipewastaken-ubuntu-ppa-focal.list
echo "deb [trusted=yes] http://ppa.launchpad.net/snaipewastaken/ppa/ubuntu bionic main" | tee -a /etc/apt/sources.list.d/snaipewastaken-ubuntu-ppa-bionic.list

apt-get update
apt-get upgrade -y
# install dev tools
apt-get install -y build-essential gdb cmake zip unzip git
# install Criterion Framework
apt-get install -y criterion-dev

# Build GoogleTest with CMake
# git clone https://github.com/google/googletest.git -b release-1.10.0
# cd googletest               # Main directory of the cloned repository.
# mkdir build                 # Create a directory to hold the build output.
# cd build
# cmake .. -DBUILD_GMOCK=OFF  # Generate native build scripts for GoogleTest, without GoogleMock
# make
# sudo make install           # Install in /usr/local/ by default
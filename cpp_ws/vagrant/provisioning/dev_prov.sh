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

# Setup git workspace
git config --global user.name "gizi92"
git config --global user.email "simonzsolt0308@gmail.com"
mkdir -p /home/vagrant/dev/git
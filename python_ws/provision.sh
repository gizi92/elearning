#!/usr/bin/env bash

apt update
apt upgrade -y
apt install -y python-is-python3 ipython3 python3-pip dos2unix
python -m pip install pytest
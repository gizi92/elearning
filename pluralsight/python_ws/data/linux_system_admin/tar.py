#!/usr/bin/env python3
import tarfile
import glob

def create_tarfile():
    tfile = tarfile.open("mytarfile.tar", "w")
    for file in glob.glob("/etc/*conf"):
        tfile.add(file)
    tfile.close()

create_tarfile()
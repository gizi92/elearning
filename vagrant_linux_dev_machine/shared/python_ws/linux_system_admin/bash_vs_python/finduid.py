#!/usr/bin/env python3
# find the largest UID in the password file
maxuid = 0
for line in open("/etc/passwd"):
    split = line.split(":")
    if int(split[2]) > maxuid:
        maxuid = int(split[2])

print(maxuid)
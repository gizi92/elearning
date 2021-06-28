#!/usr/bin/env bash

# find the largest UID in the password file
sort -n -t: -k3 /etc/passwd | tail -1 | cut -d: -f3
#!/usr/bin/env bash

factorial()
{
    fac=1
    for (( n = $1; n > 0; n--))
    do
        (( fac = fac * n ))
    done
    echo $fac
}

fac5=$(factorial 6)
echo factorial 6 is $fac5
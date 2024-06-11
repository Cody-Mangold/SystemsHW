#!/bin/bash
# Cody Mangold - kaj218
# CS 3424 Systems Programming
# Assignment 1, Spring 2023

if [ ! -d "./data" ]; then
    mkdir data
fi

while true; do
    echo "Enter one of the following actions or press CTRL-D to exit."
    echo "C - create a new course record"
    echo "R - read an existing course record"
    echo "U - update an existing course record"
    echo "D - delete an existing course record"
    echo "E - update enrolled student count of existing courses"
    echo "T - show total course count"



    if ! read userChoice; then
        break;
    fi

    case "$userChoice" in
    [Cc] ) bash create.bash;;
    [Rr] ) bash read.bash;;
    [Uu] ) bash update.bash;;
    [Dd] ) bash delete.bash;;
    [Ee] ) bash enroll.bash;;
    [Tt] ) bash total.bash;;
    *) echo "ERROR: invalid option";;
    esac
done

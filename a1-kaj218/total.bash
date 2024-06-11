#!/bin/bash
#Cody Mangold - kaj218
#CS-3424 Systems Programming 
#Assignment 1, Spring 2023
counter=0

for file in `ls data/*.crs`; do
    let counter++
    
done
echo "Total course records:  $counter"

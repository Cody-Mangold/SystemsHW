#!/bin/bash
# Cody Mangold - kaj218
# CS-3424 Systems Programming
# Assignment 1, Spring 2023


read -p "Department code: " dept_code
read -p "Department name: " dept_name
read -p "Course number: " course_num
read -p "Course name: " course_name
read -p "Course schedule: " course_sch
read -p "Course start date: " course_start
read -p "Course end date: " course_end
read -p "Course credit hours: " course_hours
read -p "Initial course enrollment: " course_size

filename=./data/${dept_code^^}${course_num}.crs

if [ -e $filename ]; then
echo "ERROR: course already exists"
exit 1
fi

echo "${dept_code^^} $dept_name" > $filename
echo "$course_name" >> $filename
echo "$course_sch $course_start $course_end" >> $filename
echo "$course_hours" >> $filename
echo "$course_size" >> $filename

echo "[`date`] CREATED: ${dept_code^^} $course_num $course_name" >>  ./data/queries.log


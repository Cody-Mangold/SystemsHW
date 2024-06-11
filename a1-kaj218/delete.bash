#!/bin/bash
#Cody Mangold - kaj218
#CS-3424 Systems Programming
#Assignment 1, Spring 2023

read -p "Enter a course department code and number: " dept_code course_num

filename=./data/${dept_code^^}${course_num}.crs
if [ ! -e $filename ]; then
    echo "ERROR: course not found"
    exit 1
fi

{
    read dept_code_old dept_name_old
    read course_name_old
    read course_sch_old course_start_old course_end_old
    read course_hours_old
    read course_size_old
} < $filename

rm $filename
echo "$course_num was successfully deleted."
echo "[`date`] DELETED: ${dept_code_old^^} $course_num $course_name_old" >> ./data/queries.log

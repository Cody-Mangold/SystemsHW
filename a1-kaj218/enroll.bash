#!/bin/bash
#Cody Mangold - kaj218
#CS-3424 Systems Programming
#Assignment 1, Spring 2023

read -p "Enter a course department code and number: " dept_code course_num
read -p "Enter an enrollment change amount: " change_amount
filename=./data/${dept_code^^}${course_num}.crs

if [ ! -e $filename ]; then
    echo "ERROR: course not found"
    exit 1
fi

{
    read dept_code_read dept_name_read
    read course_name_read
    read course_sch_read course_start_read course_end_read
    read course_hours_read
    read course_size_read

} < $filename

let course_size_new=$((course_size_read + change_amount))

echo "${dept_code^^} $dept_name_read" > $filename
echo "$course_name_read" >> $filename
echo "$course_sch_read $course_start_read $course_end_read" >> $filename
echo "$course_hours_read" >> $filename
echo "$course_size_new" >> $filename

echo "[`date`] ENROLLMENT: ${dept_code^^} $course_num $course_name_read" >> ./data/queries.log
echo "changed by $change_amount" >> ./data/queries.log

#!/bin/bash
#Cody Mangold - kaj218
#CS-3424 Systems Programming
#Assignment 1, Spring 2023
read -p "Enter a department code and course number: " dept_code course_num
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

echo "Course department:  $dept_code_read $dept_name_read"
echo "Course number:  $course_num"
echo "Course name:  $course_name_read"
echo "Schedule days:  $course_sch_read"
echo "Course start:  $course_start_read"
echo "Course end:  $course_end_read"
echo "Credit hours:  $course_hours_read"
echo "Enrolled Students:  $course_size_read"

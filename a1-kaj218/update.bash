#!/bin/bash
#Cody Mangold - kaj218
#CS3424 Systems Programming
#Assignment 1 , Spring 2023
read -p "Department code: " dept_code
read -p "Department name: " dept_name
read -p "Course number: " course_num
read -p "Course name: " course_name
read -p "Course meeting days: " course_sch
read -p "Course start date: " course_start
read -p "Course end date: " course_end
read -p "Course credit hours: " course_hours
read -p "Course enrollment: " course_size
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

if [[ $dept_code == "" ]]; then
    dept_code="$dept_code_old"
fi
if [[ $dept_name == "" ]]; then
    dept_name="$dept_name_old"
fi
if [[ $course_name == "" ]]; then
    course_name="$course_name_old"
fi
if [[ $course_sch == "" ]]; then
    course_sch="$course_sch_old"
fi
if [[ $course_start == "" ]]; then
    course_start="$course_start_old"
fi
if [[ $course_end == "" ]]; then
    course_end="$course_end_old"
fi
if [[ $course_hours == "" ]]; then
    course_hours="$course_hours_old"
fi
if [[ $course_size == "" ]]; then
    course_size="$course_size_old"
fi

echo "${dept_code^^} $dept_name" > "$filename"
echo "$course_name" >> "$filename"
echo "$course_sch $course_start $course_end" >> "$filename"
echo "$course_hours" >> "$filename"
echo "$course_size" >> "$filename"

echo "[`date`] UPDATED: ${dept_code^^} $course_num $course_name" >> ./data/queries.log 


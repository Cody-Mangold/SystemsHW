#!/bin/bash
#Cody Mangold - kaj218
#CS3424-0C3 Sam Silvestro
#Assignment 3 Spring 2023

BEGIN{ FS = ","}


{

id[$1]


address[$4]

listOfProblems[$3]++
listOfDivisions[$5]++
date = substr($2,2,10)

if(listOfDates[date] != date)
{
    listOfDates[date] = date
    firstCall[date] = $0
    lastCall[date] = $0
}
if( firstCall[date] > $0 )
{
firstCall[date] = $0

}
if(lastCall[date] < $0)
{
    lastCall[date] = $0
}
}
END{
    print("Total calls: " NR)
    print("\n")


    for( dates in listOfDates)
    {
        print("Date: " listOfDates[dates])
        print("\tFirst call: " firstCall[dates])
        print("\t Last call: " lastCall[dates])
    }
    print("\n")
    print("Per-problem totals:")
    for(problems in listOfProblems)
    {
        print("\t" problems ": " listOfProblems[problems])
    }
    print("\n")
    print("Per-division totals:")
    for(divisions in listOfDivisions)
    {
        print("\t" divisions ": " listOfDivisions[divisions])
    }
}

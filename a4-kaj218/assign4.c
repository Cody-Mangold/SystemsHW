//Assign4
//Cody Mangold kaj218
//Systems Programming Spring 23
#include "assign4.h"

#define BUFSIZE 4096
#define DATAFILE "courses.dat"


char buffer[BUFSIZE];
FILE * datafile;
void showMenu()
{

    printf("C - create a course record\n");
    printf("U - update an existing course record\n");
    printf("R - read an existing course record\n");
    printf("D - delete an existing course record\n");
    

}

int createCourse()
{
    COURSE courseTemp;
    COURSE courseCheck;
    int courseNum;
    printf("Course number: ");
    fgets(buffer,BUFSIZE,stdin);
    sscanf(buffer,"%d", &courseNum);
    
    printf("Course name: ");
    fgets(buffer,BUFSIZE,stdin);
    buffer[strlen(buffer) - 1] = 0;
    strncpy(courseTemp.course_Name, buffer, 84);
    
    printf("Course schedule: ");
    fgets(buffer,BUFSIZE,stdin);
    buffer[strlen(buffer) - 1] = 0;
    strncpy(courseTemp.course_Sched, buffer, 5);
    
    printf("Course credit hours: ");
    fgets(buffer,BUFSIZE,stdin);
    sscanf(buffer,"%d",&courseTemp.course_Hours);

    printf("Course enrollment: ");
    fgets(buffer,BUFSIZE,stdin);
    sscanf(buffer,"%d",&courseTemp.course_Size);
    
    fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);
    if(fread(&courseCheck, sizeof(COURSE), 1L, datafile) && courseCheck.course_Hours > 0)
    {
	printf("ERROR: course already exists\n");
	return 1;
    }
    else
    {
	fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);
	fwrite(&courseTemp,sizeof(COURSE), 1L, datafile);
    }

    return 0;
}

int updateCourse()
{

    COURSE courseTemp;
    COURSE courseCheck;
    int courseNum;
    printf("Course number: ");
    fgets(buffer,BUFSIZE,stdin);
    sscanf(buffer,"%d", &courseNum);

    fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);
    fread(&courseCheck, sizeof(COURSE), 1L, datafile);

    printf("Course name: ");
    fgets(buffer,BUFSIZE,stdin);
    if(buffer[0] == '\n')
    {
	strcpy(courseTemp.course_Name, courseCheck.course_Name);
    }
    else  
    {
	buffer[strlen(buffer) - 1] = 0;
	strncpy(courseTemp.course_Name, buffer, 84);
    }


    printf("Course schedule: ");
    fgets(buffer,BUFSIZE,stdin);
    if(buffer[0] == '\n')
    {
	strcpy(courseTemp.course_Sched, courseCheck.course_Sched);
    }
    else  
    {
	buffer[strlen(buffer) - 1] = 0;
	strncpy(courseTemp.course_Sched, buffer, 5);
    }

    printf("Course credit hours: ");
    fgets(buffer,BUFSIZE,stdin);
    if(buffer[0] == '\n')
    {
	courseTemp.course_Hours = courseCheck.course_Hours;
    }
    else  
    {
	sscanf(buffer, "%d", &courseTemp.course_Hours);
    }

    printf("Course enrollment: ");
    fgets(buffer,BUFSIZE,stdin);
    if(buffer[0] == '\n')
    {
	courseTemp.course_Size = courseCheck.course_Size;
    }
    else  
    {
	sscanf(buffer,"%d",&courseTemp.course_Size);
    }



    fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);

    fwrite(&courseTemp,sizeof(COURSE), 1L, datafile);

    return 0;
}

int readCourse()
{
    COURSE course;
    int courseNum;

    printf("Course number: ");
    if(!fgets(buffer,BUFSIZE,stdin))
    {
	return 1;
    }
    if(sscanf(buffer, "%d", &courseNum) != 1)
    {
	fprintf(stderr, "Error: unable to parse course number\n");
	return 1;
    }
    fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);

    if(!fread(&course, sizeof(COURSE), 1L, datafile) || course.course_Hours == 0)
    {
	fprintf(stderr, "ERROR: course not found\n");
	return 1;
    }
    printf("Course name: %s\n", course.course_Name);
    printf("Course schedule: %s\n", course.course_Sched);
    printf("Course size: %d\n", course.course_Size);
    printf("Course hours: %d\n", course.course_Hours);

    return 0;
}

int deleteCourse(){
    COURSE courseTemp;
    int courseNum;
    printf("Enter a course number: ");
    if(!fgets(buffer,BUFSIZE,stdin))
    {
	return 1;
    }
    if(sscanf(buffer, "%d", &courseNum) != 1)
    {
	fprintf(stderr, "Error: unable to parse course number\n");
	return 1;
    }

    fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);
    if(!fread(&courseTemp, sizeof(COURSE), 1L, datafile))
    {
	printf("ERROR: course not found\n");
	return 1;
    }

    courseTemp.course_Hours = 0;

    fseek(datafile, courseNum * sizeof(COURSE), SEEK_SET);
    if(fwrite(&courseTemp,sizeof(COURSE), 1L, datafile) != 1L){
	printf("ERROR: fwrite failed\n") ;
	return 1;
    }

    printf("course number was successfully deleted.\n");

    return 0;
}

int main(int argc, char ** agrv)
{

    char choice;
    if((datafile = fopen(DATAFILE,"rb+")) == NULL)
    {
	if((datafile = fopen(DATAFILE, "wb+")) == NULL)
	{
	    perror("could not open data file.");
	    return 1;
	}
    }
    while(true)
    {
	showMenu();
	if(!fgets(buffer, BUFSIZE,stdin))
	{
	    break;
	}
	if(sscanf(buffer, "%c", &choice)!= 1)
	{
	    fprintf(stderr, "ERROR: unable to parse menu choice.\n");
	    return 1;
	}
	switch(tolower(choice))
	{
	    case 'r':
		readCourse();
		break;
	    case 'u':
		updateCourse();
		break;
	    case 'd':
		deleteCourse();
		break;
	    case 'c':
		createCourse();
		break;
	}

    }
    return 0;
}

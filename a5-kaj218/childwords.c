//Cody Mangold
//Sam Silvestro
//Systems CS-3424-0C3
//Spring 2023

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFSIZE 65536

int myWordCount(const char* filename)
{

FILE * datafile;
char line[BUFSIZE];
const char* delim = " \t\n\r";
int numOfWords = 0;



  if((datafile = fopen(filename,"r")) == NULL)
    {
      perror("\tERROR: could not open data file.");
	    return EXIT_FAILURE;
    }
    
  while(fgets(line,BUFSIZE,datafile))
      {
        if(strtok(line,delim))
        {
          numOfWords++;
        
          while(strtok(NULL,delim))
            {
            numOfWords++;
            }
        
        }
      }
  printf("\tChild process for %s:  word count is %d\n",filename,numOfWords);
  fclose(datafile);
    
    

return EXIT_SUCCESS;
}


int main( int argc, char* argv[])
{

  int i;
  int argCount = argc - 1;
  int numOfReads = 0;
  int waitTester;

  for(i = 1; i < argc; i++)
    {
      switch(fork())
        { 
          case -1:
            perror("ERROR: could not create child proccess.");
            return 1;
          case 0:
            return myWordCount(argv[i]);
        }
    }

  while (wait(&waitTester) != -1)
    {
      if(WIFEXITED(waitTester))
        {
          if(WEXITSTATUS(waitTester) == 0)
            {
              numOfReads++;
            }
        }
    }
    
  printf("\n\t%d of %d files counted successfully\n",numOfReads, argCount);



return 0;
}

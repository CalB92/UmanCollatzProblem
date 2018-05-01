#include <stdio.h>
#include <stdlib.h>

//UMANtec Problem 1
//Program 2
//Author: Caleb Birch
//This program was tested by calling it from the command line and inserting the parameter.

int calcLength(long long int* sequence, int i);

int main(int argc,char* argv[])
{
	//Convert the parameter string to an int
	int cmdParameter = atoi(argv[1]);
	
	//Check if a command line parameter has been entered.
	if(argc == 1)
	{
		printf("\nNo parameter has been entered for upper limit.");
		return 0;
	}
	else if(argc > 2)
	{
		printf("\nToo many parameters have been entered.");
		return 0;
	}
	
	//If parameter is within limits, run the program
	if((cmdParameter >= 0 ) && (cmdParameter <= 5000000))
	{
		const int number = cmdParameter;		//The upper limit
	 
		int sequenceLength = 0;
		int startingNumber = 0;
		long long int sequence = 0;
		int length = 0;
		int i;
		
		//Add the large array to the heap
		int *cache = malloc(sizeof(int) * number);
		
		//Initialise cache
		for (i = 1; i <= number; i++) 
		{
		    cache[i] = -1;
		}
		
		cache[1] = 1;
		
		//Loop through each number until upper limit is reached.
		for ( i = 2; i < number; i++) 
		{
		    sequence = i;
		    length = 0;
		    
		    //Determine the length of each starting number
		    length = calcLength(&sequence, i);
		    
		    //Store result in cache
		    cache[i] = length + cache[sequence];
		   
		    //Check if the number has the longest sequence
		    if (cache[i] > sequenceLength) 
			{
		        sequenceLength = cache[i];
		        startingNumber = i;
		    }
		}
		free(cache);
		printf("\nThe starting number with longest collatz sequence is: %ld", startingNumber);
	}
	else
	{
		printf("\nThe upper limit is invalid, please enter a value between 0 and 5000000");
	}
	
	return 0;
}

//Returns the length of the number as an int. 
//The first parameter is a pointer to the sequence number.
//The second parameter is the counter indicating which starting number is being processed
int calcLength(long long int* sequence, int i)
{
	int length = 0;
	
	//The numbers which have already had lengths calculated are skipped.
	while (*sequence != 1 && *sequence >= i) 
	{
        length++;
        if ((*sequence % 2) == 0) 
		{
            *sequence = *sequence / 2;
        } 
		else 
		{
            *sequence = *sequence * 3 + 1;
        }
    }
    
	return length;
}

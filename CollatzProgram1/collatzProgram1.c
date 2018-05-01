#include <stdio.h>
 
//UMANtec Problem 1
//Program 1
//Author: Caleb Birch
//This program was tested by calling it from the command line and inserting the parameter.

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
		const int number = cmdParameter;				//The upper limit
	 	
		int sequenceLength = 0;
		long int startingNumber = 0;
		long long int sequence;
		int i;
		
		//Loop through each number until upper limit is reached.
		for (i = 2; i <= number; i++) 
		{
		    int length = 1;
		    sequence = i;
		    
		    //The length is determined for each starting number
		    while (sequence != 1) 
			{
		        if ((sequence % 2) == 0) 
				{
		            sequence = sequence / 2;
		        } 
				else 
				{
		            sequence = sequence * 3 + 1;
		        }
		        
		        length++;
		    }
	
		    //Check if the number has the longest sequence
		    if (length > sequenceLength) 
			{
		        sequenceLength = length;
		        startingNumber = i;   
		    }
		    
		}
		
		printf("\nThe starting number with longest collatz sequence is: %ld", startingNumber);

	}
	else
	{
		printf("\nThe upper limit is invalid, please enter a value between 0 and 5000000");
	}
    
    return 0;
}

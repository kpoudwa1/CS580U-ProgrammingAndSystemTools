#ifndef MY_LIB_H
#define MY_LIB_H

#include<stdio.h>
extern int myStrStr(char haystack[], char needle[], char buffer[])
{
	//Result field for checking substring
	int result = 0;

	//Pointers for individual arrays
	char *haystackPtr;
        char *needlePtr;
        char *bufferPtr;

	//Resetting the common buffer
        for(char *bufferResetPtr = buffer; bufferResetPtr <= bufferPtr; bufferResetPtr++)
	{
        	*bufferResetPtr = '\0';
	}

        //Initialize the buffer pointer
        bufferPtr = buffer;

        //For avoiding reinitalizing of inner loop
        haystackPtr = haystack;

	//Code for matching the substring
        for(needlePtr = needle; *needlePtr != '\0'; needlePtr++)
        {
		for(; *haystackPtr != '\0'; haystackPtr++)
                {
			if(*needlePtr == *haystackPtr)
                        {
				/*Copying the current character of the haystack to the current character of buffer
				and incrementing the buffer pointer to the next memory location*/
				*bufferPtr = *haystackPtr;
                                bufferPtr++;

                                //For poininting to next character for match, since the loop breaks
                                haystackPtr++;

				result = 1;
                                break;
			}
                        else
                        {
                                //Reseting the entire buffer
                                for(char *bufferResetPtr = buffer; bufferResetPtr <= bufferPtr; bufferResetPtr++)
	                                *bufferResetPtr = '\0';
                                bufferPtr = buffer;

				//Restarting outer loop
                                needlePtr = needle;

				result = 0;
			}
		}
        }
	//Setting the terminating character of the buffer string
	*bufferPtr = '\0';

        return result;
}

extern void binaryArray(int n, int array[], int size)
{
	//Right shifting and then masking with 1
	for(int i = size - 1; i >=0; i--, n >>= 1)
		array[i] = (n & 1);
}

extern void binaryPrinter(int array[], int size)
{
	printf("\nThe number in binary is: ");
	for(int i = 0; i < size; i++)
		printf("%d", array[i]);
	printf("\n");
}

extern unsigned int countOnes(int num)
{
	unsigned int counter = 0;
	//Right shifting and then masking with 1
	for(int i = 31; i >= 0; i--, num >>=1)
	{
		if((num & 1) == 1)
		{
			counter++;
		}
	}

	return counter;
}

#endif

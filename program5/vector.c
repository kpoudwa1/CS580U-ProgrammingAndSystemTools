#include"vector.h"
#include<stdio.h>
#include<stdlib.h>
Vector * newVector()
{
	Vector *vector = malloc(sizeof(Vector));
	vector->data = NULL;
	vector->current_size = 0;
	vector->max_size = 0;

	//Init function pointers
	vector->insert = insertVector;
	vector->read = readVector;
	vector->remove = removeVector;
	vector->delete = deleteVector;
	return vector;
}

void insertVector(Vector * array, int index, Data value)
{
	//To check if the index is within the bounds
	if(index >= array->max_size)
	{
		//Set the max size using the formula '2n + 1'
		array->max_size = ((2 * index) + 1);

		//Reallocate the array using the size of 'Data' and the formula
		array->data = realloc(array->data, array->max_size * sizeof(Data));

		//Set unused location to '-1'
		for(int i = array->current_size; i < array->max_size; i++)
        	{
                	array->data[i].value = -1;
        	}
	}
	/*else
	{
		printf("\nIndex within the bounds");
	}*/

	//Update the current size if the index at which data is to be inserted is greater than the current size
	if(index >= array->current_size)
	{
		array->current_size = index + 1;
	}

	//Inserting data in the array
	array->data[index].value = value.value;
}

Data * readVector(Vector * array, int index)
{
	Data *data = NULL;
	//Return null if the index is greater than the max size
	if(index >= array->max_size)
	{
		return data;
	}
	else//Return the data at the required index
	{
		data = &(array->data[index]);
	}

	return data;
}

void removeVector(Vector * array, int index)
{
	//Check whether the data to be removed from the list is less than the index passed
	if(index < array->max_size)
	{
		//Allocating a new array of size 'max_size - 1' and copying of data
		Data *tempData = malloc(array->max_size * sizeof(Data) - 1);
		for(int i = 0; i < array->max_size - 1; i++)
		{
			if(i < index)
			{
				tempData[i].value = array->data[i].value;
			}
			else
			{
				tempData[i].value = array->data[i + 1].value;
			}
		}
		free(array->data);
		array->data = tempData;
		array->max_size -= 1;
		int newCurrentSize = 0;
		//Updating the current size
		for(int i = (array->max_size - 1); i >= 0; i--)
		{
			if(array->data[i].value != -1)
			{
				newCurrentSize = i + 1;
				break;
			}
		}
		array->current_size = newCurrentSize;
	}
	/*else
	{
		printf("\nIndex passed is out of bounds");
	}*/
}

void deleteVector(Vector * array)
{
	free(array->data);
	free(array);
}

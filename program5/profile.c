#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "vector.h"
#include "list.h"
#include "profile.h"

void profileInsert(Vector *array, List *list)
{
	printf("\nPerforming profile insert");
        //Profiling insert for vector
        struct timeval start, stop;
        gettimeofday(&start, NULL);

        Data data_array[1000];
        for(int i = 0 ; i < 1000 ; i++)
        {
                data_array[i].value = i + 1;
                array->insert(array, i, data_array[i]);
        }

        gettimeofday(&stop, NULL);
        time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
        time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
        float profile_time_vector = stop_time - start_time;
        printf("\nTotal time for inserting for 1000 elements in vector is %f\n", profile_time_vector);

        //Profiling insert for list
        gettimeofday(&start, NULL);

        for(int index = 0 ; index < 1000 ; index++ )
        {
                list->insert(list , index, (Data){index+1});
        }

        gettimeofday(&stop, NULL);
        start_time = (start.tv_sec* 1000000) + start.tv_usec;
        stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
        float profile_time_list = stop_time - start_time;
        printf("Total time for inserting 1000 elements in list is %f\n", profile_time_list);

        if(profile_time_vector > profile_time_list)
	{
                printf("Vector takes more time than List\n\n");
        }
        else
	{
                printf("List takes more time than Vector\n\n");
        }
}

void profileRead(Vector *array, List *list)
{
        printf("\nPerforming profile read");
	//Profiling read for vector
	struct timeval start, stop;
	gettimeofday(&start, NULL);

	srand(time(NULL));
	for(int i = 0 ; i < 100 ; i++)
	{
		int index = rand()%1000;
		array->read(array, index);
	}

	//Profiling read for list
	gettimeofday(&stop, NULL);
	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	float profile_time_vector = stop_time - start_time;
	printf("\nTotal time for reading 100 elements in vector is %f\n", profile_time_vector);

	for(int i = 0; i  < 100 ; i++)
	{
		int index = rand()%1000;
		list->read(list, index);
	}

	gettimeofday(&stop, NULL);
	start_time = (start.tv_sec* 1000000) + start.tv_usec;
	stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	float profile_time_list = stop_time - start_time;
	printf("Total time for reading 100 elements in list is %f\n", profile_time_list);

	if(profile_time_vector>profile_time_list)
	{
		printf("Vector takes more time than List\n\n");
	}
	else
	{
		printf("List takes more time than Vector\n\n");
	}
}

void profileRemove(Vector *array, List *list)
{
        printf("\nPerforming profile remove");
	//Profiling remove for Vector
	struct timeval start, stop;
	gettimeofday(&start, NULL);

	for (int i = 0; i < 100; i++)
	{
		int index = rand()%1000;
	//	printf("%d ", index);
		array->remove(array, index);
	}

	gettimeofday(&stop, NULL);
	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	float profile_time_vector = stop_time - start_time;
	printf("\nProfile time for delete for 100 elements in vector is %f\n", profile_time_vector);

        //Profiling remove for List
	struct timeval start1, stop1;
	gettimeofday(&start1,NULL);
	for (int i = 0; i < 100; i++)
	{
		int index = rand()%10;
		list->remove(list , index);
	}

	gettimeofday(&stop1, NULL);
	start_time = (start1.tv_sec* 1000000) + start1.tv_usec;
	stop_time = (stop1.tv_sec* 1000000) + stop1.tv_usec;
	float profile_time_list = stop_time - start_time;
	printf("Profile time for delete for 100 elements in list is %f\n", profile_time_list);

	if(profile_time_vector>profile_time_list)
	{
		printf("Vector takes more time than List\n\n");
	}
	else
	{
		printf("List takes more time than Vector\n\n");
	}
}

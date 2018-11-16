#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int size)
{
	for(int index = 0; index < size; index++)
	{
		printf("%d ",arr[index]);
	}
	printf("\n");
}

void stable_counting_sort(int* arr, int size)
{
    
}

void counting_sort(int* arr, int size)
{
	int* count_list = (int* )calloc(RANGE, sizeof(int));
	int* sorted_list = (int* )calloc(size, sizeof(int));
	
	print_array(arr, size);
	
	// Count number of elements
	for(int index = 0; index<size; index++)
	{
		*(count_list + *(arr + index) ) +=1 ;
	}
	
	print_array(count_list, RANGE);
	
	for(int index = 1; index<RANGE ; index++)
	{
	    *(count_list + index) += *(count_list + index - 1);
	}
	print_array(count_list, RANGE);	
	
	for(int index = 0; index<size; index++)
	{
	    *(sorted_list + *(count_list + *(arr + index)) - 1) = *(arr + index);
	    
	    *(count_list + *(arr + index) ) -= 1;
	}
	print_array(sorted_list, size);
}


int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	counting_sort(arr, sizeof(arr)/sizeof(arr[0]));

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
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

int partition(int* arr, int start_index, int end_index)
{
	int small_index = start_index;
	int temp;
	
	int pivot = arr[end_index];
	
	for(int current_index = start_index; current_index<end_index; current_index++)
	{
		if( *(arr + current_index) <= pivot && current_index != small_index) 
		{
			temp = *(arr + current_index);
			*(arr + current_index) = *(arr + small_index);
			*(arr + small_index) = temp;
			
			small_index++;
		}		
	}
	
	temp = *(arr + small_index);
	*(arr + small_index) = pivot;
	*(arr + end_index) = temp;
	
	return small_index;		
}

void quick_sort(int* arr, int start_index, int end_index)
{
    if(start_index < end_index)
	{
		int partition_index = partition(arr, start_index, end_index);
		
		quick_sort(arr, start_index, partition_index-1);
		
		quick_sort(arr, partition_index+1, end_index);
	}
}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	quick_sort(arr, 0, 7);

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
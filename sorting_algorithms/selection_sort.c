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

void swap_value(int* left_addr, int* right_addr)
{
    int temp = *left_addr;
    
    *left_addr = *right_addr;
    
    *right_addr = temp;
}

void stable_selection_sort()
{
}

void selection_sort(int* arr, int size)
{
    int min_index = 0;
    // Loop over sort_index
    for(int sort_index = 0; sort_index < size-1; sort_index++)
    {
        min_index = sort_index;
        
        // Find index of minimum val in unsorted 
        for(int unsort_index = sort_index + 1; unsort_index < size; unsort_index++)
        {
            if(arr[min_index] > arr[unsort_index])
            {
                min_index = unsort_index;
            }
        }
        
        // swap the minimum value with the value at end of sorted 
        swap_value(&arr[sort_index], &arr[min_index]);
    }
}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	selection_sort(arr, sizeof(arr)/sizeof(arr[0]));

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
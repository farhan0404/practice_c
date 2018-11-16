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

void binary_insertion_sort()
{
}

void insertion_sort(int* arr, int size)
{
    int sorted_index, current_val;
    
    // loop of unsort_index
    for(int unsort_index = 1; unsort_index < size; unsort_index++)
    {
        current_val = arr[unsort_index];
        sorted_index = unsort_index - 1;
        // insert current element in sorted array by shifting elements in sorted array
        for(; sorted_index >= 0 && arr[sorted_index] > current_val;)
        {
            arr[sorted_index + 1] = arr[sorted_index];
            sorted_index--;
        }
        arr[sorted_index + 1] = current_val;
    }
}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
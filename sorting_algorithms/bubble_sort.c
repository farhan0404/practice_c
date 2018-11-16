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

void bubble_sort(int* arr, int size)
{
    for(int index = 0; index < size - 1; index++)
    {
        // Compare with adjacent if bigger then swap
        for(int comp_index = 0; comp_index < size - 1 - index; comp_index++)
        {
            if(arr[comp_index] > arr[comp_index + 1])
            {
                swap_value(&arr[comp_index], &arr[comp_index+1]);
            }
        }
    }
}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
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

void max_heapify(int* arr, int size, int node)
{
	int largest = node;
	int left_child = 2*node + 1;
	int right_child = 2*node + 2;
	
	if( left_child < size && *(arr + left_child) > *(arr + largest) )
		largest = left_child;
		
	if( right_child < size && *(arr+ right_child) > *(arr + largest) )
		largest = right_child;
	
	if( largest != node )
	{
		swap_value(&arr[node], &arr[largest]);
		
		max_heapify(arr, size, largest);
	}
}
void heap_sort(int* arr, int size)
{
	// Build heap
	// The first node which is not max heap from leave element is n/2
	for(int index = size/2; index >= 0; index--)
		max_heapify(arr, size, index);
		
	// since we have max heap
	// the root node is max element
	// move it to end and reduce the size of heap 
	// again heapify and repeat
	for(int index = size-1; index >= 0; index--)
	{
		swap_value(&arr[0], &arr[index]);
		
		max_heapify(arr, index, 0);
		
	}
}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	heap_sort(arr, sizeof(arr)/sizeof(arr[0]));

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
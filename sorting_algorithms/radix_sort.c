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

// radix sort starting with msd, recursive

// radix sort using bucket sort


int find_max(int* arr, int size)
{
    int max = arr[0];
    for(int index=1; index<size; index++)
    {
        if( *(arr+index) > max )
            max = *(arr+index);
    }
    return max;
}

// stable version of count sort
void radix_countsort(int* arr, int size, int digit_val)
{
   int* count_list = (int* )calloc(RANGE, sizeof(int));
   int* sorted_list = (int* )calloc(size, sizeof(int));
   
   for(int index=0; index<size; index++)
        *(count_list + ( *(arr+index)/digit_val)%10 ) += 1;
        
    //print_array(count_list, RANGE);    
    
    for(int index=1; index<RANGE; index++)
        *(count_list + index) += *(count_list + index -1);
        
    //print_array(count_list, RANGE);
    
    for(int index=size-1; index>=0; index--)
    {
        *(sorted_list + *(count_list + ( *(arr+index)/digit_val)%10 ) -1 ) = *(arr+index);
        *(count_list + ( *(arr+index)/digit_val)%10 ) -= 1;
    }
   
   //print_array(sorted_list, size);
   
   for(int index=0; index<size; index++)
        *(arr+index) = *(sorted_list+index);
}

void radix_sort(int* arr, int size)
{
    // Find max value
    int max = find_max(arr, size);
    
    for(int digit_val=1; max/digit_val > 0; digit_val *=10)
    {
        radix_countsort(arr, size, digit_val);
    }

}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	radix_sort(arr, sizeof(arr)/sizeof(arr[0]));

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
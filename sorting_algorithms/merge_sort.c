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

void merge(int* arr, int l_index, int m_index, int r_index)
{
    int l_arr_size = m_index - l_index + 1;
    int r_arr_size = r_index - m_index ;
    
    int l_arr[l_arr_size];
    int r_arr[r_arr_size];
    
    int merge_index = 0;
    
    for(int index = 0; index < l_arr_size; index++)
        l_arr[index] = arr[l_index + index];
    
    for(int index = 0; index < r_arr_size; index++)
        r_arr[index] = arr[m_index + 1 + index];    
        
    merge_index = l_index;        
    l_index = 0;
    r_index = 0;

    while( l_index < l_arr_size && r_index < r_arr_size)
    {
        if(l_arr[l_index] < r_arr[r_index])
        {
            arr[merge_index] = l_arr[l_index];
            l_index++;
        }
        else
        {
            arr[merge_index] = r_arr[r_index];
            r_index++;
        }
        merge_index++;
    }
    
    while(l_index<l_arr_size)
    {
        arr[merge_index] = l_arr[l_index];
        merge_index++;
        l_index++;
    }
    
    while(r_index<r_arr_size)
    {
        arr[merge_index] = r_arr[r_index];
        merge_index++;
        r_index++;
    }    
}
void merge_sort(int* arr, int l_index, int r_index)
{
    if(l_index < r_index)
    {
        int m_index = (l_index + r_index )/ 2;
        merge_sort(arr, l_index, m_index);
        merge_sort(arr, m_index + 1, r_index);
        
        merge(arr, l_index, m_index, r_index);
    }
}

int main(void)
{
	int arr[] = {12, 4, 11, 13, 4, 5, 6, 7};

	print_array(arr, sizeof(arr)/sizeof(arr[0]));

	merge_sort(arr, 0, 7);

	print_array(arr, sizeof(arr)/sizeof(arr[0]));  

	return 0;
}
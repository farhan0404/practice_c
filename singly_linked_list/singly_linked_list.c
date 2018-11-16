#include "singly_linked_list.h"

void print_llist(struct Node* node)
{
	while(node != NULL)
	{
		printf("%d -> ",node->data);
		node = node->next;
	}
	printf("\n");
}

void add_first(struct Node** ptr_head, int data)
{
	struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
	
	new_node->data = data;
	new_node->next = *ptr_head; // Value pointed by head
	
	*ptr_head = new_node; // head is now pointing 
}

void add_last(struct Node** ptr_head, int data)
{
    struct Node* start = *ptr_head;
	struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
	
	new_node->data = data;
	new_node->next = NULL;
	
	if( start == NULL )
	{
		*ptr_head = new_node;
		return;
	}
    
	while( start->next != NULL )
	{
	    start = start->next;
	}
	start->next = new_node;
}

void insert_before_val()
{
    
}

void insert_after_val()
{
    
}

void insert_after_node(struct Node* prev_node, int data)
{
    if(prev_node == NULL)
        return;
        
    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = prev_node->next;
    
    prev_node->next = new_node;
}

int remove_start(struct Node** ptr_phead)
{
    int val;
    
	if( *ptr_phead == NULL)
	    return -1;
	
	struct Node* temp;
	temp = *ptr_phead;
	
	val = temp->data; 
	
	(*ptr_phead) = temp->next;
	
	free(temp);
	return val;
}

int remove_end(struct Node* head)
{
    struct Node* prev;
    int val;
    
    if( head == NULL)
        return -1;
        
    prev = head;
    while(head->next != NULL)
    {
        prev = head;
        head = head->next;
    }
    val = head->data;
    prev->next = NULL;
    free(head);
    
    return val;
} 


int delete_key(struct Node** ptr_phead, int key)
{
	struct Node* curr,* prev;

	curr = *ptr_phead;
	prev = curr;

    // First node contains key
    if( curr->data == key )
    {
        *ptr_phead = curr->next;
        free(curr);
        return 0;
    }
    
	while( curr->next != NULL & curr->data != key)
	{
        prev = curr;
        curr = curr->next;
	}
    if( curr->data == key)
    {
        prev->next = curr->next;
        free(curr);
        return 0;
    }	
    // The key is not in the list
    return -1;
}

int delete_position(struct Node** ptr_phead, int location)
{
    struct Node* curr,* prev;
    curr = *ptr_phead;
    
    int count = 0;
    
    if( location == 1)
    {
        *ptr_phead = curr->next;
        free(curr);
        return 0;
    }
    count = 1;
    while( curr->next != NULL && count != location )
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    if( count == location )
    {
        prev->next = curr->next;
        free(curr);
        return 0;
    }
    
    return -1;
}

void delete_list(struct Node** head)
{
	struct Node* current;
	struct Node* next;
	
	current = *head;
	
	while( current != NULL)
	{
	    next = current->next;
	    free(current);
	    current = next;
	}
	
	*head = NULL;
}


int get_length_recursive(struct Node* head)
{
	if( head == NULL )
		return 0;
	else
		return ( 1 + get_length_recursive(head->next) );
}

int get_length_iterative(struct Node* head)
{
	int count;
	if (head == NULL)
		return 0;
	count = 1;
	while(head->next != NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}

search_key_recursive()
{
}

int search_key_iterative(struct Node* head, int key)
{
}

// Returns node at position, starts from 1
int get_nth_node(struct Node* head, int position)
{
	int index = 1;
	
	while(head->next != NULL && index<position)
	{
		head = head->next;
		index++;
	}
	
	if( index == position )
	{
		return head->data;
	}
	return -1;
}

int get_nth_node_from_end(struct Node* head, int position)
{
    int length;
	length = get_length_iterative(head);
	//printf("length is %d \n", length);
	
	length = get_length_recursive(head);
	//printf("length recursive is %d \n", length);
	
	return get_nth_node(head, length - position + 1);
}

int main(void)
{
	struct Node* head = NULL; // just a pointer to first element in list
	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	
	/*
	first =  (struct Node* )malloc(sizeof(struct Node));
	second = (struct Node* )malloc(sizeof(struct Node));
	third = (struct Node* )malloc(sizeof(struct Node));
	
	head->next = first;
	
	first->data = 1;
	first->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	*/
	/*
	add_first(&head,1);
	add_first(&head,2);
	add_first(&head,3);
	*/
	//add_last(&head,4);
	
	add_last(&head, 8);
	print_llist(head);
	
	add_last(&head, 9);
	print_llist(head);

	printf("Value removed from end is %d \n", remove_end(&head));
	print_llist(head);
	
	printf("Value removed from end is %d \n", remove_end(&head));
	print_llist(head);
	
	add_first(&head, 7);
	add_first(&head,3);
	print_llist(head);
	
	insert_after_node(head,1);
	print_llist(head);
	
	insert_after_node(head->next,2);
	print_llist(head);
	
	insert_after_node(head->next->next,3);
	print_llist(head);
			
	insert_after_node(head->next->next,6);
	print_llist(head);
	
	printf("Length recursive %d \n", get_length_recursive(head));
	printf("Length iterative %d \n", get_length_iterative(head));

    printf("After deleting key 3 return val %d \n", delete_key(&head,3));
	print_llist(head);	

    printf("After deleting key 6 return val %d \n", delete_key(&head,6));
	print_llist(head);
	

    printf("After deleting key 7 return val %d \n", delete_key(&head,7));
	print_llist(head);
	
    printf("After deleting key 77 return val %d \n", delete_key(&head,7));
	print_llist(head);	
	
	printf("Value removed from front is %d \n", remove_start(&head));
	print_llist(head);

	printf("Value removed from end is %d \n", remove_end(&head));
	print_llist(head);


	add_last(&head, 8);
	print_llist(head);
	
	add_last(&head, 7);
	print_llist(head);
	
	add_last(&head, 1);
	print_llist(head);
	
	add_last(&head, 9);
	print_llist(head);	

    printf("Delet val at location 1 return val %d \n", delete_position(&head,1));
	print_llist(head);		

    printf("Delet val at location 2 return val %d \n", delete_position(&head,3));
	print_llist(head);			
	
	printf("Delet val at location 3 return val %d \n", delete_position(&head,3));
	print_llist(head);			

	add_last(&head, 6);
	print_llist(head);
	
	add_last(&head, 9);
	print_llist(head);	
	
	printf("Get val at postion 3 return val %d \n", get_nth_node(head,3));
	print_llist(head);		

	printf("Get val at postion 1 return val %d \n", get_nth_node(head,1));
	print_llist(head);	
	
	printf("Get val at postion 4 return val %d \n", get_nth_node(head,4));
	print_llist(head);	
	
	printf("Length recursive %d \n", get_length_recursive(head));
	printf("Length iterative %d \n", get_length_iterative(head));	
	
	printf("Get val from end at postion 1 return val %d \n", get_nth_node_from_end(head,1));
	print_llist(head);		

	printf("Get val from end at postion 4 return val %d \n", get_nth_node_from_end(head,4));
	print_llist(head);	
	
	printf("Get val at from end postion 2 return val %d \n", get_nth_node_from_end(head,2));
	print_llist(head);		
	//delete_list(&head);
	//print_llist(head);		

}
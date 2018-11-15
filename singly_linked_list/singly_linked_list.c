#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* next;
	int data;
};

void print_llist(struct Node* node)
{
	while(node != NULL)
	{
		printf("%d -> ",node->data);
		node = node->next;
	}
	printf("\n");
}

void new_node(struct Node** ptr_head, int data)
{
	struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
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

void add_end(struct Node** ptr_head, int data)
{
    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = NULL;
    if(*ptr_head == NULL)
    {
        *ptr_head = new_node;
        return;
    }
    
    while( (*ptr_head)->next != NULL)
    {
        (*ptr_head) = (*ptr_head)->next;
    }
    (*ptr_head)->next = new_node;
    
}

void insert_before_key()
{
    
}

void insert_after_key()
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

delete_node_key()
{
	
}

delete_node_position()
{
}

void delete_list(struct Node** head)
{
    /*
    struct Node* temp;
	temp = head;
	
	if(head == NULL)
	    return;
	    
	//temp = temp->next;
	while( head->next!= NULL )
	{   temp = temp->next;
		free(head);
		head = temp;
	}
	free(head);
	*/
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

search_key_iterative()
{
}

get_nth_node()
{
}

get_nth_node_from_end()
{
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
	
	add_end(&head, 8);
		print_llist(head);
	
	add_end(&head, 9);
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
	
	delete_list(&head);
	print_llist(head);	
}
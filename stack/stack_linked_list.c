#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	
	struct Node* next;
};

void print_stack(struct Node* top)
{
	while(top != NULL)
	{
		printf("%d ",top->data);
		top = top->next;
	}
	printf("\n");
}

void push(struct Node** top, int element)
{
	struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
	
	new_node->data = element;
	
	new_node->next = *top;

	*top = new_node;	
}

int pop(struct Node** top)
{
	int data;

	struct Node* temp = *top;
	
	data = (*top)->data;
	*top = (*top)->next;
	
	free(temp);
	
	return data;
}

int top_peek(struct Node* top)
{
	return top->data;
}

int is_stack_empty(struct Node* top)
{
	return top == NULL;
}

int stack_size(struct Node* top)
{
	int size = 0;
	
	while(top != NULL)
	{
		size++;
		top = top->next;
	}
	
	return size;
}

void delete_stack(struct Node** top)
{
	struct Node* current;
	struct Node* next;
	
	current = *top;
	
	while( current != NULL )
	{
		next = current->next;
		free(current);
		current = next;
	}
	*top = NULL;
}

int main(void)
{
	struct Node* top = NULL;
	
	if( is_stack_empty(top) >0)
	{
	    printf("Stack is empty \n");
	}
	else
	{
	    printf("Stack is not empty \n");
	}
	
	push(&top, 1);	
	push(&top, 2);	
	push(&top, 3);	
	push(&top, 4);	
	push(&top, 5);
	
	print_stack(top);
	
	printf("First pop val %d \n", pop(&top));
	
	print_stack(top);
	
	printf("Peek stack %d\n", top_peek(top));
	
	print_stack(top);
	
	printf("Stack size %d \n", stack_size(top));
	
	if( is_stack_empty(top) >0)
	{
	    printf("Stack is empty \n");
	}
	else
	{
	    printf("Stack is not empty \n");
	}
	
	delete_stack(&top);
	
	print_stack(top);
	printf("Stack size %d \n", stack_size(top));	
	
}
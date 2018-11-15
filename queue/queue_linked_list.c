#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* next;
	
	int data;
};

struct Queue
{
	struct Node* head;
	struct Node* tail;
};

void print_queue(struct Node* front)
{
    int size = 0;
	printf("|");	
	while( front != NULL )
	{
	    size++;
		printf(" %d |",front->data);
		front = front->next;
	}
	printf("\n");
	//printf("\n Queue size is %d \n", size);
}

void enqueue(struct Node** q_head, struct Node** q_tail, int element)
{
	struct Node* new_element = (struct Node* )malloc(sizeof(struct Node));
	
	new_element->data = element;
	new_element->next = NULL;
	
	if(*q_tail)
	{
		(*q_tail)->next = new_element;	
	}
	*q_tail = new_element;	
	
	if(*q_head == NULL )
	{
		*q_head = *q_tail;
	}
}

int dequeue(struct Node** q_head, struct Node** q_tail)
{
    int val;
    struct Node* temp;
	if( *q_head == NULL )
	{
	    return -1;
	}
	
	val = (*q_head)->data;
	
	if( (*q_head)->next == NULL )
	{
	    *q_tail = NULL;
	}
	temp = *q_head;
	
	*q_head = (*q_head)->next;
	
	free(temp);
	
	return val;
}

int queue_size(struct Node* q_head)
{
    int size = 0;
    
    while( q_head != NULL )
    {
        size++;
        q_head = q_head->next;
    }
    return size;
}

int is_queue_empty(struct Node* head)
{
    return head == NULL;
}

void delete_queue(struct Node** q_head, struct Node** q_tail)
{
    struct Node* current;
    struct Node* next;
    
    current = *q_head;
    
    while( current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *q_head = NULL;
    *q_tail = NULL;
}

int main(void)
{
    int val;
	struct Node* q_head = NULL;
	struct Node* q_tail = NULL;
	
	enqueue(&q_head, &q_tail, 1);
	enqueue(&q_head, &q_tail, 2);
	enqueue(&q_head, &q_tail, 3);
	enqueue(&q_head, &q_tail, 4);
	enqueue(&q_head, &q_tail, 5);
	
	print_queue(q_head);
	
	printf("Queue size is %d \n",queue_size(q_head));
	
    printf("dequeued value is %d \n", dequeue(&q_head, &q_tail));

	print_queue(q_head);
    printf("dequeued value is %d \n", dequeue(&q_head, &q_tail));

	print_queue(q_head);
	
	printf("Queue size is %d \n",queue_size(q_head));	
	
	printf("hello\n");
	
	print_queue(q_head->next->next);
	
	delete_queue(&q_head, &q_tail);
	printf("Queue size is %d \n",queue_size(q_head));	
	print_queue(q_head);
}
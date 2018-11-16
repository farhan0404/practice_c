#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* next;
	int data;
};

void print_llist(struct Node* node);

void add_first(struct Node** ptr_head, int data);

void add_last(struct Node** ptr_head, int data);

void insert_before_val();

void insert_after_val();

void insert_after_node(struct Node* prev_node, int data);

int remove_start(struct Node** ptr_phead);

int remove_end(struct Node* head);

int delete_key(struct Node** ptr_phead, int key);

int delete_position(struct Node** ptr_phead, int location);

void delete_list(struct Node** head);

int get_length_recursive(struct Node* head);

int get_length_iterative(struct Node* head);

search_key_recursive();

int search_key_iterative(struct Node* head, int key);

int get_nth_node(struct Node* head, int position);

get_nth_node_from_end();


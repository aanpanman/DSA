//Avantika Suryawanshi, 20BCE2051
//Program to implement Linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node //Create a node
{
	int data;
	struct Node* next;
};

void insertAtBeginning(Node* * ref, int data) //Insert a node at begin
{
	//Allocate memory to a node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->item = data;    //insert the item
	new_node->next = (*ref);
	(*ref) = new_node;      //Move head to new node
}

void insertAfter(struct Node* node, int data) //Insert a node at a position
{
	if (node == NULL) 
	{
		printf("previous node null");
		return;
	}
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->item = data;
	new_node->next = node->next;
	node->next = new_node;
}

void insertAtEnd(struct Node** ref, int data) //Insert a node at end
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *ref;
	new_node->item = data;
	new_node->next = NULL;
	if (*ref == NULL) 
	{
		*ref = new_node;
		return;
	}
	while (last->next != NULL)
	last = last->next;
	
	last->next = new_node;
	return;
}

void deleteNode(struct Node** ref, int key) //delete a node given position
{
	struct Node *temp = *ref, *prev;
	if (temp != NULL && temp->item == key) 
	{
		*ref = temp->next;
		free(temp);
		return;
	}
	while (temp != NULL && temp->item != key) 
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) return;
	prev->next = temp->next;
	free(temp);
}

void printList(struct Node* node) //Print the linked list
{
	while (node != NULL) 
	{
		printf(" %d ", node->item);
	    node = node->next;
	}
}

int main() 
{
	struct Node* head = NULL;
	
	insertAtBeginning(&head, 2);
	insertAtBeginning(&head, 1);
	insertAtEnd(&head, 4);
	insertAtEnd(&head, 5);
	insertAfter(head->next, 3);
	
	printf("Linked list: ");
	printList(head);
	
	printf("\nAfter deleting an element: ");
	deleteNode(&head, 3);
	printList(head);
}


//Avantika Suryawanshi, 20BCE2051
//Program to impliment Stack ADT
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int i, c = 0;

typedef struct stack 
{
	int a[MAX];
	int top;
}st;

void create(st *s)  // Creating a stack
{
	s->top = -1;
}

int isfull(st *s) // Check if the stack is full 
{
	if (s->top == MAX - 1)
		return 1;
	else
		return 0;
}

int isempty(st *s) // Check if the stack is empty 
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void push(st *s, int e) // Push operation 
{
	if (isfull(s))
	{
    	printf("\n Stack overflow \n");
	} 
    else 
    {
    	s->top++;
    	s->a[s->top] = e;
    }
    c++;
}

void pop(st *s) // Remove element from stack
{
	if (isempty(s)) 
    {
    	printf("\n Stack underflow \n");
    } 
    else 
    {
    	printf("element popped= %d", s->a[s->top]);
    	s->top--;
    }
    c--;
    printf("\n");
}

void print_stack(st *s) // Print elements of stack
{
    printf("Stack: ");
    for (i = 0; i < c; i++) 
	{
    	printf("%d ", s->a[i]);
    }
    printf("\n");
}

int main() 
{
    int ch;
    st *s = (st *)malloc(sizeof(st));
    int a;

    create(s);
    printf("Enter element:");
    scanf("%d", &a);

    push(s, a);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    print_stack(s);

    pop(s);

    printf("\nAfter popping out\n");
    print_stack(s);
}
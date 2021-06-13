#include<stdio.h>
#define MAX 5

int st[MAX],top,x,i;
void create(void);
int isempty(void);
int isfull(void);
void push(int);
int pop(void);
void display(void);

void create()
{
    top = -1;
}

int isempty()
{
 	if (top == -1) 
		return 1;
	else 
		return (0);
}

int isfull()
{
 	if (top == (MAX-1)) 
		return 1;
	else 
		return (0);
}


void push(int element)
{
	if (isfull())
	{
		printf("\n Stack overflow");
	}
	else
	{
		top ++;
		st[top] = element;
	}
}

int pop() 
{
	if (isempty())
	{
		printf("\n Stack underflow");
	}
	else
	{
		int a = st[top];
 		top--;
		return a;
	}
}

void display()
{
    if(top>=0)
    {
        printf("\nStack:");
        for(i=top; i>=0; i--)
            printf("\n%d",st[i]);
    }
    else
    {
        printf("\nStack is empty");
    }
   
}

void main()
{
	int st[MAX];
	create();
	if (isempty())
		printf("\nStack is empty");
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	display();
	push(6);
	if (isfull())
		printf("\nStack is full");
	pop();
	pop();
	display();

}
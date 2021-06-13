#include <stdio.h>

#define N 5

int d[N];
int front = -1, rear = -1;

void addfront(int x)
{
	if((front == 0 && rear == N-1)||(front == rear + 1))
		printf("\nqueue is full");
	else if(front == -1 && rear == -1) 
	{
		front = rear = 0;
		d[front]=x;
	}
	else if(front == 0)
	{
		front = N-1;
		d[front]=x;
	}
	else
	{
		front--;
		d[front] =x;
	}
}

void addrear(int x)
{
	if((front == 0 && rear == N-1)||(front == rear+1))
		printf("\nqueue is full");
	else if(front == -1 && rear == -1) 
	{
		front = rear = 0;
		d[rear]=x;
	}
	else if(rear == N-1)
	{
		rear=0;
		d[rear]=x;
	}
	else
	{
		rear++;
		d[rear] =x;
	}
}

void delfront()
{
	if(front == -1 && rear == -1) 
		printf("\nqueue is empty");
	else if(rear == front)
		front = rear = -1;
	else if(front = N-1)
	{
		printf("\ndeleted: %d", d[front]);
		front=0;
	}
	else
		front++;
}

void delrear()
{
	if(front == -1 && rear == -1) 
		printf("\nqueue is empty");
	else if(rear == front)
		front = rear = -1;
	else if(rear == 0)
	{
		rear=N-1;		
		printf("\ndeleted: %d", d[rear]);
	}
	else
		rear--;
}

void display()
{
	int i = front;
	printf("\nDEqueue:");
	while (i != rear)
	{
		printf("%d ", d[i]);
		i = (i+1) % N;
	}
	printf("%d", d[rear]);
}

int main() 
{
	addrear(4);
	addfront(3);
	addrear(5);
	addfront(2);
	addrear(6);
	addfront(1);
	
	display();
	
	delfront();
	display();
	
	addrear(7);
	addrear(8);
	
	display();

	delrear();
	display();
}

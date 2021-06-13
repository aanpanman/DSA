#include <stdio.h>

#define N 5

int items[N];
int front = -1, rear = -1;

int isFull()  //Check if the queue is full 
{
	if ((front == rear + 1) || (front == 0 && rear == N - 1)) 
    	return 1;
	else
    	return 0;
}

int isEmpty() //Check if the queue is empty
{
	if (front == -1) 
		return 1;
	else
  		return 0;
}

void enQueue(int element) //Insert an element
{
	if (isFull())
    	printf("\nQueue full");
	else 
	{
    	if (front == -1) 
			front = 0;
    	rear = (rear + 1) % N;
    	items[rear] = element;
    	printf("\nInserted element = %d", element);
    }
}

void deQueue() //Delete an element
{
	int element;
	if (isEmpty()) 
	{
    	printf("\nQueue empty");
    } 
	else 
	{
    	element = items[front];
    	if (front == rear)  //if only one element, resetting
		{
      		front = -1;
      		rear = -1;
    	} 
    	else 
		{
      		front = (front + 1) % N;
    	}
    	printf("\nDeleted element = %d\n", element);
	}
}

void display() // Display the queue
{
	int i;
	if (isEmpty())
    	printf(" \nEmpty Queue");
	else 
	{
    	printf("\nFront = %d ", front);
    	printf("\nItems = ");
    	for (i = front; i != rear; i = (i + 1) % N) 
		{
      		printf("%d ", items[i]);
    	}
    	printf("%d ", items[i]);
    	printf("\nRear = %d", rear);
    }
}

int main() 
{
  deQueue();  //front = -1, queue is empty
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
  enQueue(6);  //front == 0 && rear == SIZE - 1, queue is full
  display();
  deQueue();
  display();
  enQueue(7);
  display();
  enQueue(8);  //front == rear + 1, queue is full
  return 0;
}
//Avantika Suryawanshi 20BCE2051
//Program to insert an element at position d
#include<stdio.h>
int main()
{
    int i, n, d, m;
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++) //get elements from user
	{
        scanf("%d", &arr[i]);
    }
    printf("Enter the new element\n");
    scanf("%d", &m);  //get new element
    printf("Enter the index where the new element has to be inserted\n");
    scanf("%d", &d);  //get index of new element
    int c[n+1];
    for(i = 0; i < n+1; i++) //store elements in new array
	{
        if( i == d)
		{
            c[i] = m;       
        }
        else if(i < d)
		{
            c[i] = arr[i];
        }
        else
		{
            c[i] = arr[i-1];
        }
    }
    printf("The new array is\n");
    for(i = 0; i < n+1; i++)
	{
        printf("%d ", c[i]);
    }
}


//Avantika Suryawanshi 20BCE2051
//Program to reverse an array
#include<stdio.h>

void swap(int *x, int *y)   //swapping two numbers
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int n, i;
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++)
	{
        scanf("%d", &arr[i]);  //get arrary elements from user
    }
    
    for(i = 0; i < n/2; i++)   //reversing the array
	{
        swap(arr+i, arr+n-i-1); //swapping elements
    }
    
    printf("The reversed array is\n");  //printing reversed array
    for(i = 0; i < n; i++)
	{
        printf("%d ", arr[i]);
    }
    return 0;
}


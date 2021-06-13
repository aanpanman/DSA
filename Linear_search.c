#include <stdio.h>

int linear(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return (i+1);
    }
    return -1;
}

void main() 
{
    int n;
    printf("Enter total number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter element to search:");
    scanf("%d", &x);

    int result = linear(arr, n, x);

    if (result == -1)
    {
        printf("Element not in array");
    }
    else
    {
        printf("Element is at the index %d", result);
    }
}
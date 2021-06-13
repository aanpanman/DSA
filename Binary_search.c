#include <stdio.h>

int binarySearch(int a[], int x, int low, int high) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == x)
            return (mid+1);

        else if (a[mid] < x)
            low = mid + 1;

        else if (a[mid] > x)
            high = mid - 1;
        else 
            return -1;
    }
}

void main() 
{
    int n;
    printf("Enter total number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements in ascending order:");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter element to search:");
    scanf("%d", &x);
  
    int result = binarySearch(arr, x, 0, n-1);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is at index %d", result);
}
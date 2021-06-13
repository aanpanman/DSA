//Avantika Suryawanshi 20BCE2051
//Program to rotate array elements by d
#include<stdio.h>
int main()
{
    int i, n, d, c = 0;
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++)
	{
        scanf("%d", &arr[i]);  //get array elements
    }
    
    printf("Enter the number of elements to be rotated\n");
    scanf("%d", &d);   //get vaule of d
    int temp[n];
    
    for(i = 0; i < d; i++)  //store elements up till index d in temp
	{
        temp[i] = arr[i];
    }
    
    for(i = 0; i < n-d; i++) //shift the elements by d
	{
        arr[i] = arr[i+d];
    }
    
    for(i = n-d; i < n; i++) //replace older elements with temp elements
	{
        arr[i] = temp[c++];
    }    
    printf("The rotated array is\n");
    for(i = 0; i < n; i++)
	{
        printf("%d ", arr[i]);
    }
    return 0;   
}


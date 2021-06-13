// Avantika Suryawanshi 20BCE2051
//Program to print the repated the elements with their frequencies.
#include <stdio.h>
int main()
{
    int i, j, n;
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    int arr[n], freq[n];
    printf("Enter the array elements\n"); //get elements from user 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        int ctr = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j]) //check frequency of each element by comparing
            {
                ctr++;
                freq[j] = -1;
            }
        }
        if (freq[i] != -1)
        {
            freq[i] = ctr;
        }
    }
    printf("\nThe frequency of all elements of array : \n");
    for (i = 0; i < n; i++) //print the element and its frequency
    {
        if (freq[i] != -1)
        {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }
    return 0;
}





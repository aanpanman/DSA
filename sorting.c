#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bub, insert, selc;

// To swap integers
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// To take the input
void arr_gen(int arr[], int n) 
{
    int i;
    printf("\nEnter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Bubble sort
void bub_sort(int arr[], int n) 
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            bub++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

// Selection sort
void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            selc++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr + min_idx, arr + i);
    }
}


// Insertion sort
void insert_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            insert++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void display(int arr[], int n)
{
    int i;
    printf("\nArray:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    bub = 0;
    insert = 0;
    selc = 0;

    int x1, x2, x3;
    printf("Enter number of elements in fisrt array: ");
    scanf("%d", &x1);
    int a1[x1];
    arr_gen(a1, x1);

    printf("Enter number of elements in second array: ");
    scanf("%d", &x2);
    int a2[x2];
    arr_gen(a2, x2);

    printf("Enter number of elements in third array: ");
    scanf("%d", &x3);
    int a3[x3];
    arr_gen(a3, x3);

    bub_sort(a1, x1);
    display(a1, x1);

    selection_sort(a2, x2);
    display(a2, x2);

    insert_sort(a3, x3);
    display(a3, x3);

}


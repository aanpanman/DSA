#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define N 50

struct details
{
    int roll;
    char fname[N];
    char lname[N];
    char pro[N];
    float cgpa;
};

void input(struct details arr[], int n)
{
    int i;
    printf("Enter details : \n");
    for (i = 0; i < n; i++)
    {
        printf("Reg No. : ");
        scanf("%d", &arr[i].roll);

        printf("First Name : ");
        scanf("%s", &arr[i].fname);

        printf("Last Name : ");
        scanf("%s", &arr[i].lname);

        printf("Programme : ");
        scanf("%s", &arr[i].pro);

        printf("CGPA : ");
        scanf("%f", &arr[i].cgpa);

        printf("\n");
    }
    
}

void swap(struct details *x, struct details *y) 
{
    struct details temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void sort(struct details arr[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].roll > arr[j + 1].roll)
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

int binary_search(struct details arr[], int l, int h, int x)
{
    if (h >= l)
    {
        int mid = l + (h - l) / 2;
        
        if (arr[mid].roll == x)
        {
            return mid;
        }
        if (arr[mid].roll > x)
        {
            return binary_search(arr, l, mid - 1, x);
        }
        return binary_search(arr, mid + 1, h, x);
    }
    return -1;
}

void display(struct details arr[], int r)
{
    if (r != -1)
    {
        printf("\nFound at index %d", r+1);
        printf("\nRoll number: %d", arr[r].roll);
        printf("\nName: %s %s", arr[r].fname, arr[r].lname);
        printf("\nProgramme: %s", arr[r].pro);
        printf("\nCGPA: %.1f", arr[r].cgpa);
    }
    else
    {
        printf("Not Present");
    }
}

void display_list(struct details arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d) Roll number: %d", i+1, arr[i].roll);
        printf("\nName: %s %s", arr[i].fname, arr[i].lname);
        printf("\nProgramme: %s", arr[i].pro);
        printf("\nCGPA: %.1f", arr[i].cgpa);
    }
    printf("\n");
}


int main()
{
    struct details stu[N];
    int n, result, x;

    printf("Enter number of students: ");
    scanf("%d", &n);
    input(stu, n);
    display_list(stu, n);

    sort(stu, n);
    printf("\nSorted list:");
    display_list(stu, n);

    printf("Enter roll number to search: ");
    scanf("%d", &x);
    result = binary_search(stu, 0, n - 1, x);
    display(stu, result);

    return 0;
}





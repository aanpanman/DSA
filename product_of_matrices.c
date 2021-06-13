//Avantika Suryawanshi 20BCE2051
//Program to product of 2 matrices
#include <stdio.h>
int main()
{
	int m, n; 
	printf("Enter the number of rows \n");
	scanf("%d", &m);
	printf("Enter the number of columns \n");
	scanf("%d", &n);
	int arr1[m][n], arr2[m][n],mul[m][n];
	
	printf("Enter the matrix elements\n"); //accept matrix 1
	for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			scanf("%d", &arr1[i][j]);
		}
	}
	
	printf("Enter the matrix elements\n"); //accept matrix 2
	for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			scanf("%d", &arr2[i][j]);
		}
	}
	
	printf("Multiplication of the matrix\n"); //perform multiplication
	for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			mul[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				mul[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	
	for (int i = 0; i < m; i++)  //To print result
    {
		for (int j = 0; j < n; j++)
        {
			printf("%d\t", mul[i][j]);
		}
		printf("\n");
	}
	return 0;
}


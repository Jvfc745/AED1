#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Total 20000

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort (int v[], int i)
{
    int h,j,k;
    for (h = 0; h < i; h++)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(&v[j],&v[j + 1]);
            }
        }
    }
}

void printA(int A[], int f)
{
    int k;
    for (k = 0; k < f; k++)
    {
        printf("%d ",A[k]);
    }
}

int main()
{
    int arr[Total];
    for(int i = 0 ; i < Total ; i++ )
    {
      arr[i] = rand() % Total;
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    double time_spent = 0.0;
	clock_t begin = clock();
    selectionSort(arr, size - 1);
    //printA(arr,size);
    clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n", time_spent);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Total 20000


void InsertionSort(int A[], int f)
{
    int j;
    int i;
    int key;

    for (i = 1; i < f; i++)
    {
        j = i - 1;
        key = A[i];
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
    int A[Total];
    int f;
    for(int i = 0 ; i < Total ; i++ ) {
      A[i] = rand() % Total;
    }
    f = sizeof(A)/sizeof(A[0]);
    double time_spent = 0.0;
	clock_t begin = clock();
    InsertionSort(A,f);



    clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n", time_spent);
    return 0;
}
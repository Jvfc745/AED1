//Base do codigo pela apostila Algoritmos em C do Paulo Feofiloff
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Total 20000


void intercala (int p, int q, int r, int v[]){
    int i, j,k,*w;
    w = malloc((r - p)*sizeof(int));
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r)
    {
        if (v[i] <= v[j])
        {
            w[k++] = v[i++];
        }
        else
        {
            w[k++] = v[j++];
        }
    }
    while (i < q)
    {
        w[k++] = v[i++];
    }
    while (j < r)
    {
        w[k++] = v[j++];
    }
    for ( i = p; i < r; i++)
    {
        v[i] = w[i-p];
    }
    free(w);
}

void mergeSort (int p, int r, int v[])
{
    if (p < r - 1)
    {
        int q;
        q = (p + r)/2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
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
    for(int i = 0 ; i < Total ; i++ ) {
      arr[i] = rand() % Total;
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    double time_spent = 0.0;
	clock_t begin = clock();
    mergeSort(0, size, arr);
    //printA(arr,size);
    clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n", time_spent);
    return 0;
}

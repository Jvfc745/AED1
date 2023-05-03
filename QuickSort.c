//Base do codigo pela apostila Algoritmos em C do Paulo Feofiloff
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

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
    {
        if (v[k] <= c)
        {
            swap(&v[j],&v[k]);
            j++;
        }
    }
    v[r] = v[j], v[j] = c;    
    return j;
}

void Quicksort (int p, int r, int v[])
{
    int j;
    if (p < r) {
    j = Separa (p, r, v);
    Quicksort (p, j - 1, v);
    Quicksort (j + 1, r, v);
    }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
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
    Quicksort(0,Total,arr);
    //printArray(arr,size);
    clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n", time_spent);
    return 0;
}

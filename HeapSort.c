#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Total 5


void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void InsereEmHeap (int m, int v[]) {
int f = m;
while (f > 0 && v[f/2] < v[f]) {
swap(&v[f/2],&v[f]);
f = f/2;
}
}


void SacodeHeap (int m, int v[]) {
int t, f = 2;
while (f <= m) {
if (f < m && v[f] < v[f+1]) ++f;
if (v[f/2] >= v[f]) break;
swap(&v[f/2],&v[f]);
f *= 2;
}
}

void Heapsort (int n, int v[]) {
int m;
    for (m = 0; m < n; m++)
    {
      InsereEmHeap (m, v);
    }
    for (m = n; m > 1; m--)
    {
      int t = v[1]; v[1] = v[m]; v[m] = t;
      SacodeHeap (m-1, v);
    }
    for (m = n; m > 1; m--)
    {
      int t = v[1]; v[1] = v[m]; v[m] = t;
      SacodeHeap (m-1, v);
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
    for(int i = 0 ; i < Total ; i++ ) {
      arr[i] = rand() % Total;
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    double time_spent = 0.0;
	  clock_t begin = clock();
    Heapsort(size - 1, arr);
    swap(&arr[0],&arr[size - 1]);
    
    printArray(arr,size);
    clock_t end = clock();
	  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n", time_spent);
    return 0;
}

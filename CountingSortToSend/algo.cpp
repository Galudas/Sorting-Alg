#include "algo.h"

int maxArray(int *a, int n)
{
    int i;
    int max = a[0];

    for (i = 1; i < n; ++i)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
void counting_sort(int *a, int n, int max)
{   
	int counter = 0;
    int i, j;
    if(n == 0){
        printf("Empty\n");
        return;
    }
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (i = 0; i < n; ++i)
        count[a[i]] = count[a[i]] + 1;

    for (i = 0; i <= max; ++i){
        for (j = 1; j <= count[i]; ++j)
        {
			a[counter] = i;
			counter++;
        }
		
	}
    free(count);
}
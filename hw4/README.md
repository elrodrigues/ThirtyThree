This is a copy of hw4.txt

The following is my optimized version of transpose() that makes use of loop unrolling and blocks for better cache use.

This version reduces time taken by 60 to 70 percent of the original function.
```c
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define mN 7789 // matrix size
#define MEM_SIZE (sizeof(int)*mN*mN)

void transpose(int *dst, int *src, int dim){
  int i, j;
	int I, J;
	int B = 13; // Magic number on seasnet server.
        int s1, s2;
        int lim = dim - B;
	for(I = 0; I <= lim; I+=B) // Matrix split into blocks of size B
		for(J = 0; J <= lim; J+=B) // This reduces miss rate of cache
			for(i = I; i < I + B; i++){
				int l1 = J + B - 1;
				for(j = J; j < l1; j+=2) // Loop unrolling reduces time further
				{
					s1 = j*dim + i;
					s2 = i*dim + j;
					dst[s1] = src[s2];
					dst[s1+dim] = src[s2 + 1];
				}
				if(j < l1 + 1)
					dst[j*dim + i] = src[i*dim + j];
			}
	int bound = i; // Take care of remaining boundary cases
	for(i = bound; i < dim; i++) // Row cases
		for(j = 0; j < bound; j++)
			dst[j*dim + i] = src[i*dim + j];

	for(i = 0; i < dim; i++) // Column cases
		for(j = bound; j < dim; j++)
			dst[j*dim + i] = src[i*dim + j];			
				
}
int main() // Test the transpose function.
{
        int* tr = (int*) malloc(MEM_SIZE);
	int* mat = (int*) malloc(MEM_SIZE);
        clock_t begin = clock();
        long t;
        for(t = 0; t < 10; t++) // This function takes 4.77s; original: 13s.
        {
                transpose(tr, mat, mN);
        }
        clock_t end = clock();
        double time_elapsed = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("Time elapsed: %f\n", time_elapsed);
	free((void*) tr);
	free((void*) mat);
	return 0;
}
```

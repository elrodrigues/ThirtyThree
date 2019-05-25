#include<time.h>
#include<stdio.h>
void transpose(int *dst, int *src, int dim){
	int i, j;
	for(i = 0; i < dim; i++)
		for(j = 0; j < dim; j++)
			dst[j*dim+i] = src[i*dim+j];
}
int main()
{
	int tr[25];
	clock_t begin = clock();
	long t;
	for(t = 0; t < 100000000; t++)
	{
		int mat[25];
		transpose(mat, tr, 5);
	}
	clock_t end = clock();
	double time_elapsed = ((double)(end - begin)) / CLOCKS_PER_SEC;
	printf("Time elapsed: %f\n", time_elapsed);
}

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define mN 7789
#define MEM_SIZE (sizeof(int)*mN*mN)

void transpose(int *dst, int *src, int dim){
        int i, j;
        for(i = 0; i < dim; i++)
                for(j = 0; j < dim; j++)
                        dst[j*dim+i] = src[i*dim+j];
		
}
int main()
{
        int* tr = (int*) malloc(MEM_SIZE);
	int* mat = (int*) malloc(MEM_SIZE);
	//printf("Dimensions: %d\n", mN);
	//int mat[9] = {0, 0, -1, 0, 2, 0, 1, 0, 0};
	//int tr[9];
        clock_t begin = clock();
        long t;
        for(t = 0; t < 10; t++)
        {
                transpose(tr, mat, mN);
        }
        clock_t end = clock();
        double time_elapsed = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("Time elapsed: %f\n", time_elapsed);
	//int k;
	//for(k = 0; k < 9; k++)
	//	printf("%d ", tr[k]);
	//printf("\n");
	free((void*) tr);
	free((void*) mat);
}


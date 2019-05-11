#include<stdio.h>
#include<time.h>
void psums1a(float a[], float p[], long n)
{
  long i, j, k;
  float v1, v2, v3;
  v1 = p[0] = a[0];
  v3 = v2 = v1;
  for (i = 1; i < n - 2; i+=3){
    j = i + 1;
    k = i + 2;
    v1 += a[i];
    v2 += (a[i] + a[j]);
    v3 += (a[i] + a[j] + a[k]);
    p[i] = v1;
    p[j] = v2;
    p[k] = v3;
    v1 = v2 = v3;
  }
  for(; i < n; i++)
  {
     v1 += a[i];
     p[i] = v1;
  }
}
int main()
{
	double total_time;
	clock_t start, end;
	start = clock();
	float a[20] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
		9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0,
		17.0, 18.0, 19.0, 20.0};
	float p[20];
	for(int i = 0; i < 1000000000; i++)
		psums1a(a, p, 20);
  //psums1a(a, p, 20);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken: %f\n", total_time);
  for(int i = 0; i < 20; i++)
    printf("%f ", p[i]);
  printf("\n");
	return 0;
}

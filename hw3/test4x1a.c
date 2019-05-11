#include<stdio.h>
#include<time.h>
void psums1a(float a[], float p[], long n)
{
  long i;
  float v1, v2, v3, v4;
  v1 = p[0] = a[0];
  v1 = p[1] = v1 + a[1];
  v1 = p[2] = v1 + a[2];
  v1 = p[3] = v1 + a[3];
  v2 = v1 + a[4];
  v3 = v2 + a[5];
  v4 = v3 + a[6];
  for (i = 4; i < n - 3; i+=4){
    v1 = v1 + a[i];
    v2 = v2 + a[i+1];
    v3 = v2 + a[i+2];
    v4 = v3 + a[i+3];
    //printf("%ld %f %f %f %f\n", i, v1, v2, v3, v4);
    p[i] = v1;
    p[i+1] = v2;
    p[i+2] = v3;
    p[i+3] = v4;
    v1 = v2 = v3 = v4;
  }
  for(; i < n; i++)
  {
	   p[i] = v4 + a[i];
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
	// for(int i = 0; i < 1000000000; i++)
	// 	psums1a(a, p, 20);
  psums1a(a, p, 20);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken to print 25000 random number is: %f\n", total_time);
  for(int i = 0; i < 20; i++)
    printf("%f ", p[i]);
  printf("\n");
	return 0;
}

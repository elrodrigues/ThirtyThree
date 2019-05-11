#include<stdio.h>
#include<time.h>
#include<assert.h>
void psum3_3(float a[], float p[], long n)
{
  long i, j, k;
  float v1, v2, v3;
  //float t1, t2, t3;
  v1 = v2 = v3 = 0;
  float lval;
  lval = p[0] = a[0];
  for (i = 1; i < n - 2; i+=3){
    j = i + 1;
    k = i + 2;
    v1 += a[i];
    p[i] = v1 + (v2 + v3);
    v2 += a[j];
    p[j] = v1 + (v2 + v3);
    v3 += a[k];
    p[k] = v1 + (v2 + v3);
    //t4 = a[l]#define LOOP 1000
    //v1 = lval + t1;
    //v2 = lval + (t1 + t2);
    //v3 = lval + (t1 + t2 + t3);
  }
  lval = v1 + v2 + v3;
  for(; i < n; i++)
  {
    lval += a[i];
     p[i] = lval;
  }
}
#define LOOP 100000
#define LEN  1000

int main(int argc, char* argv[]) {
  double total_time;
  clock_t start, end;
  start = clock();
  float a[5] = { 1, 2, 3, 4, 5 };
  float p[5];
  psum1a(a, p, 5);
  assert(p[4] == 15);

  //float q[5];
  //psum_4_1a(a, q, 5);
  //assert(q[4] == 15);

  /* for prof */
  int i;
  for (i = 0; i < LOOP; i++) {
    float s[LEN];
    float d[LEN];
    psum1a(s, d, LEN);
  }
  end = clock();
  total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken to print 25000 random number is: %f\n", total_time);
  return 0;
}

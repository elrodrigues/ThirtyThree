#include<stdio.h>
#include<time.h>
void psums1a(float a[], float p[], long n)
{
  long i;
  float val;
  val = p[0] = a[0];
  for (int i = 1; i < n; i++){
    val += a[i];
    p[i] = val;
    //last_val = val;
  }
}
#define LOOP 1000
#define LEN  1000

int main(int argc, char* argv[]) {
  double total_time;
  clock_t start, end;
  start = clock();
  float a[5] = { 1, 2, 3, 4, 5 };
  float p[5];
  psum1a(a, p, 5);
  assert(p[4] == 15);

  float q[5];
  psum_4_1a(a, q, 5);
  assert(q[4] == 15);

  /* for prof */
  int i;
  for (i = 0; i < LOOP; i++) {
    float s[LEN];
    float d[LEN];
    psum_4_1a(s, d, LEN);
  }
  end = clock();
  total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken to print 25000 random number is: %f\n", total_time);
  return 0;
}

void psum_4x1a(float a[], float p[], long n) {
  long i;
  float val, last_val;
  float tmp0, tmp1, tmp2, tmp3;
  last_val = p[0] = a[0];

  for (i = 1; i < n - 4; i++) {
    tmp0 = last_val + a[i];
    tmp1 = tmp0 + a[i+1];
    tmp2 = tmp1 + a[i+2];
    tmp3 = tmp2 + a[i+3];

    p[i] = tmp;
    p[i+1] = tmp1;
    p[i+2] = tmp2;
    p[i+3] = tmp3;

    last_val = last_val + (a[i] + a[i+1] + a[i+2] + a[i+3]);
  }

  for (; i < n; i++) {
    last_val += a[i];
    p[i] = last_val;
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

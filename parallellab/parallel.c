//OpenMP version.  Edit and submit only this file.
/* Enter your details below
 * Name : Elvis Rodrigues
 * UCLA ID : 804997981
 * Email : eldav.rodrigues99@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

void work_it_par(long *old, long *new) {
  int i, j, k;
  int u, v;
  long compute_it;
  long aggregate=1.0;
  int l1, l2;
  long need = we_need_the_func();
  long gimmie = gimmie_the_func();
  int limit = DIM - 1;
  int DIMSQ = DIM * DIM;
  long acc1, acc2, acc3 = 0;
  omp_set_num_threads(16); // Set accordingly - be careful!
  #pragma omp parallel for private(j, k, l1, l2) reduction(+:acc1, acc2, acc3)
  for (i=1; i<limit; i++) {
    l1 = i * DIMSQ;
    for (j=1; j<limit; j++) {
      l2 = l1 + j*DIM;
      for (k=1; k < limit - 2; k += 3) {
        acc1 += (old[l2 + k] * need) / gimmie;
        acc2 += (old[l2 + k + 1] * need) / gimmie;
	      acc3 += (old[l2 + k + 2] * need) / gimmie;
      }
      for(; k < limit; k++)
         acc1 += (old[l2 + k] * need) / gimmie;
    }
  }
  aggregate = acc1 + acc2 + acc3 + 1;
  printf("AGGR:%ld\n",aggregate);
  acc1 = acc2 = acc3 = 0;
  long acc4, acc5, acc6 = 0;
  long acc7, acc8, acc9 = 0;
  int index;
  #pragma omp parallel for private(j, k, l1, l2, index) reduction(+:acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9)
  for (i=1; i<limit; i++) {
    l1 = i * DIMSQ;
    for (j=1; j<limit; j++) {
      l2 = l1 + j*DIM;
      for (k=1; k<limit; k++) {
        index = l2 - DIMSQ + k;
        acc1 += (old[index - 1 - DIM] + old[index - DIM] + old[index + 1 - DIM]);
        acc2 += (old[index - 1] + old[index] + old[index + 1]);
        acc3 += (old[index - 1 + DIM] + old[index + DIM] + old[index + 1 + DIM]);
        index += DIMSQ;
        acc4 += (old[index - 1 - DIM] + old[index - DIM] + old[index + 1 - DIM]);
        acc5 += (old[index - 1] + old[index] + old[index + 1]);
        acc6 += (old[index - 1 + DIM] + old[index + DIM] + old[index + 1 + DIM]);
        index += DIMSQ;
        acc7 += (old[index - 1 - DIM] + old[index - DIM] + old[index + 1 - DIM]);
        acc8 += (old[index - 1] + old[index] + old[index + 1]);
        acc9 += (old[index - 1 + DIM] + old[index + DIM] + old[index + 1 + DIM]);
        new[l2+k] = (acc1 + acc2 + acc3 + acc4 + acc5 + acc6 + acc7 + acc8 + acc9) / 27;
        acc1 = acc2 = acc3 = 0;
        acc4 = acc5 = acc6 = 0;
        acc7 = acc8 = acc9 = 0;
      }
    }
  }
  acc1 = acc2 = acc3 = 0;
  acc4 = acc5 = acc6 = 0;
  acc7 = acc8 = acc9 = 0;
  long acc0 = 0;
  #pragma omp parallel for private(j, k, u, v, l1, l2) reduction(+:acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9)
  for (i=1; i<limit; i++) {
    l1 = i * DIMSQ;
    for (j=1; j<limit; j++) {
      l2 = l1 + j*DIM;
      for (k=1; k<limit - 1; k+=2) {
        int flip = 1;
        u = (new[l2+k]/100);
        v = (new[l2+k + 1]/100);
        if (u<=0) u=0;
        if (v<=0) v=0;
        if (u>=9) u=9;
        if (v>=9) v=9;
        zawarudo:
        switch(u){
          case 0:
            acc0++; break;
          case 1:
            acc1++; break;
          case 2:
            acc2++; break;
          case 3:
            acc3++; break;
          case 4:
            acc4++; break;
          case 5:
            acc5++; break;
          case 6:
            acc6++; break;
          case 7:
            acc7++; break;
          case 8:
            acc8++; break;
          case 9:
            acc9++; break;
        }
        if(flip){
         u = v;
	       flip = 0;
         goto zawarudo;
        }
      }
    }
  }
  histogrammy[0] = acc0; histogrammy[1] = acc1; histogrammy[2] = acc2;
  histogrammy[3] = acc3; histogrammy[4] = acc4; histogrammy[5] = acc5;
  histogrammy[6] = acc6; histogrammy[7] = acc7; histogrammy[8] = acc8;
  histogrammy[9] = acc9;
}

#pragma scop
/* Clay
   peel_after([0], [0,-5]);
*/
for(i = 10 ; i <= N-8 ; i++) {
  a[i] = 0;
}
#pragma endscop

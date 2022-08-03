#include <stdio.h>

/*
 * 1 if x has an odd number of 1s, zero otherwise.
 * Assume w=32
 * Maximum 12 operations
 */
int odd_ones(unsigned x)
{
  // The XOR operation preserves bit parity, and so repeatedly halving and XORing will have 2 log(32) + 1 = 11 ops
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 1;
}

int main()
{
  int x;
  printf("x = 0x");
  scanf("%x", &x);
  printf("bit parity of 0x%08x is %d\n", x, odd_ones(x));
}
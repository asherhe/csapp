#include <stdio.h>

/*
 * Generate mask indicating leftmost 1 in x.
 * Assume w=32
 * For example, 0xff00 -> 0x8000 and 0x6600 --> 0x4000
 * Return 0 if x == 0
 */
int leftmost_one(unsigned x)
{
  // Fill x with 1s starting from the leftmost 1
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;
  return x ^ (x >> 1); // Take only the leftmost one
}

int main()
{
  unsigned x;
  printf("x = 0x");
  scanf("%x", &x);
  printf("leftmost of 0x%08x -> 0x%08x\n", x, leftmost_one(x));
}
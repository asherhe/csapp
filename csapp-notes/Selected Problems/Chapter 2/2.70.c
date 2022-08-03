#include <stdio.h>

int fits_bits(int x, int n)
{
  // x fits if extrabits is either 0 (nonnegative) or -1 (negative)
  // caveat: fitting, for example, 0b1101 to two bits gives 0b11, which looks like it works but (0b01 = 1) != (0b1101 = -3)
  int extrabits = x >> n;
  int zero = -!extrabits;
  int fits2scomp = !((x >> (n - 1)) + 1); // check if the nth bit is 1 as well as checking if the whole thing is a bunch of leading ones
  return fits2scomp | zero;
}

int main()
{
  int x, w;
  printf("x, w = 0x");
  scanf("%x%d", &x, &w);
  printf("0x%08x fits in %d bits: %d\n", x, w, fits_bits(x, w));
}
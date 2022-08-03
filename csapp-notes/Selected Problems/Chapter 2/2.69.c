#include <stdio.h>

int rotate_left(unsigned x, int n)
{
  int shift = x << n;

  int mask = ((1 << n) - 1) << (31 - n) << 1; // Circumvent issues with n = 0

  int rotate = (mask & x) >> (31 - n) >> 1;

  return shift | rotate;
}

int main()
{
  unsigned x;
  int n;
  printf("x << n (rotational)\n(0x)x, n = ");
  scanf("%x%d", &x, &n);
  printf("0x%08x << %d (rotational) = 0x%08x\n", x, n, rotate_left(x, n));
}
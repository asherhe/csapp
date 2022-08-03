#include <stdio.h>

int lower_one_mask(int n)
{
  int mask = (1 << (n - 1)) << 1; // Things get tricky at n = w so split the shift in half
  return mask - 1;
}

int main()
{
  int w = sizeof(int) * 8;
  for (int i = 1; i <= w; i++)
    printf("%2d: 0x%08x\n", i, lower_one_mask(i));
}
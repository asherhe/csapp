#include <stdio.h>
#include <limits.h>

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  if (x < 0)
  {
    x = ~x;
  }

  int lo = 0, hi = 31, mid;
  while (lo != hi) // Not the same value
  {
    mid = (lo + hi) / 2; // Recompute
    int midBit = x >> mid;
    // printf("hi=%2d; lo=%2d; mid=%2d; val=%d\n", hi, lo, mid, midBit); // Debug
    if (midBit == 0)
    {
      hi = mid;
    }
    else
    {
      lo = mid + 1;
    }
  }

  return lo + 1; // Since bits start at 0
}

int main()
{
  int vals[6] = {12,
                 298,
                 -5,
                 0,
                 -1,
                 0x80000000};

  for (int i = 0; i < 6; i++) {
    printf("howManyBits(%d) = %d\n", vals[i], howManyBits(vals[i]));
  }

  return 0;
}
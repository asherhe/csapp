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
  if (x >> 31)
  {
    x = ~x;
  }

  // Iteration 1
  int lo = 0, hi = 31, mid = 15;
  int midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 2
  mid = (lo + hi) >> 1; // Shorthand for halving
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 3
  mid = (lo + hi) >> 1;
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 4
  mid = (lo + hi) >> 1;
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 5
  mid = (lo + hi) >> 1;
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
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

  for (int i = 0; i < 6; i++)
  {
    printf("howManyBits(%d) = %d\n", vals[i], howManyBits(vals[i]));
  }

  return 0;
}
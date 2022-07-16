---
tags: floating-point 
aliases: 
date created: 2022/06/29 9:45:46 pm
date modified: 2022/07/15 9:20:07 pm
---

# floatFloat2Int

#lab #datalab #chapter-2 #floating-point #2s-compliment

Since a normalized floating-point value is equivalent to $\texttt{sign}\cdot\texttt{frac}\cdot2^\texttt{exp}$, all we need to do is to shift `frac` by `exp` and apply the sign as necessary.

`exp`s are biased to allow for negative exponents so we have to correct for the bias before doing anything.

If `exp` is negative, the integer representation of the floating-point number will be less than zero, no matter what `frac` is, so in that case, we return 0.

If `exp` is greater than 23, then we also bail because that's as far as the `frac` component goes (otherwise we will lose precision).

So afterwards we shift `frac` by the exponent and return.

```c
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
  // Get the three components of a floating-point number
  unsigned signMask = 0x80000000;
  unsigned expMask = 0x7f800000;
  unsigned fracMask = 0x007fffff;
  int sign = uf & signMask;
  int exp = ((uf & expMask) >> 23) - 0x7f; // account for bias
  // printf("0x%08x\t%d\n", uf, exp);
  int frac = (uf & fracMask) + 0x00800000; // also include the implied 1

  if (exp < 0)
    return 0; // less than zero
  if (exp > 23)
    return 0x80000000; // doesn't fit in an int

  frac >>= 23 - exp;
  if (sign == signMask)
    frac = -frac;
  return frac;
}
```

**Operations:** 12

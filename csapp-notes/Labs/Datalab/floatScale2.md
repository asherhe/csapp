---
date created: 2022/06/29 9:22:45 pm
date modified: 2022/06/29 9:45:30 pm
---

# floatScale2

#lab #datalab #chapter-2 #floating-point

In most cases, scaling a floating-point number by two is a matter of incrementing the `exp` component of the number.

There are, however, three cases to consider - $\pm0$, special values ($\pm\infty$ and $NaN$), and denormalized values. In the case of the first two, doubling has no effect, so if we have one of these cases we just return.

For denormalized values. we have to left-shift the `frac` component by one. If the most significant bit of `frac` is `1`, this will overflow, but thanks to the smart people who devised the floating-point standard, we can continue as usual.

```c
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
  // Get exponent part of the number
  unsigned expMask = 0x7f800000; // binary: 0 11111111 00000000000000000000000 - selects the exp portion of the float
  unsigned fracMask = 0x7fffff;  // binary: 0 00000000 11111111111111111111111 - selects the frac portion of the float
  unsigned exp = uf & expMask;
  if (uf << 1 == 0) // Positive or negative zero
    return uf;
  if (exp == expMask) // "Special" value - infinities and NaN
    return uf;        // No need to do anything; double a special value is still itself
  if (exp == 0)
  {                                // Denormalized values
    unsigned frac = uf & fracMask; // the fraction portion of the floating-point number
    frac <<= 1;
    // if the value overflows the exponent should in theory be one anyways
    // frac &= fracMask;
    uf &= ~fracMask;
    return uf | frac;
  }

  // Normalized Values
  exp += 0x00800000; // Add one to the exponent
  uf &= ~expMask;    // clear the exponent
  return uf | exp;   // add the exponent
}
```

**Operations:** #todo

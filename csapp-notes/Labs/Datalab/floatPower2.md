---
tags: 
date created: 2022/07/06 7:49:34 pm
date modified: 2022/07/06 7:52:22 pm
---

# floatPower2

#lab #datalab #chapter-2 #floating-point

With floating-point powers, the `frac` component is `0`, so the only thing we really need to modify is the `exp` component (since all exponents are positive).

We also have to confront corner cases, but that's relatively easy (just check when the exponent goes denorm or $NaN$)

Finally we account for bias by adding `0x7f`, and then shifting by 23 to put it into place

```c
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
  if (x < -126) // too small to be expressed with floating-point
    return 0;
  if (x > 127) // too large for floating-point
    return 0x7f800000;
  return (0x7f + x) << 23;
}
```

**Operations:** #todo

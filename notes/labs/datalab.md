# Implementation Notes for Datalab

## `bitXor`

`x^y` can alternatively be expressed as `(~x & y) | (x & ~y)`. However, `|` (logical OR) is not allowed here, so we apply De Morgan's Laws to substitute `x|y` with `~(~x & ~y)`

```c
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  // x^y = (~x & y) | (x & ~y)
  // The | operator is forbidden so we substitute it for &s and ~s using De Morgan's Laws
  return ~(~(~x & y) & ~(x & ~y));
}
```

**Operators:** 8

## `tMin`

The smallest two's complement integer is always `1000...0000`. To construct this in the case of 32 bits, we left shift 1 by 31 bits.

```c
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  // tmin is just a 1 followed by zeros
  return 1 << 31;
}
```

**Operators:** 1

## `isTmax`

`tMax` has a special property that adding one has the same effect as bitwise negation. `-1` is the only other two's complement number that shares this property. To test if `x == tMax`, we check if `~x == x + 1` while also maintaining that `x != -1`.

Unfortunately, `==` and `!=` are prohibited. What is not prohibited though, is `!`, the logical negation operator. `!x` is `true` (`-1`) if `x` is zero and `false` (`0`) otherwise. We can exploit this fact to construct `==`:

```c
a == b  =>  !(a-b)
```

However, the subtraction operator `-` is also prohibited. Rather than implementing subtraction (`a-b  =>  a + ~b + 1`, three operations), we can use `a^b` in place of `a-b`. All we are doing with the subtraction operator anyway is checking that two values have the same value. It is apparent that `^` has the same effect if we look at its truth table:

```
 ^ | 0 | 1
 0 | 0 | 1 
 1 | 1 | 0
```

So substituting `-` for `^`, we can make the following simplifications:

```c
   ~x == x + 1 && x != -1
=> ~x ^ (x + 1) == 0 && ~!(x + 1)
=> !(~x ^ (x + 1)) & ~!(x + 1)
```

If we extract `x + 1` into a variable to save operations, we get the following code:

```c
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  // tMax and -1 are the only two's complement integers such that adding one has the same effect as a bitwise negation operation
  // Test if the property holds and ensure that x != -1
  int add1 = x + 1;
  return !(~x ^ add1) & ~!add1;
}
```

**Operators:** 7

## `allOddBits`

```c
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  // Build mask (0xAAAAAAAA) first - rather than shifting 4 times, we only need
  // 2 shifts and 2 ORs
  int mask = (0xAA << 8) | 0xAA;
  // We can only express byte values, but no need to write the definition of mask again
  mask = (mask << 16) | mask;
  return !((x & mask) ^ mask);
  /*
   *     x & mask == mask
   * =>  (x & mask) ^ mask == 0
   * =>  !((x & mask) ^ mask)
   */
}
```

**Operators:** 7

## `negate`

```c
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return ~x + 1;
}
```

**Operators:** 2

## `isAsciiDigit`

```c
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  // We can use the right shift operator to check if a number is within some
  // power-of-two range. All we do is to shift by some number, and check if it's
  // one.
  // We can also split the digits 0x30 to 0x39 into a 8-chunk and a 2-chunk.

  // We try to fit our numbers 0-7 (0x30-0x37) into the numbers 8-15, then >> 3
  int zero2Seven = !(((x + ~0x27 /* Writing "- 0x28" without subtraction*/) >> 3) + ~0 /* ~0 is -1 */);
  /*
   *     8 <= x - 0x30 + 8 <= 15
   * =>  (x - 0x28) >> 3 == 1
   * =>  (x - 0x28) >> 3 - 1 == 0
   * =>  !((x + ~0x27) >> 3 - 1)
   */

  // Now try to fit it into 2 and 3 and >> 1
  int eightOr9 = !(((x + ~0x35) >> 1) + ~0); // Same logic as zero2Seven
  return zero2Seven | eightOr9;
}
```

**Operators:** 13

## `conditional`

```c
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  // Same functionality as the multiplexer, so we can use the multiplexer

  // Converts x to a true/false value for masking
  int xMask = !x + ~0;

  return (y & xMask) | (z & ~xMask);
}
```

**Operators:** 7

## `isLessOrEqual`

```c
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  // We can take y - x and check if it's >= 0. To do this, we can perform an
  // *arithmetic* right shift 31 times, so we get either 0 or -1. However, this
  // doesn't work when one of them is negative and the unsigned representation
  // of x is greater than the unsigned representation of y.

  int xSign = x >> 31; // For smaller op count
  // Check if the signs are different - logic fails if they are
  int diffSigns = (xSign ^ (y >> 31));
  return (diffSigns & !~xSign) | (~diffSigns & !((y + ~x + 1) >> 31));
  /*
   *     if (diffSigns) x < 0 else y - x > 0
   * =>  conditional(diffSigns,
   *                 (x >> 31) == -1,
   *                 (y - x) >> 31 == 0)
   * =>  conditional(diffSigns,
   *                 ~(x >> 31) == 0,
   *                 !((y - x) >> 31))
   * =>  conditional(diffSigns,
   *                 !~(x >> 31),
   *                 !((y - x) >> 31))
   */
}
```

**Operators:** 14

## `logicalNeg`

```c
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
  // We can think of the logical negation operator as checking if x is zero.
  // First we check if x is not negative, then we check if x is not positive (by
  // checking if -x is not negative)

  return ((x >> 31) + 1) & (((~x + 1) >> 31) + 1);
  /*
   *     x >= 0 && x <= 0
   * =>  MSB(x) == 1 && MSB(-x) == 1
   * =>  x >> 31 == -1 && -x >> 31 == -1
   * =>  ((x >> 31) + 1) & (((~x + 1) >> 31) + 1)
   */
}
```

**Operators:** 7

## `howManyBits`

```c
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
  // The dumb way to do this would be to find every right-shift and count the
  // nonzero ones. However, that takes 94 operators, which is kind of a lot. So
  // instead, we can do binary search. Binary search with some vey hairy logic
  // though. First we pick the middle bit. Then we check if it's zero. If it is,
  // we move down by a half, moving up by a half otherwise. And we repeat the
  // process again and again and again and again (exactly five times). Five
  // times is the maximum amount of times we need, since log2(32)=5.

  int lo;
  int hi;
  int mid;
  int midBit;

  int neg = x >> 31;
  x = neg ^ x; // Same as (~neg & x) | (neg & ~x)

  mid = 15; // Iteration 1
  midBit = !(x >> mid) + ~0;

  lo = midBit & (mid + 1); // If midBit happens to be zero, lo would be set to zero
  hi = (midBit & 31) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 2
  midBit = !(x >> mid) + ~0;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 3
  midBit = !(x >> mid) + ~0;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 4
  midBit = !(x >> mid) + ~0;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 5
  midBit = !(x >> mid) + ~0;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  return lo + 1; // Since bits start at 0
}
```

**Operators:** 73

## `floatScale2`

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
  unsigned fracMask = 0x7fffff; // binary: 0 00000000 11111111111111111111111 - selects the frac portion of the float
  unsigned exp = uf & expMask;
  if (uf << 1 == 0) // Positive or negative zero
    return uf;
  if (exp == expMask) // "Special" value - infinities and NaN
    return uf;     // No need to do anything; double a special value is still itself
  if (exp == 0) {  // Denormalized values
    unsigned frac = uf & fracMask; // the fraction portion of the floating-point number
    frac <<= 1;
    // if the value overflows the exponent should in theory be one anyways
    // frac &= fracMask;
    uf &= ~fracMask;
    return uf | frac;
  }

  // Normalized Values
  exp += 0x00800000; // Add one to the exponent
  uf &= ~expMask; // clear the exponent
  return uf | exp; // add the exponent
}
```

**Operators:** 14

## `floatFloat2Int`

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
  return 2;
}
`

**Operators:** 

## `floatPower2`

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
  return 2;
}
```

**Operators:** 

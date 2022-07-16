/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
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
// 2
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
  // Build mask (0xaaaaaaaa) first - rather than shifting 4 times, we only need
  // 2 shifts and 2 ORs
  int mask = (0xaa << 8) | 0xaa;
  // We can only express byte values, but no need to write the definition of mask again
  mask = (mask << 16) | mask;
  return !((x & mask) ^ mask);
}
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
// 3
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
  int zero2Seven = !(((x + ~0x27 /* Writing "- 0x28" without subtraction*/) >> 3) - 1 /* ~0 is -1 */);

  // Now try to fit it into 2 and 3 and >> 1
  int eightOr9 = !(((x + ~0x35) >> 1) - 1); // Same logic as zero2Seven
  return zero2Seven | eightOr9;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  // Same functionality as the multiplexer, so we can use the multiplexer logic

  // Converts x to a true/false value for masking
  int xMask = !x - 1;

  return (y & xMask) | (z & ~xMask);
}
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
}
// 4
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
}
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
  midBit = !(x >> mid) - 1;

  lo = midBit & (mid + 1); // If midBit happens to be zero, lo would be set to zero
  hi = (midBit & 31) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 2
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 3
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 4
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 5
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  return lo + 1; // Since bits start at 0
}
// float
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

---
tags: 
aliases: 
date created: 2022/06/22 10:05:55 pm
date modified: 2022/07/15 9:49:54 pm
---

# isAsciiDigit

#lab #datalab #logic

Since we're not allowed the ever-so-helpful comparators, we'll have to improvise. The key to this problem is `!`, as usual, but also the right shift operator `>>`.

What the right shift allows us to do is to throw away bits. Thus, we can use an equality to check if a number is within a range. Note that the range must be the size of a power of 2.

Our range is 10 numbers in size, and since 10 is not a power of 2, we have to split it into 8 and 2, which *are* powers of 2.

To cut down on operations, we make the following reductions:

```
    8 <= x - 0x30 + 8 <= 15
=>  (x - 0x28) >> 3 == 1
=>  (x - 0x28) >> 3 - 1 == 0
=>  !((x + ~0x27) >> 3 - 1)

```

The same logic applies to the 8-9 range.

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
  int zero2Seven = !(((x + ~0x27 /* Writing "- 0x28" without subtraction*/) >> 3) - 1 /* ~0 is -1 */);

  // Now try to fit it into 2 and 3 and >> 1
  int eightOr9 = !(((x + ~0x35) >> 1) - 1); // Same logic as zero2Seven
  return zero2Seven | eightOr9;
}
```

**Operations:** 13

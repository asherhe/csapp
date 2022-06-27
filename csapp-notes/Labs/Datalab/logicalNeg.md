---
date created: 2022/06/25 8:20:40 pm
date modified: 2022/06/25 8:36:19 pm
---

# logicalNeg

#lab #datalab #chapter-2 #logic

As exploited in [[isTmax|pre]][[allOddBits|vi]][[isAsciiDigit|ous]] [[isLessOrEqual|labs]], the [[Boolean Algebra#Logical operations|logical]] [[Boolean Algebra#Not|not]] operator has a side function as a zero check. Checking if something is zero without `!` is possible, but a bit tricky.

Zero is the only number that is nonpositive and nonnegative at the same time, so we can get two overlapping ranges and [[Boolean Algebra#And|and]] them.

Checking the sign of a [[Integers and Two's Compliment#Signed Integers|two's compliment]] integer is simply a matter of looking at its most significant bit (MSB).

So basically the whole thing is just `MSB(x) == 1 && MSB(-x) == 1`. `MSB` is found with a (arithmetic) bit shift.

Since we are returning a `0x00`/`0x01` value we'll have to change our results accordingly.

If we add 1 to the result of the shift we go from `0x00`/`0xff` to `0x01/0x00`. This seems backwards, but since the logical negation means "is this **not** equal to zero," this is exactly what we want.

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
}
```

**Operations: ** #todo

---
tags: 
aliases: 
date created: 2022/06/25 7:46:06 pm
date modified: 2022/07/15 9:20:07 pm
---

# isLessOrEqual

#lab #datalab #chapter-2 #logic #2s-compliment

Checking a number for negativity is somewhat easier than comparing two numbers. All we do is to shift to the most significant bit and see if it's `1`.

Thus the problem of comparing two values is now the problem of determining if a value (`y - x`) is nonnegative.

However, when, for example, `x = -1` and `y = 7`, overflow breaks this logic, as shown below:

```
  0111
- 1111
  1000
```

When the difference becomes `tMin` (i.e. $x=tMin+n$ and $y=n$), overflow causes this difference to behave strangely, so we must also introduce a check for this.

Checking if this is the right form is a bit difficult (and even I myself am not sure if this is the only corner case), but it seems that things only break down when the signs of `x` and `y` are different, so we can easily implement a check for that.

Next, we make some logical simplifications:

```
    if (diffSigns) x < 0 else y - x > 0
=>  conditional(diffSigns,
                (x >> 31) == -1,
                (y - x) >> 31 == 0)
=>  conditional(diffSigns,
                ~(x >> 31) == 0,
                !((y - x) >> 31))
=>  conditional(diffSigns,
                !~(x >> 31),
                !((y - x) >> 31))
```

This gives us our final program:

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
}
```

**Operations:** 14
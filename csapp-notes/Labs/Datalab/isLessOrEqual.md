---
date created: 2022/06/25 7:46:06 pm
date modified: 2022/06/25 8:36:48 pm
---

# isLessOrEqual

#lab #datalab #chapter-2 #logic #todo

Though comparing one number with another is difficult, comparing a number with zero is quite easy.

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

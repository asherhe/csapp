---
date created: 2022/05/02 7:37:04 pm
date modified: 2022/06/25 8:37:01 pm
---

# tMin

#lab #datalab #2s-compliment

The minimum 32-bit [[Integers and Two's Compliment|two's compliment integer]] is equal to `0x80000000`, or simply a `1` in the MSB.

Since we are prohibited from directly entering `0x80000000`, a simple bit shift does the trick.

```c
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  // tmin is just a 1 followed by zeros
  return 1 << 31;
}
```
**Operations:** 1

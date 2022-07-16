---
date created: 2022/06/22 10:00:30 pm
date modified: 2022/06/29 9:25:03 pm
---

# allOddBits

#lab #datalab

Basically we construct a mask, mask it with `x`, and then check if the mask is all filled.

Since we're not allowed to use `==` we have to improvise with the following reductions:

```
    x & mask == mask
=>  (x & mask) ^ mask == 0
=>  !((x & mask) ^ mask)
```

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
  // Build mask (0xaaaaaaaa) first - rather than shifting 4 times, we only need
  // 2 shifts and 2 ORs
  int mask = (0xaa << 8) | 0xaa;
  // We can only express byte values, but no need to write the definition of mask again
  mask = (mask << 16) | mask;
  return !((x & mask) ^ mask);
}
```

**Operations:** #todo

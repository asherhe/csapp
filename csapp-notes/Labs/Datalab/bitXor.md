---
date created: 2022/05/02 7:33:35 pm
date modified: 2022/06/29 9:23:04 pm
---

# bitXor

#lab #datalab #logic

`x^y` is logically equivalent to `(~x & y) | (x & ~y)`. [[Boolean Algebra#Or|Bitwise OR]] isn't allowed here so we apply De Morgan's laws to convert it into [[Boolean Algebra#And|bitwise ANDs]] and [[Boolean Algebra#Not|NOTs]].

```c
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  // x^y = (~x & y) | (x & ~y)
  // The | operator is forbidden so we substitute it for &s and ~s using De Morgan's Laws
  return ~(~(~x & y) & ~(x & ~y));
}
```
**Operations:** #todo

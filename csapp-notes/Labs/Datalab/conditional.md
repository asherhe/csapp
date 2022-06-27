---
date created: 2022/06/25 7:37:31 pm
date modified: 2022/06/25 8:36:36 pm
---

# conditional

#lab #datalab #chapter-2 #logic

To understand this code, let's analyze the *multiplexer*, a logical circuit. To simplify things, assume a 1-bit multiplexer

It has two inputs, `a` and `b`, as well as another input `sel` that determines which of `a` or `b` to output.

The logic within that circuit is `(x & ~sel) | (y & sel)`.

---

Extrapolating to our `conditional`, `x` plays the role of `sel`, while `z` and `y` play the role of `a` and `b` respectively (notice that it's backwards).

Since the one-line conditional `?` sees `x` as a true/false value, we first convert it into `0x00000000` or `0xffffffff` (false and true respectfully) performing a [[Boolean Algebra#Logical operations|logical]] [[Boolean Algebra#Not|not]], then subtracting 1.

Then we perform the multiplexer logic.

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
  // Same functionality as the multiplexer, so we can use the multiplexer logic

  // Converts x to a true/false value for masking
  int xMask = !x - 1;

  return (y & xMask) | (z & ~xMask);
}
```

**Operations:** #todo

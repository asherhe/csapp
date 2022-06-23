# isTmax
#lab #datalab #2s-compliment 

tMax, the largest 32-bit [[Integers and Two's Compliment|two's compliment number]], is `0x7fffffff`. It is one of the only two numbers along with `-1` that has the property such that adding 1 has the same effect as a bitwise negation (note: this does not work for logical or arithmetic negation). Therefore all we do is to test if `x + 1 == ~x`.

Unfortunately, we are not yet permitted to use `==`. This is not a big problem as we can make that from scratch using the logical negation operator `!`. Logical operators, unlike bitwise operators, see values as either a `true` or a `false`. More precisely, either `0` or not `0`.

```c
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  // tMax and -1 are the only two's complement integers such that adding one has the same effect as a bitwise negation operation
  // Test if the property holds and ensure that x != -1
  int add1 = x + 1;
  return !(~x ^ add1) & ~!add1;
}
```
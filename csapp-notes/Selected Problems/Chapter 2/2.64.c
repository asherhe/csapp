#include <stdio.h>

/* Return 1 when any odd bit of x equals 1, 0 otherwise. Assume w=32 */
int any_odd_one(unsigned x)
{
  x = x & 0xaaaaaaaa; // ignore even bits

  return !!x; // 0 if zero, 1 otherwise
}

int main()
{
  int x;
  printf("x = 0x");
  scanf("%x", &x);

  printf("0x%08x has odd one: %d\n", x, any_odd_one(x));
}
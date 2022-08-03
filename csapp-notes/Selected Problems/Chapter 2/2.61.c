#include <stdio.h>

/*
 * A NOTE ON LOGICAL NOT (!)
 * -------------------------
 * The truth table for logical not (!) is as follows:
 *
 *     x | !x
 * ------|----
 *     0 | 1
 *  != 0 | 0
 *
 * This effectively makes !x the same as x == 0.
 * Because we are prohibited from using equality (==) this is useful!
 */

int any1(int x)
{
  // Not zero
  return !!x;
}
int any0(int x)
{
  // Not -1
  return !!(x + 1);
}
int lastByte1(int x)
{
  // Only keep the last byte
  x = x & 0xff;
  return !!x; // Not 0
}
int lastByte0(int x)
{
  x = x & 0xff;
  return !!(x - 0xff); // Not 0xff
}

// Testing function: Get input from user and print data
int main()
{
  int x;
  printf("x = ");
  scanf("%x", &x);
  printf("%d", x);

  printf("Contains 1: %d\nContains 0: %d\nLast byte contains 1: %d\nLast byte contains 0: %d\n",
         any1(x),
         any0(x),
         lastByte1(x),
         lastByte0(x));
  return 0;
}
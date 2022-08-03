#include <stdio.h>

int int_shifts_are_arithmetic()
{
  // Right shift -1 (all 1's) and see if it is still all 1's (and not a zero and then all 1's)
  return !((-1 >> 1) + 1);
}

int main()
{
  if (int_shifts_are_arithmetic() == 1)
    printf(">> is arithmetic\n");
  else
    printf(">> is logical\n");
  return 0;
}
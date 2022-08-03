#include <stdio.h>
#include <limits.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{
  /*
   * There are four cases to consider:
   *
   * CASE 1: x, y > 0
   * Since we are checking if x + y > TMax, we can exploit the modular nature of
   * signed numbers and check instead if x + y < 0.
   */
  unsigned w = sizeof(int) << 3; // Word count of int data type

  int sgnX = x >> (w - 1);
  int sgnY = y >> (w - 1);

  int sum = x + y;

  if (sgnX + sgnY == 0) // check if both are nonnegative
    return (sum < 0) ? INT_MAX : sum;
  if (sgnX + sgnY == -1) // both negative
    return (sum < 0) ? sum : INT_MIN;
  // TODO: Different signs
}

int main()
{
  int x, y, sum;
  scanf("%d%d", &x, &y);
  sum = saturating_add(x, y);
  printf("sum = %d", sum);
  switch (sum)
  {
  case INT_MAX:
    printf(" (TMax)\n");
    break;
  case INT_MIN:
    printf(" (TMin)\n");
    break;
  default:
    prinf("\n");
    break;
  }
}
#include <stdio.h>

// logical right shift from arithmetic right shift
unsigned srl(unsigned x, int k)
{
  /* Perform shift arithmetically */
  unsigned xsra = (int)x >> k;

  if (k == 0)
    return xsra; // 1 << w is undefined

  int w = 8 * sizeof(int);

  int mask = (1 << (w - k)) - 1;
  return xsra & mask; // Clear the 1s
}

// arithmetic right shift from logical right shift
int sra(int x, int k)
{
  /* Perform shift logically */
  int xsrl = (unsigned)x >> k;

  if (k == 0)
    return xsrl; // 1 << w is undefined

  int w = 8 * sizeof(int);

  int mask = (1 << (w - k)) - 1;
  return xsrl | ~mask; // Add in leading 1s
}

int main()
{
  int x, k;

  printf("x, k:  ");
  scanf("%d%d", &x, &k);
  printf("srl(0x%08x, %d) == 0x%08x (compare 0x%08x)\n", x, k, srl(x, k), (unsigned)x >> k);
  printf("sra(0x%08x, %d) == 0x%08x (compare 0x%08x)\n", x, k, sra(x, k), x >> k);
}
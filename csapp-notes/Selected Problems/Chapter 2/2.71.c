#include <stdio.h>

/* Declaration of data type where 4 bytes are packed into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum)
{
  int byte = word >> (bytenum << 3);
  return (byte << 24) >> 24; // Pull the 1s out of the magician's hat
}

int main()
{
  int b0, b1, b2, b3;
  printf("byte #0 (between -128 and 127) = ");
  scanf("%x", &b0);
  printf("byte #1 (between -128 and 127) = ");
  scanf("%x", &b1);
  printf("byte #2 (between -128 and 127) = ");
  scanf("%x", &b2);
  printf("byte #3 (between -128 and 127) = ");
  scanf("%x", &b3);

  packed_t word = (b0 & 0xff) | (b1 << 8 & 0xff00) | (b2 << 16 & 0xff0000) | (b3 << 24 & 0xff000000);
  printf("word = 0x%08x\n", word);

  int bytenum;
  while (1)
  {
    printf("get byte #");
    scanf("%d", &bytenum);
    printf("byte #%d = 0x%02x\n", bytenum, xbyte(word, bytenum));
  }
}
---
date created: 2022/05/02 9:38:40 pm
date modified: 2022/06/26 9:05:40 pm
---

# Practice Problem 2.6

#practice-problems #chapter-2 #data-types #floating-point

> Using `show_int` and `show_float`, we determine that the integer 3510593 has hexadecimal representation `0x00359141` while the floating point number 3510593.0 has hexadecimal representation `0x4A564504`.
>
> A. Write the binary representation of these two hexadecimal values.
>
> B. Shift these two strings relative to one another to maximize the number of matching bits. How many bits mach?
>
> C. What parts of the strings do not match?

The binary representations of the numbers are `00000000 00110101 10010001 00100001` and `00101010 01010110 00100101 00000010`, respectively.

The parts of the string that match when shifted are indicated below:

```
00000000001101011001000100100001
           **************
  00101010010101100010010100000010
```

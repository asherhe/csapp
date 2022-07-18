---
tags: practice-problems chapter-2 floating-point 
aliases: 
date created: 2022/07/11 9:24:23 pm
date modified: 2022/07/15 9:20:06 pm
---

# Practice Problem 2.47

> Consider a 5-bit floating-point representation based on the IEEE floating-point format, with one sign bit, two exponent bits ($k=2$), and two fraction bits ($n=2$). The exponent bias is $2^{2-1}-1=1$.
> The table that follows enumerates the entire nonnegative range for this 5-bit floating-point representation. Fill in the blank table and entries using the following instructions:
>
> | $e$ | $E$ | $2^E$ | $f$ | $M$ | $2^E\times M$ | $V$ | Decimal |
> | --- | --- | --- | --- | --- | --- | --- | --- |
> | The value represented by considering the exponent field to be an unsigned integer | The value of the exponent after biasing | The numeric weight of the exponent | The value of the fraction | The value of the significand | The (unreduced) fractional value of the number | The reduced fractional value of the number | The decimal representation of the number |
>
> Express the values of $2^E$, $f$, $M$, $2^E\times M$, and $V$ either as integers (when possible) or as fractions of the form $\frac xy$, where $y$ is a power of 2. You need not fill in entries marked $\textemdash$

| Bits | $e$ | $E$ | $2^E$ | $f$ | $M$ | $2^E\times M$ | $V$ | Decimal |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `0 00 00` | 0 | 0 | 1 | $\frac04$ | $\frac04$ | $\frac04$ | $0$ | 0 |
| `0 00 01` | 0 | 0 | 1 | $\frac14$ | $\frac14$ | $\frac14$ | $\frac14$ | 0.25 |
| `0 00 10` | 0 | 0 | 1 | $\frac24$ | $\frac24$ | $\frac24$ | $\frac12$ | 0.5 |
| `0 00 11` | 0 | 0 | 1 | $\frac34$ | $\frac34$ | $\frac34$ | $\frac34$ | 0.75 |
| `0 01 00` | 1 | 0 | 1 | $\frac04$ | $\frac44$ | $\frac44$ | $1$ | 1 |
| `0 01 01` | 1 | 0 | 1 | $\frac14$ | $\frac54$ | $\frac54$ | $\frac54$ | 1.25 |
| `0 01 10` | 1 | 0 | 1 | $\frac24$ | $\frac64$ | $\frac64$ | $\frac32$ | 1.5 |
| `0 01 11` | 1 | 0 | 1 | $\frac34$ | $\frac74$ | $\frac74$ | $\frac74$ | 1.75 |
| `0 10 00` | 2 | 1 | 2 | $\frac04$ | $\frac44$ | $\frac84$ | $2$ | 2 |
| `0 10 01` | 2 | 1 | 2 | $\frac14$ | $\frac54$ | $\frac{10}4$ | $\frac52$ | 2.5 |
| `0 10 10` | 2 | 1 | 2 | $\frac24$ | $\frac64$ | $\frac{12}4$ | $3$ | 3 |
| `0 10 11` | 2 | 1 | 2 | $\frac34$ | $\frac74$ | $\frac{14}4$ | $\frac72$ | 3.5 |
| `0 11 00` | — | — | — | — | — | — | $+\infty$ | — |
| `0 11 01` | — | — | — | — | — | — | $NaN$ | — |
| `0 11 10` | — | — | — | — | — | — | $NaN$ | — |
| `0 11 11` | — | — | — | — | — | — | $NaN$ | — |

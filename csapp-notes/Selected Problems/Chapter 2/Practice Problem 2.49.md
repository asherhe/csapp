---
tags: practice-problems chapter-2 floating-point 
aliases: 
date created: 2022/07/11 9:48:36 pm
date modified: 2022/07/15 9:20:06 pm
---

# Practice Problem 2.49

> A. For a floating-point format with an $n$-bit fraction, give a formula for the smallest integer that cannot be represented exactly (because it would require an $(n+1)$-bit fraction to be exact). Assume the exponent field size $k$ is large enough that the range of representable exponents does not provide a limitation for this problem.
> B. What is the numeric value for single-precision format ($n=23$)

When $E>n$, the least significant bit of `frac` "rises" from the least significant bit of its integer form. However, $2^{n+1}$ is still exact because the LSB of the `frac` portion is still 0, which doesn't affect anything. Therefore, the smallest largest number is $2^{n+1}\times(1.\underbrace{00\dots01}_n)=2^{n+1}\times(1+2^{-n})=2^{n=1}+2$.

If $n=23$, this value is equal to $2^{24}+2=16,\!777,\!217$.

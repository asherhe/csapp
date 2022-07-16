---
tags: 
aliases: ["#floating-point", "float", "floats", "floating point number", "floating point numbers"]
date created: 2022/05/21 9:53:05 pm
date modified: 2022/07/15 9:20:07 pm
---

# Floating-Point

#chapter-2 #floating-point

Floating point is a system of encoding real numbers[^1] in binary format, since not all numbers are [[Integers and Two's Compliment|integers]]. It is mandated by the IEEE ("eye-triple-ee") floating-point standard, carefully designed so that everything is convenient.

Before delving into floating point, let's explore fractional binary numbers.

## Fractional Binary Numbers and Scientific Notation

A number expressed in decimal can be expanded as:
$$
1.4142=1+4\times\frac1{10}+1\times\frac1{100}+4\times\frac1{100}+2\times\frac1{1000}
$$

Similarly, binary "decimals" can be expressed as:
$$
11.001001_2=1\times2^1+1\times2^0+1\times2^{-3}+1\times2^{-6}
$$

We also know[^2] scientific notation, which is not only a great way to write large numbers, but also a good way for writing numbers in a more modular form. For example, scientific notation in base 10 looks like
$$
3,\!628,\!000=3.628\times10^6
$$

Similarly, in binary we have
$$
11001100_2=1.10011\times2^7
$$

---

Combining fractional binary and scientific notation gives us the essence of floating-point numbers. A floating-point number consists of three components:

- The **sign** $s$: indicates the sign of the floating-point number
- The **exponent** $E$: a number representing the exponent (or where to place the "binary point")
- The **signifcand** $M$: the fractional portion of the binary number

In memory, the three components are listed in that exact order. The sign is one bit occupying the MSB, while the exponent and significand, occupying $k$ and $n$ bits, respectively, occupy the rest of the floating point number[^3] in a slightly modified form, as we will see.

Floating-point numbers also have a few different cases for special numbers

- **Normalized Values**: The "normal", run-of-the-mill scientific notation fractional binary numbers
  For normalized values, the `exp` portion is neither all zero or all one (which results in the corner cases). To compensate for negative exponent, the numeric form of `exp` is decremented by a *bias* first to turn it into the proper exponent $E$, where the bias is $2^{k-1}-1$ (a bit reminicscient to [[Integers and Two's Compliment|two's compliment]]), and so $E=\texttt{exp}-2^{k-1}+1$. For example, an `exp` of `0x85` represents an exponent of 6.
  Since the significant will always have a leading 1 no matter what happens, we earn an extra bit by declaring that there is an *implied 1* at the start. In other words, $E=1+\texttt{frac}$.

- **Denormalized Values**: Denormalized values (or "denorms") provide (two) zeros and a smooth transition into zero.
  Because powers of two can never become zero, at some point we say "stop, this is zero". We want to do this as far back as possible, so we let this happen at `exp = 0x00`. However, $E$ still remains at what would happen at `exp = 0x01`, namely, $E=-2^{k-1}+2$. Instead of transitioning to an even smaller step size, we gently flow into zero. This means we also remove the implied 1.
  Curiously, there are two values of zero, at $+0.0=\texttt{0x00\,00\,00\,00}$ and $-0.0=\texttt{0x80\,00\,00\,00}$.
 ^9943a7
- **Special Values**: For representing really large or even nonexistent numbers.
  When the `exp` field is all 1's (`0xff`), we enter the realm of "special values": $\pm\infty$ and $NaN$, literally "not a number". When the fraction field is all zeros, we have an infinity, usually the result of the floating-point counterpart of overflow. $NaN$ is reserved for those absurd computations like $\frac00$, $0^\infty$, $\sqrt{-1}$, $\infty-\infty$, and so on. They are also really handy as "uninitialized values", filler data values before any real data has been assigned. ^d05a98

Notice that increasing integer values correlate to increasing floating-point values. This is intentional design to that floating-point numbers can be compared and sorted as if they were normal integers.[^4]

Many familiar numbers (take 0.1 for example) give off repeating decimals ($0.1=0.0\overline{0011}_2$) that cannot be expressed precisely in floating-point. As a result, we're forced to round, **but in which direction?**

IEEE defines four *rounding modes*:

- **Round-to-even** (or **round-to-nearest** which is honestly a better name): Find the closest number to this number. It's called "round-to-even" because if the value is exactly halfway between our boundaries, we round to the even[^5] number (to avoid statistical bias).
- **Round-toward-zero**: Round to the one that is closer to zero (down for positives, up for negatives)
- **Round-down:** Round to the lesser number
- **Round-up**: Round to the greater number

By default floating points use round-to-even.

[^1]: Albiet with some loss of precision
[^2]: If you haven't, you should
[^3]: Floating-point values have two sizes corresponding to two degrees of precision: single-precision (denoted by `float`) and double-precision (`double`). `float` takes up 32 bits, with $k=8$ and $n=23$. `double` takes up 64 bits, with $k=11$ and $n=52$. `float` is [generally not preferable](https://stackoverflow.com/a/2386882/11389823) and thus `double` is more widely-used
[^4]: But then there are negative numbers
[^5]: For our purposes even numbers have a `0` as their least significant bit

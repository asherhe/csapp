---
Aliases: [ "#boolean-algebra", "#logic" ]
date created: 2022/05/21 9:49:45 pm
date modified: 2022/06/25 7:44:01 pm
---

# Boolean Algebra

#boolean-algebra #logic

> [!quote]
> Since binary values are at the core of how computers encode, store, and manipulate information, a rich body of mathematical knowledge has evolved around the study of the values 0 and 1. This started with the work of George Boole (1815-1864) around 1850 and thus is known as *Boolean algebra*.

First of all, just to clarify, this algebra is not your run-of-the-mill $3x+4=0$ algebra. Instead, this algebra refers to [*abstract algebra*](https://en.wikipedia.org/wiki/Abstract_algebra), which is essentially the mathematical study of sets and operations on those sets. In our case, that set is $\{0,1\}$, and those operations are whatever mysterious things computers do to flip bits.

Actually what Boole tried to do was to generalize how thinking works by mathematicizing (whatever the present form of the verb *to math* is) "yes" and "no" and using a bunch of funny-looking operations on them. And then it just so happens that computers store things in binary through "on" and "off" electrical states.

## The Boolean Operations in maybe a bit too much detail

### Not

The NOT operation negates whatever predicate it has been applied to. $\neg P$ is true if $P$ is not true. For 0 and 1 values, `~p == 1` if `p == 0`.

### And

$P\land Q$ : true if both $P$ and $Q$ are true.

Binary analogue: `&`, literally the same behaviour

### Or

$P\lor Q$: true if at least one of $P$ or $Q$ is true

Binary analogue: `|`

### Exclusive Or (XOR)

$P\oplus Q$: true only if exactly one of $P$ or $Q$ is true (not both)

Use `^` for 0 and 1s (don't confuse this with exponentiation)

---

In addition to plain 0 and 1 values, boolean operations can also be used multiple at a time. These chains of multiple bits are known as *bit vectors*.

## Truth Tables

Truth tables are a great way to visualize a boolean operation's inputs and outputs. It's analogous to a binary addition chart, except it's not for addition but instead conjunction,[^1] disjunction,[^2] negation,[^3] and what have you. They look like this (XOR as an example)

$$
\begin{array}{c|cc}
\oplus & 0 & 1 \\\hline
0 & 0 & 1 \\
1 & 1 & 0
\end{array}
$$

## Boolean operations in C

In C, boolean operations are like any other operation such as addition, multiplication, whatever. We can also use hexadecimal or binary or whatever other format as a number.

### Logical operations

In C there are also logical operations which treat numbers as either true or false. True or false are represented as 1 and 0 (literally `0x01` and `0x00`) and non-zero numbers all count as true.

[^1]: and
[^2]: or
[^3]: not

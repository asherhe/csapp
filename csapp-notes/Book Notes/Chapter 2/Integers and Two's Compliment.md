---
Aliases: [ "#2s-compliment" ]
---

# Integers and Two's Compliment
#chapter-2 #2s-compliment #data-types 

- A system for representing negative numbers as well as positive numbers
- Defined so that traditional addition and subtraction still make mathematical sense
  - There is no need to introduce a new framework for accounting for signed numbers

## First of all, some terminology

| Symbol   | Type      | Meaning                         |
| -------- | --------- | ------------------------------- |
| $B2T_w$  | Function  | Binary to two's compliment      |
| $B2U_w$  | Function  | Binary to unsigned              |
| $U2B_w$  | Function  | Unsigned to binary              |
| $U2T_w$  | Function  | Unsigned to two's compliment    |
| $T2B_w$  | Function  | Two's compliment to binary      |
| $T2U_w$  | Function  | Two's compliment to unsigned    |
| $TMin_w$ | Constant  | Minimum two's-compliment value  |
| $TMax_w$ | Constant  | Maximum two's compliment value  |
| $UMax_w$ | Constant  | Maximum unsigned value          |
| $+^t_w$  | Operation | Two's-compliment addition       |
| $+^u_w$  | Operation | Unsigned addition               |
| $*^t_w$  | Operation | Two's-compliment multiplication |
| $*^u_w$  | Operation | Unsigned multiplication         |
| $-^t_w$  | Operation | Two's-compliment negation       |
| $-^u_w$  | Operation | Unsigned negation               |

## Unsigned Integers

Your run-of the mill binary numbers

A vector $\overrightarrow x=\left[x_{w-1},x_{w-2},\cdots,x_0\right]$ would represent::

$$
B2U_w\left(\overrightarrow x\right)\doteq\sum^{w-1}_{i=0}x_i2^i
$$

($\doteq$ meaning that the left-hand side is defined to be equal to the right-hand side - kind of like a definition)

So the maximum number $UMax_w$ corresponds to the bit vector $[11\cdots1]$ while the minimum is (a bit obviously) $[00\cdots0]$.

Anyways, we can express $UMax_w$ as $UMax_w\doteq\sum^{w-1}_{i=0}2^i=2^w-1$

$B2U_w$ is also a *bijection*, meaning that a vector can be converted into an unsigned integer and vice versa. The opposite function is called $U2B_w$.

## Signed Integers
#2s-compliment 

In order to represent signed integers, the most significant bit in two's compliment is negated, which offsets the whole thing. Thus we have:

$$
B2T_w(\overrightarrow x)\doteq-x_{w-1}2^{w-1}+\sum^{w-2}_{i=0}x_i2^i
$$

**#todo Add that diagram from the lecture with the number line and arrows showing how this works visually - see Figure 2.13 (p. 65) in the book**

So the minimum value is $[100\cdots0]$ (set the negative bit on), which is equal to $TMin_w\doteq-2^{w-1}$, and the maximum value is $[011\cdots1]$, which is equal to $TMax_w\doteq\sum^{w-2}_{i=0}2^i=2^{w-1}-1$.

## Signed ↔ Unsigned conversions



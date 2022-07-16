---
tags: lab datalab chapter-2 
aliases: 
Aliases: [ "#datalab" ]
date created: 2022/06/22 10:00:30 pm
date modified: 2022/07/15 9:29:47 pm
---

# Datalab

#lab #datalab #chapter-2

Datalab is about using elementary operations to maniuplate data at its lowest level. Low-level programming is not much about elegance, but rather cunning. So there are a few things to note here:

- Simplify all expressions to reduce the operation count, even if the result bears no resemblance to the original expression
	- Perhaps add comments to clarify
- If it helps, encapsulate commonly-used calculations in variables
	- The grader checks for operation count, not memory usage
- For algorithmically more complicated problems, write a program with `while` and `if` first and gradually refine the program until there are no more
	- `if` can be implemented by changing the variables involved with a [[conditional]]
	- Looping structures such as `while` and `for` will consist of the same code repeated as many times as necessary
		- For `while` loop for the worst-case scenario
- Use [[Bit Shifting]] to extract some component of a number
- The behaviour of `!` ([[Boolean Algebra#Logical operations|logical not]]) can be exploited as "equals"
---

italics = difficult problem.

**Section 1** - The simple stuff
1. [[bitXor]] - making [[Boolean Algebra#Exclusive Or XOR|XOR]] with [[Boolean Algebra#And|AND]] and [[Boolean Algebra#Not|NOT]]
2. [[tMin]] - return minimum [[Integers and Two's Compliment#Signed Integers|two's compliment]] integer

**Section 2** - Still simple
1. [[isTmax]] - verify that a number is the largest [[Integers and Two's Compliment#Signed Integers|two's compliment]] number
2. [[allOddBits]] - verify that an integer's odd bits are all 1
3. [[negate]] - arithmetic negation

**Section 3** - Suddenly really hard for some reason
1. [[isAsciiDigit]] - check if a ASCII character is within the range representing numeric digits (`'0'` to `'9'`)
2. [[conditional]] - simple `if`
3. *[[isLessOrEqual]] - `>=` operation*
4. [[logicalNeg]] - implement the ever-so-helpful `!` ([[Boolean Algebra#Bitwise vs Logical|logical]] [[Boolean Algebra#Not|negation]]) operator
5. *[[howManyBits]] - calculates the minimum amount of two's compliment bits needed to represent an integer*

**Floating-point stuff** - Relatively easy if you understand [[Floating Point]]
1. [[floatScale2]] - double a `float`
2. [[floatFloat2Int]] - turn floating-point value to an integer (truncate the decimal points)
3. [[floatPower2]] - integer powers of 2 in floating point (use `exp`)

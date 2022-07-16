---
tags: 
aliases: 
date created: 2022/05/02 9:15:16 pm
date modified: 2022/07/15 9:20:07 pm
---

# Size of Data Types in C

#chapter-2 #data-types

## 32vs 64-bit

- Every computer has a *word size* that indicates the size of pointer data
- Addresses are encoded through pointers
  - The memory limit for a computer is restricted by the word size
- Most computers in use today are either 32-bit or 64-bit
  - 64-bit is becoming more common
  - 32-bit limit: 4 GB
  - 64-bit limit: 16 **exabytes** - 4,294,967,296 times the 32-bit limit(!)
- Programs written for 32-bit can be run on 64-bit machine
  - However, 64-bit programs cannot run on 32-bit machines
  - 32-bit programs are a subset of 64-bit programs

## Signed vs. Unsigned

#2s-compliment #floating-point

- Numeric types such as `int`, `short`, `long`, etc. have signed and unsigned variants
- Unsigned data only represents positive numbers, while signed data also [[Integers and Two's Compliment|represents negative numbers]]
- With no need to represent negative numbers, unsigned data allows higher numbers to be stored
- In [[Floating Point|floating-point data types]] such as `float` and `double` there is no distinction between signed and unsigned since sign is part of their definition

| Signed | Unsigned | Size on 32-bit machine | Size on 64-bit machine |
| --------------- | ---------------- | ---------------------- | ---------------------- |
| `(signed) char` | `unsigned char` | 1 | 1 |
| `short` | `unsigned short` | 2 | 2 |
| `int` | `unsigned` | 4 | 4 |
| `long` | `unsigned long` | 4 | 8 |
| `int32_t` | `uint32_t` | 4 | 4 |
| `int64_t` | `uint64_t` | 8 | 8 |
| `char *` | | 4 | 8 |
| `float` | | 4 | 4 |
| `double` | | 8 | 8 |

**[[Integers and Two's Compliment|Range of integral data types]] (64-bit)**

| Data type | Minimum | Maximum |
| ----------------------------------- | -------------------------- | -------------------------- |
| `[signed] char` (signed by default) | -128 | 127 |
| `unsigned char` | 0 | 255 |
| `short` | -32,768 | 32,767 |
| `unsigned short` | 0 | 65,535 |
| `int` | -2,147,483,648 | 2,147,483,647 |
| `unsigned` | 0 | 4,294,967,295 |
| `long` | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |
| `unsigned long` | 0 | 18,446,744,073,709,551,615 |
| `int32_t` | -2,147,483,648 | 2,147,483,647 |
| `uint32_t` | 0 | 4,294,967,295 |
| `int64_t` | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |
| `uint64_t` | 0 | 18,446,744,073,709,551,615 |

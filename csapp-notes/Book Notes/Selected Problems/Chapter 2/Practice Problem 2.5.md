---
date created: 2022/05/02 9:14:58 pm
date modified: 2022/06/26 9:05:40 pm
---

# Practice Problem 2.5

#practice-problems #chapter-2 #data-types

> Consider the following three calls to `show_bytes`:
>
> ```c
> int val = 0x87654321;
> byte_pointer valp = (byte_pointer) &val;
> show_bytes(valp, 1); /* A. */
> show_bytes(valp, 2); /* B. */
> show_bytes(valp, 3); /* C. */
> ```
>
> Indicate the values that will be printed by each call on a little-endian machine and on a big-endian machine.

## Little-Endian Machines

On little-endian machines, `val` is stored in memory as

```
21
43
65
87
```

Thus the program will print

```
21
21 43
21 43 65
```

## Big-Endian Machines

Big-endian machines store `val` as

```
87
65
43
21
```

As a result the program prints

```
87
87 65
87 65 43
```

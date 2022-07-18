---
tags: 
aliases: 
date created: 2022/05/02 9:46:59 pm
date modified: 2022/07/15 9:20:06 pm
---

# Practice Problem 2.7

#practice-problems #chapter-2 #data-types #string

> What would be printed as a result of the following call to `show_bytes`?
>
> ```c
> const char *s = "abcdef";
> show_bytes((byte_pointer) s, strlen(s));
> ```
>
> Note that letters `'a'` through `'z'` have ASCII codes `0x61` through `0x7A`

```
61 62 63 64 65 66
```

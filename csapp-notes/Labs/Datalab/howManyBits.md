---
date created: 2022/06/25 8:56:38 pm
date modified: 2022/06/25 9:14:10 pm
---

# howManyBits

#lab #datalab #chapter-2 #logic #2s-compliment

`howManyBits`, in my opinion, may be the most difficult problem in the whole of [[Datalab]]. It counts the number of bits in the *[[Integers and Two's Compliment#Signed Integers|two's compliment]]* representation of a number. The brute-force solution of checking over every bit takes up too many operations and would not work. Instead, we must use a preprocessed algorithm.

I have broken up the writing of `howManyBits` into three stages.

## Stage 1: The Algorithm

Rather than counting the number of bits by brute force, we can instead find it through *binary search*.

The stage 1 program is as follows:

```c
int howManyBits(int x)
{
  if (x < 0)
  {
    x = ~x;
  }

  int lo = 0, hi = 31, mid;
  while (lo != hi) // Not the same value
  {
    mid = (lo + hi) / 2; // Recompute
    int midBit = x >> mid;
    if (midBit == 0)
    {
      hi = mid;
    }
    else
    {
      lo = mid + 1;
    }
  }

  return lo + 1; // Since bits start at 0
}
```

Let's break this into sections.

First of all we have

```c
if (x < 0)
{
  x = ~x
}
```

Since we have to deal with negative numbers too, counting bits is a bit annoying.

However, notice that that for two's compliment, all we really need is the final `1` that makes it negative - the rest of the consecutive string of `1`s before that crucial `1` are all useless.

So instead we can simply [[Boolean Algebra#Not|not]] it and move on.

Next we have some variable declarations, and then we enter the main loop.

In binary search, we start off with the entirety of the bits to search from. We then progressively divide our range in half until we have one final number.

At last we have our final answer, but beware: the final range is not the actual answer. Since we are referring to the *index* of the bit, we have to add 1 to turn it into the *count*.

## Stage 2: Uncurling the `while` loop

Of course, we will not be able to use a `while` loop in the final version, so we'll have to pull that apart.

Since we have 32 bits to work with, the `while` loop will take at most $\log_2(32)=5$ iterations, so we repeat the loop contents five times.

Now we make a few simplifications and the only thing we have to kill off now are our `if` statements.

**Stage 2 code**

```c
int howManyBits(int x)
{
  if (x >> 31)
  {
    x = ~x;
  }

  // Iteration 1
  int lo = 0, hi = 31, mid = 15;
  int midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 2
  mid = (lo + hi) >> 1; // Shorthand for halving
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 3
  mid = (lo + hi) >> 1;
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 4
  mid = (lo + hi) >> 1;
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  // Iteration 5
  mid = (lo + hi) >> 1;
  midBit = x >> mid;
  if (midBit)
  {
    lo = mid + 1;
  }
  else
  {
    hi = mid;
  }

  return lo + 1; // Since bits start at 0
}
```

## Stage 3: Expanding the `if`s

So all we have left to dissect are the `if`s. Each `if` is responsible for updating the new values of `hi` and `lo`.

Since the `if`s affect both `hi` and `lo` we will have to change both values.

The `if` is like a [[conditional]], and thus we expand it like a conditional. The `if` block:

```c
midBit = x >> mid;
if (midBit)
{
  lo = mid + 1;
}
else
{
  hi = mid;
}
```

now turns into:

```c
midBit = !(x >> mid) - 1;
lo = (midBit & (mid + 1)) | (~midBit & lo);
hi = (midBit & hi) | (~midBit & mid);
```

---

**Final Program:**

```c
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  // The dumb way to do this would be to find every right-shift and count the
  // nonzero ones. However, that takes 94 operators, which is kind of a lot. So
  // instead, we can do binary search. Binary search with some vey hairy logic
  // though. First we pick the middle bit. Then we check if it's zero. If it is,
  // we move down by a half, moving up by a half otherwise. And we repeat the
  // process again and again and again and again (exactly five times). Five
  // times is the maximum amount of times we need, since log2(32)=5.

  int lo;
  int hi;
  int mid;
  int midBit;

  int neg = x >> 31;
  x = neg ^ x; // Same as (~neg & x) | (neg & ~x)

  mid = 15; // Iteration 1
  midBit = !(x >> mid) - 1;

  lo = midBit & (mid + 1); // If midBit happens to be zero, lo would be set to zero
  hi = (midBit & 31) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 2
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 3
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 4
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  mid = (lo + hi) >> 1; // Iteration 5
  midBit = !(x >> mid) - 1;

  lo = (midBit & (mid + 1)) | (~midBit & lo);
  hi = (midBit & hi) | (~midBit & mid);

  return lo + 1; // Since bits start at 0
}
```

**Operations:** #todo

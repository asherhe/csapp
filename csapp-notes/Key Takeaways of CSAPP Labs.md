# CSAPP Labs - Key Takeaways

CSAPP labs are a very interesting (and important) part of the CS:APP course. Here are a few key takeaways I've learned

## Datalab

Datalab is mostly about using elementary operators to perform feats of magic.

- `!` (logical NOT) checks if a value is 0 - false if truthy (not zero) and true if falsy (zero)
- `x >> 31` can be used to find the most significant bit of `x` (assuming 32-bit integers). Useful for checking the sign of `x`
- To check if a number is within a range of size $\texttt2^\texttt n$, then we can fit it to the range $\texttt2^\texttt n$ to $\texttt2^{\texttt{n+1}}\texttt{-1}$ see if `x >> n == 1`. This works because that range starts with a `1` at the fourth bit from the end, so that shifting it would ignore the other three bits and give 1.
- Don't be afraid to use variables for commonly appearing expressions! It's the symbol count that matters, not runtime or memory usage
- Mercilessly simplify! Probably add comments explaining what it's _supposed_ to be though.

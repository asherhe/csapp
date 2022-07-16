---
tags: 2s-compliment 
date created: 2022/07/06 9:43:10 pm
date modified: 2022/07/06 9:52:27 pm
---

# Bit Shifting

Bit shifting is when the bits of some value are "shifted" over by some amount.

Shifting can be done in two directions:

- **Left shifting**: `0x0b << 4 = 0xb0`
  Bits are shifted towards the MSB. The bits that go out of range are discarded and zeros are appended to fill in the gaps
- **Right shifting**:
  Bits are shifted towards the LSB. Bits that go out of range are discarded, but the behaviour on the left side of the value becomes a little strange.

## Arithmetic and Logical Right Shifts

Right shifting is peculiar because there are two ways of doing it.

**Logical right shifting** mirrors left shifting and places zeros in the gap.
**Arithmetic right shifting** is a bit different because it preserves [[Integers and Two's Compliment|two's compliment]] by filling the gap with whatever used to be the MSB.

Since right shifting is frequently used for dividing by powers of two, arithmetic right shift works the best. The C standard does not define precisely what right shift to use, but most machines use arithmetic right shift.

---

Behaviour when shifting by increments greater than the number of bits is not mandated by the C standard, but most machines shift by $k\mod w$. Since this is not necessarily true on all machines, in C we avoid shifting by more than we should.

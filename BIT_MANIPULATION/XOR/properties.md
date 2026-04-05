# XOR Bitwise Properties Reference

### 1. Fundamental Algebraic Properties

- **Commutative:** The order of operands does not change the result.
  $$a \oplus b = b \oplus a$$
- **Associative:** The grouping of operands does not change the result.
  $$(a \oplus b) \oplus c = a \oplus (b \oplus c)$$
- **Identity Element:** XORing any number with zero results in the number itself.
  $$a \oplus 0 = a$$
- **Self-Inverse (Nilpotence):** XORing a number with itself results in zero.
  $$a \oplus a = 0$$

---

### 2. The "Undo" (Inverse) Property

XOR is its own inverse. This allows you to move variables across the equation similar to basic algebra.

- If $a \oplus b = c$, then:
  - $a \oplus c = b$
  - $b \oplus c = a$

---

### 3. Relationship with Addition

XOR is often described as "addition without carries." The relationship between the arithmetic sum and the bitwise XOR sum is:
$$a + b = (a \oplus b) + 2(a \ \& \ b)$$

**Key Implications:**

- $a + b \ge a \oplus b$
- $a + b$ and $a \oplus b$ always have the same parity (both even or both odd).
- If $a \ \& \ b = 0$, then $a + b = a \oplus b$.

---

### 4. Range XOR (Prefix Trick)

Similar to Prefix Sums, you can calculate the XOR sum of any subarray $[L, R]$ in $O(1)$ time after $O(N)$ preprocessing.

- Let $P[i] = a[0] \oplus a[1] \oplus \dots \oplus a[i]$
- $\text{XOR Sum}(L, R) = P[R] \oplus P[L-1]$

---

### 5. Bitwise Independence

Each bit position (0 to 63) is processed independently.

- The $k$-th bit of the result is $1$ if and only if there are an **odd** number of $1$s at the $k$-th bit position across all operands.
- $a \ \& \ (b \oplus c) = (a \ \& \ b) \oplus (a \ \& \ c)$ (Distributive over AND).

---

### 6. Common Problem-Solving Patterns

- **Finding the "Odd One Out":** In an array where every element appears twice except for one, XORing all elements results in the unique element.
- **Subsegment Partitioning:** If the total XOR sum of an array is $S$, and you want to split it into $k$ segments each with XOR sum $X$:
  - If $k$ is even: $S$ must be $0$.
  - If $k$ is odd: $S$ must be $X$.
- **Linear Basis:** A set of numbers can be reduced to a "basis" (max size 64) that can represent every possible XOR sum achievable by any subset of the original set.

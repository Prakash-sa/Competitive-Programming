# Clock Modulo Congruences & Modular Arithmetic

This guide explores the relationship between modular arithmetic and time representation (as on a clock face), and covers key concepts, algorithms, and code for modular operations.

---

## 1. Modulo Operation & Special Cases

The modulo operation finds the remainder after division. In Python, the result's sign matches the divisor's sign. Some special cases:

- **Negative Dividend:** The result may be positive or negative, depending on language rules.
- **Negative Divisor:** The sign of the result may vary by language.
- **Zero Divisor:** Division by zero is undefined.

**General formula:**

$$
r = a - b \times \left\lfloor \frac{a}{b} \right\rfloor
$$

Where $r$ is the remainder, $a$ is the dividend, and $b$ is the divisor.

**Example:**

$$
-7 \% 5 = -7 - 5 \times \left\lfloor \frac{-7}{5} \right\rfloor = -7 - 5 \times (-2) = -7 + 10 = 3
$$

---

## 2. Modular Exponentiation

Efficiently computes $a^n \bmod m$ in $O(\log n)$ time by iterating through the bits of the exponent.

```python
def power_mod(base, exponent, modulus):
	result = 1
	base %= modulus
	while exponent > 0:
		if exponent % 2 == 1:
			result = (result * base) % modulus
		base = (base * base) % modulus
		exponent //= 2
	return result
```

---

## 3. Fermat's Little Theorem

If $p$ is a prime and $a$ is not divisible by $p$:

$$
a^{p-1} \equiv 1 \pmod{p}
$$

**Example:**

$$
2^{5-1} = 2^4 = 16 \equiv 1 \pmod{5}
$$

This theorem is widely used in number theory, cryptography, and computer science.

---

## 4. Modular Inverse & Division

To divide $a$ by $b$ modulo $m$, find the modular inverse of $b$ (i.e., $b^{-1}$ such that $b \cdot b^{-1} \equiv 1 \pmod{m}$), then compute $(a \cdot b^{-1}) \bmod m$.

### Methods to Find Modular Inverse

#### a) Extended Euclidean Algorithm (Python Example)

```python
def mod_inv(a, m):
    m0, x0, x1 = m, 0, 1
    if m == 1:
        return 0
    while a > 1:
        q = a // m
        a, m = m, a % m
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += m0
    return x1

def mod_div(a, b, m):
    a %= m
    inv = mod_inv(b, m)
    if inv == -1:
        return -1  # Modular inverse doesn't exist
    return (a * inv) % m
```

#### b) Fermat's Little Theorem (when $m$ is prime)

The modular inverse of $b$ modulo $m$ is $b^{m-2} \bmod m$.

```python
def mod_inv(b, m):
	return pow(b, m-2, m)
```

Then, $a / b \bmod m = (a \cdot b^{-1}) \bmod m$.

---

## 5. Existence of Modular Inverses

An integer $a$ has an inverse modulo $m$ if and only if $\gcd(a, m) = 1$ (i.e., $a$ and $m$ are coprime).

**Example:**

$$
a = 3,\ m = 7 \\
\gcd(3, 7) = 1 \implies \text{inverse exists}
$$

---

## 6. Composite Expressions in Modular Arithmetic

You can combine addition, subtraction, and multiplication under a modulus:

Given $m = 10$, compute $(5 + 3) - (6 \times 2) \bmod 10$:

$$
(5 + 3) \% 10 = 8 \\
(6 \times 2) \% 10 = 2 \\
(8 - 2) \% 10 = 6
$$

So, $(5 + 3) - (6 \times 2) \bmod 10 = 6$.

---

## 7. Why Prime Modulo Helps in Inverse Calculation

When $m$ is prime, every integer not divisible by $m$ has an inverse modulo $m$. This maximizes the set of invertible elements and simplifies computations.

---

## 8. Co-Primality

Two integers $a$ and $b$ are coprime if their greatest common divisor (GCD) is 1. Co-primality ensures the existence of modular inverses.

---

**Summary:**

Modular arithmetic is essential for cyclic phenomena (like clocks), cryptography, and efficient computation. Understanding modular inverses, exponentiation, and their properties is crucial for competitive programming and number theory.

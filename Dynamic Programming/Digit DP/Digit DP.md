# Digit DP

Digit DP is dynamic programming over the digits of a number. It is useful when
you need to count or optimize over numbers in a range, especially when the
condition depends on individual digits.

Common examples:

- Count numbers `<= N` with no consecutive equal digits.
- Count numbers `<= N` whose digit sum is `X`.
- Count numbers `<= N` divisible by `K`.
- Count numbers that do not contain digit `4`.

Instead of iterating over every number from `1` to `N`, convert `N` to a string
and build valid numbers one digit at a time.

## Core Idea

For a query like `count valid numbers <= N`:

1. Convert `N` into its digit string `s`.
2. Recursively choose one digit at each position.
3. Use DP to avoid recalculating the same state.
4. Track whether the current prefix is still equal to the prefix of `N`.

The range query `[L, R]` is usually handled as:

```python
answer = solve(R) - solve(L - 1)
```

## Standard State

A typical Digit DP state looks like this:

```python
dp(pos, tight, leading_zero, other_states...)
```

Where:

- `pos`: current index in the digit string.
- `tight`: whether the current prefix is exactly equal to `N`'s prefix.
- `leading_zero`: whether we have only placed leading zeros so far.
- `other_states`: problem-specific information.

Examples of `other_states`:

- `digit_sum`
- `last_digit`
- `remainder`
- `mask` of used digits
- `changed` flag
- `count` of some digit

## Tight Bound

The `tight` flag controls the maximum digit you are allowed to place.

```python
limit = int(s[pos]) if tight else 9
```

For every possible digit:

```python
for d in range(limit + 1):
    next_tight = tight and (d == int(s[pos]))
```

If `tight` is `True`, you cannot exceed the current digit of `N`. If you choose
a smaller digit, the remaining positions are free to use `0` through `9`.

## Leading Zeros

Leading zeros let every constructed number have the same length as `N`.

For example, while solving `N = 527`, the number `42` is represented as `042`.

Use `leading_zero` when:

- The number `0` needs special handling.
- A condition should start only after the first non-zero digit.
- You track `last_digit`, digit count, distinct digits, or repeated digits.

Typical update:

```python
next_leading_zero = leading_zero and d == 0
```

If you track `last_digit`, avoid comparing against leading zeros:

```python
if not leading_zero and d == last_digit:
    continue
```

## Base Case

When all digits have been processed:

```python
if pos == len(s):
    return 1 if valid_state else 0
```

The base case is where you decide whether the number you built should be
counted.

## Example 1: Count Numbers `<= N`

This counts all numbers from `0` to `N`.

```python
from functools import lru_cache


def solve(N):
    s = str(N)

    @lru_cache(None)
    def dp(pos, tight):
        if pos == len(s):
            return 1

        limit = int(s[pos]) if tight else 9
        ans = 0

        for d in range(limit + 1):
            next_tight = tight and (d == int(s[pos]))
            ans += dp(pos + 1, next_tight)

        return ans

    return dp(0, True)
```

## Example 2: Count Numbers With Digit Sum `X`

```python
from functools import lru_cache


def count_numbers(N, target_sum):
    s = str(N)

    @lru_cache(None)
    def dp(pos, tight, digit_sum):
        if digit_sum > target_sum:
            return 0

        if pos == len(s):
            return int(digit_sum == target_sum)

        limit = int(s[pos]) if tight else 9
        ans = 0

        for d in range(limit + 1):
            next_tight = tight and (d == int(s[pos]))
            ans += dp(pos + 1, next_tight, digit_sum + d)

        return ans

    return dp(0, True, 0)
```

## Example 3: No Consecutive Equal Digits

This version counts numbers in `[1, N]`.

```python
from functools import lru_cache


def count_no_equal_adjacent(N):
    if N <= 0:
        return 0

    s = str(N)

    @lru_cache(None)
    def dp(pos, tight, leading_zero, last_digit):
        if pos == len(s):
            return int(not leading_zero)

        limit = int(s[pos]) if tight else 9
        ans = 0

        for d in range(limit + 1):
            next_tight = tight and (d == int(s[pos]))
            next_leading_zero = leading_zero and d == 0

            if not next_leading_zero and not leading_zero and d == last_digit:
                continue

            next_last_digit = -1 if next_leading_zero else d
            ans += dp(pos + 1, next_tight, next_leading_zero, next_last_digit)

        return ans

    return dp(0, True, True, -1)
```

## Reusable Template

```python
from functools import lru_cache


def solve(N):
    if N < 0:
        return 0

    s = str(N)

    @lru_cache(None)
    def dp(pos, tight, leading_zero, state):
        if pos == len(s):
            return int(is_valid(leading_zero, state))

        limit = int(s[pos]) if tight else 9
        ans = 0

        for d in range(limit + 1):
            next_tight = tight and (d == int(s[pos]))
            next_leading_zero = leading_zero and d == 0
            next_state = update(state, d, next_leading_zero)

            ans += dp(pos + 1, next_tight, next_leading_zero, next_state)

        return ans

    return dp(0, True, True, initial_state)
```

## Practice Progression

Beginner:

- Count numbers without digit `4`.
- Count numbers with even digit sum.
- Count numbers containing at least one `7`.

Medium:

- Count numbers with no consecutive equal digits.
- Count numbers divisible by `K`.
- Count numbers with exactly `X` non-zero digits.

Hard:

- Count numbers where digit sum is `K` and the number is divisible by `M`.
- Count numbers with at most `X` distinct digits.
- Count numbers using a digit bitmask and a modulo constraint.

## Common Mistakes

- Forgetting to update `tight` correctly.
- Treating leading zeros as real digits.
- Returning the wrong value in the base case.
- Forgetting to memoize.
- Counting `0` when the problem asks for `[1, N]`.
- Using a mutable object as a DP state.

## Mental Model

Think:

> I am constructing a number digit by digit while staying under the bound `N`.

Every Digit DP problem is mostly about choosing the right state.

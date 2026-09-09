# Python Interview Questions and Answers

This guide covers common Python interview topics, from core language behavior to concurrency, testing, and practical coding patterns. Unless stated otherwise, examples target Python 3.

## Core Language

### 1. What is the difference between a list and a tuple?

A list is mutable, while a tuple is immutable. Lists are typically used for collections that change; tuples are useful for fixed records and can be dictionary keys when all their elements are hashable.

```python
items = [1, 2, 3]
items.append(4)

point = (10, 20)
# point[0] = 5  # TypeError
```

### 2. What does mutable versus immutable mean?

A mutable object's value can change after creation. Lists, dictionaries, and sets are mutable. Integers, strings, tuples, and `frozenset` objects are immutable.

Names in Python refer to objects. An operation may mutate the existing object or bind a name to a new object:

```python
values = [1, 2]
alias = values
values.append(3)       # Both names see the mutation.

word = "cat"
other = word
word += "s"           # word now refers to a new string.
```

### 3. What is the difference between `==` and `is`?

`==` compares values. `is` tests whether two references point to the same object. Use `is` for singletons such as `None`.

```python
a = [1, 2]
b = [1, 2]

assert a == b
assert a is not b
assert a is not None
```

Do not rely on interning of small integers or strings when deciding whether to use `is`.

### 4. How are arguments passed in Python?

Python uses object references passed by assignment. A function receives new local names bound to the same objects supplied by the caller. It can mutate a mutable argument, but rebinding a parameter does not rebind the caller's name.

```python
def update(values, count):
    values.append("new")  # Visible to the caller.
    count += 1            # Only rebinds the local name.
```

### 5. Why are mutable default arguments dangerous?

Default arguments are evaluated once when the function is defined, not on every call. A mutable default can therefore retain state between calls.

```python
def add_item(item, items=None):
    if items is None:
        items = []
    items.append(item)
    return items
```

### 6. What are `*args` and `**kwargs`?

`*args` collects extra positional arguments into a tuple. `**kwargs` collects extra keyword arguments into a dictionary. The same syntax can unpack arguments at a call site.

```python
def describe(name, *skills, active=True, **metadata):
    return name, skills, active, metadata

options = {"active": False, "level": "senior"}
describe("Ada", "Python", "SQL", **options)
```

### 7. What is the LEGB rule?

Python resolves names in this order:

1. Local scope
2. Enclosing function scopes
3. Global module scope
4. Built-in scope

Use `nonlocal` to rebind a name in the nearest enclosing function scope and `global` to rebind a module-level name.

### 8. What is the difference between shallow and deep copying?

A shallow copy creates a new outer container but shares nested objects. A deep copy recursively copies nested objects.

```python
import copy

original = [[1], [2]]
shallow = copy.copy(original)
deep = copy.deepcopy(original)

original[0].append(9)
assert shallow[0] == [1, 9]
assert deep[0] == [1]
```

### 9. What makes an object hashable?

A hashable object has a hash value that remains stable during its lifetime and can be compared for equality. Hashable objects can be dictionary keys or set members. Immutable built-ins are often hashable, but a tuple is hashable only when all its elements are hashable.

Objects that compare equal must have equal hashes.

### 10. How do dictionaries work?

A dictionary is a hash table that provides average-case `O(1)` lookup, insertion, and deletion. Keys must be hashable. Hash collisions are resolved internally, and pathological collision patterns can degrade performance.

Modern Python dictionaries preserve insertion order. This ordering guarantee does not mean that keys are sorted.

## Iteration and Functional Features

### 11. What is the difference between an iterable and an iterator?

An iterable can produce an iterator, usually through `iter()`. An iterator produces one item at a time through `next()` and raises `StopIteration` when exhausted.

```python
numbers = [1, 2, 3]       # Iterable
iterator = iter(numbers)  # Iterator
first = next(iterator)
```

### 12. What is a generator?

A generator is a lazy iterator, commonly created by a function containing `yield` or by a generator expression. It produces values on demand, which can reduce memory usage for large sequences.

```python
def squares(limit):
    for value in range(limit):
        yield value * value
```

Generators are single-use: once exhausted, they must be recreated to iterate again.

### 13. List comprehension or generator expression?

A list comprehension builds the entire list immediately. A generator expression computes each value only when requested.

```python
eager = [x * x for x in range(1_000)]
lazy = (x * x for x in range(1_000))
```

Use a list when values need to be reused or indexed. Use a generator for one-pass processing or large streams.

### 14. What is a decorator?

A decorator is a callable that takes a function or class and returns a replacement. It is often used for logging, authorization, caching, retries, or registration.

```python
from functools import wraps

def traced(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"calling {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

@traced
def add(a, b):
    return a + b
```

`functools.wraps` preserves useful metadata from the wrapped function.

### 15. What is a closure?

A closure is a function that retains access to variables from its enclosing scope even after that outer function returns.

```python
def multiplier(factor):
    def multiply(value):
        return value * factor
    return multiply

double = multiplier(2)
assert double(5) == 10
```

### 16. What is late binding in closures?

Free variables are looked up when the inner function is called, not when it is defined. This can surprise developers who create functions in a loop.

```python
functions = [lambda value=i: value for i in range(3)]
assert [func() for func in functions] == [0, 1, 2]
```

The default argument captures the current loop value at definition time.

## Object-Oriented Python

### 17. What is the difference between instance, class, and static methods?

- An instance method receives `self` and works with an object.
- A class method receives `cls` and is useful for alternative constructors or class-wide behavior.
- A static method receives neither automatically and groups a related utility with the class.

```python
class Temperature:
    unit = "C"

    def __init__(self, value):
        self.value = value

    @classmethod
    def from_fahrenheit(cls, value):
        return cls((value - 32) * 5 / 9)

    @staticmethod
    def is_valid(value):
        return value >= -273.15
```

### 18. What is method resolution order (MRO)?

MRO is the order in which Python searches classes for an attribute or method, especially with multiple inheritance. Python uses C3 linearization. Inspect it with `ClassName.mro()`.

Zero-argument `super()` follows the MRO; it does not simply mean “call my parent.” Cooperative multiple inheritance works best when participating methods consistently call `super()` and use compatible signatures.

### 19. What are dunder methods?

Double-underscore methods define how objects participate in Python operations. Examples include `__init__`, `__repr__`, `__len__`, `__iter__`, `__eq__`, and `__enter__`.

Prefer calling the corresponding built-in, such as `len(obj)`, instead of invoking `obj.__len__()` directly.

### 20. What is the difference between `__repr__` and `__str__`?

`__repr__` should provide an unambiguous, developer-oriented representation. `__str__` should provide a readable, user-oriented representation. If `__str__` is absent, Python falls back to `__repr__`.

### 21. What is a dataclass?

A dataclass reduces boilerplate for data-holding classes by generating methods such as `__init__`, `__repr__`, and `__eq__` from annotated fields.

```python
from dataclasses import dataclass, field

@dataclass(frozen=True)
class User:
    name: str
    roles: tuple[str, ...] = field(default_factory=tuple)
```

Use `default_factory` for mutable defaults. `frozen=True` prevents normal field reassignment, though it does not recursively freeze nested values.

### 22. Composition or inheritance?

Inheritance models an “is-a” relationship and enables polymorphism. Composition models a “has-a” relationship by assembling objects from collaborators. Prefer composition when behavior should be replaceable or when the subtype relationship is weak; it usually reduces coupling.

## Exceptions and Resource Management

### 23. How should exceptions be handled?

Catch the narrowest exception type that can be handled meaningfully. Avoid a bare `except`, do not silently discard errors, and preserve the original cause when translating exceptions.

```python
try:
    value = int(raw_value)
except ValueError as error:
    raise ConfigurationError("port must be an integer") from error
```

The `else` block runs when no exception occurs. The `finally` block runs during normal completion and exception propagation, so it is appropriate for cleanup.

### 24. What is a context manager?

A context manager controls setup and cleanup around a block, even if the block raises an exception. Files and locks are common examples.

```python
from contextlib import contextmanager

@contextmanager
def managed_resource(resource):
    try:
        yield resource
    finally:
        resource.close()
```

Classes can implement the protocol with `__enter__` and `__exit__`.

## Concurrency and Performance

### 25. What is the Global Interpreter Lock (GIL)?

In the standard CPython build, the GIL normally allows only one thread at a time to execute Python bytecode. Threads can still help I/O-bound workloads because the GIL is released while waiting on many blocking operations. CPU-bound pure-Python work usually benefits more from processes, native extensions, or a different execution strategy.

The GIL is an implementation detail, not a substitute for synchronization: multi-step updates to shared state can still have race conditions.

### 26. When should you use threads, processes, or `asyncio`?

| Tool | Good fit | Main trade-off |
| --- | --- | --- |
| Threads | Blocking I/O and shared-memory tasks | Synchronization and GIL constraints |
| Processes | CPU-bound parallel work | Startup, serialization, and memory overhead |
| `asyncio` | Many concurrent, cooperative I/O operations | Requires async-compatible libraries and non-blocking code |

Measure real workloads before choosing. A thread or process pool is often simpler than rewriting a small program around asynchronous I/O.

### 27. What do `async` and `await` do?

Calling an `async def` function creates a coroutine object. `await` suspends the current coroutine until an awaitable completes, allowing the event loop to run other work.

```python
import asyncio

async def fetch_all():
    first, second = await asyncio.gather(fetch("/a"), fetch("/b"))
    return first, second
```

`asyncio` provides concurrency, not automatic CPU parallelism. Blocking calls inside the event-loop thread stall other coroutines.

### 28. How is memory managed in CPython?

CPython primarily uses reference counting, supplemented by a cyclic garbage collector for unreachable reference cycles. `del name` removes a binding; it does not guarantee immediate destruction if other references remain.

Implementation-specific memory behavior should not be used as part of program correctness. Manage external resources explicitly with context managers.

### 29. How do you improve slow Python code?

First profile instead of guessing. Then consider:

- Choosing a better algorithm or data structure.
- Moving repeated work out of loops.
- Using built-ins, comprehensions, or optimized libraries.
- Streaming data instead of materializing it unnecessarily.
- Caching only when invalidation and memory costs are acceptable.
- Using concurrency appropriate to the workload.

State both time and space complexity during interviews.

## Modules, Types, and Testing

### 30. Why use `if __name__ == "__main__"`?

When a file is run directly, its `__name__` is `"__main__"`. When imported, its `__name__` is the module name. The guard prevents script-only behavior from running during import.

```python
def main():
    print("run application")

if __name__ == "__main__":
    main()
```

### 31. What are type hints?

Type hints describe expected types for readers and static analysis tools. Python does not enforce them automatically at runtime.

```python
def index_by_id(users: list[User]) -> dict[int, User]:
    return {user.id: user for user in users}
```

Type hints improve documentation and tooling, but tests and runtime validation are still needed at trust boundaries.

### 32. What is duck typing?

Duck typing focuses on supported behavior rather than a concrete class: if an object provides the needed operation, it can be used. `typing.Protocol` can express this structural requirement for static checking without requiring inheritance.

### 33. How should Python code be tested?

Tests should be deterministic, isolated, and focused on observable behavior. A balanced suite commonly includes:

- Unit tests for small pieces of logic.
- Integration tests for component boundaries such as databases or APIs.
- End-to-end tests for a few critical user flows.

Use dependency injection or targeted mocks around external boundaries. Avoid mocking so deeply that a test only verifies its own setup.

### 34. What is the difference between a module and a package?

A module is an importable unit, commonly a `.py` file. A package groups modules under a shared namespace. Traditional packages contain `__init__.py`; namespace packages can span directories without it.

Avoid naming local files after standard-library modules such as `json.py` or `typing.py`, because they can shadow the intended import.

## Practical Coding Questions

### 35. How do you count item frequencies?

```python
from collections import Counter

counts = Counter(["a", "b", "a"])
assert counts["a"] == 2
```

Building the counter takes `O(n)` time and `O(k)` space for `k` distinct items.

### 36. How do you remove duplicates while preserving order?

For hashable values:

```python
unique = list(dict.fromkeys(values))
```

This takes average-case `O(n)` time and `O(n)` additional space.

### 37. How do you group records by a key?

```python
from collections import defaultdict

by_team = defaultdict(list)
for employee in employees:
    by_team[employee.team].append(employee)
```

`defaultdict` avoids separate key-existence checks while keeping the intent clear.

### 38. How do you implement a simple retry with exponential backoff?

```python
import random
import time

def call_with_retry(operation, attempts=3, base_delay=0.1):
    for attempt in range(attempts):
        try:
            return operation()
        except TransientError:
            if attempt == attempts - 1:
                raise
            delay = base_delay * (2 ** attempt)
            time.sleep(delay + random.uniform(0, delay))
```

Only retry transient failures. Use bounded attempts, add jitter, respect operation idempotency, and propagate the final error.

### 39. How do you build an LRU cache?

For production code, `functools.lru_cache` is appropriate for caching function results. In an interview implementation, combine a dictionary with a doubly linked list so lookup, insertion, promotion, and eviction are all `O(1)`.

```python
from functools import lru_cache

@lru_cache(maxsize=256)
def load_user(user_id):
    return query_user(user_id)
```

The arguments and return-value lifetime must fit the cache semantics. Consider staleness, memory use, and invalidation.

### 40. How do you find the most common interview bugs in a code review?

Check for:

- Mutable default arguments.
- Incorrect `is` comparisons for values.
- Broad or silently swallowed exceptions.
- Shared-state race conditions.
- Resource leaks from missing context managers.
- Accidental quadratic work inside loops.
- Off-by-one errors and unhandled empty inputs.
- Naive datetime handling and ambiguous time zones.
- Functions that mix business logic with I/O and are difficult to test.

## Rapid Review

- Assignment binds names to objects; it does not copy objects.
- `is` checks identity; `==` checks value equality.
- Dictionary and set operations are average-case `O(1)`.
- Generators are lazy, memory-efficient, and normally single-use.
- Default arguments are evaluated when the function is defined.
- `super()` follows the MRO.
- Context managers make cleanup reliable.
- Threads suit much blocking I/O; processes suit much CPU-bound Python work.
- `asyncio` is cooperative concurrency and must avoid blocking the event loop.
- Type hints support tooling but are not automatically enforced at runtime.
- Profile performance before optimizing it.
- In interviews, explain assumptions, edge cases, and both time and space complexity.

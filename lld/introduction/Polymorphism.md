# Polymorphism

Polymorphism ("many forms") lets objects of different types be treated through the same interface while behaving according to their concrete type.

Why it matters

- Enables generic code that operates on abstractions (interfaces/base classes) while allowing concrete classes to provide specialized behavior.
- Improves extensibility and decouples code that uses objects from the object's specific implementation.

Types

- Static (compile-time) polymorphism
  - Achieved via method overloading or operator overloading (where the language supports it).
  - The compiler selects the appropriate method based on parameter types/signatures.
- Dynamic (runtime) polymorphism
  - Achieved via method overriding in a class hierarchy.
  - The actual method implementation is chosen at runtime based on the object's concrete type.

Examples (concept)

- Overloading: several methods named add(...) that accept different parameter lists.
- Overriding: class Animal defines makeNoise(); subclasses (Dog, Lion) override makeNoise() with type-specific behavior.

Notes

- Operator overloading is not supported in some languages (e.g., Java, JavaScript).
- Static polymorphism relies on different signatures; dynamic polymorphism requires the same signature and typically the same return type.

Comparison

| Aspect                   | Static Polymorphism                                           | Dynamic Polymorphism                       |
| ------------------------ | ------------------------------------------------------------- | ------------------------------------------ |
| Resolved                 | Compile-time                                                  | Runtime                                    |
| Implemented by           | Method overloading (and operator overloading where supported) | Method overriding                          |
| Typical use              | Multiple signatures for convenience/readability               | Specialized runtime behavior in subclasses |
| Method arguments         | Must differ (different signatures)                            | Must be the same                           |
| Return type              | Can differ                                                    | Must be the same                           |
| Private / sealed methods | Can be overloaded                                             | Cannot be overridden                       |
| Performance              | Generally better (compile-time binding)                       | Generally worse (runtime binding)          |

See also

- `Abstraction.md` — designing simple interfaces and hiding implementation details.
- `Inheritance.md` — class hierarchies used for overriding and extension.

# Inheritance

Inheritance lets you create a new class (derived) from an existing class (base). The derived class reuses and extends behavior and state from the base class.

When to use

- Use inheritance to model an IS-A relationship (e.g., Car IS-A Vehicle).
- Avoid using inheritance just to reuse code; prefer composition when appropriate.

Common types of inheritance

- Single inheritance — a class extends one base class.
- Multiple inheritance — a class extends more than one base class (language-dependent).
- Multilevel inheritance — a class derives from a class which itself derives from another.
- Hierarchical inheritance — multiple classes extend the same base class.
- Hybrid inheritance — a combination of the above.

Advantages

- Reusability: share common code in base classes.
- Extensibility: extend functionality in derived classes without modifying the base.
- Localized changes: updates to base behavior propagate to subclasses.

Notes and caveats

- Some languages restrict multiple inheritance (e.g., Java) to avoid complexity; they offer interfaces/traits instead.
- Overuse of inheritance can lead to fragile hierarchies; prefer composition for flexible designs.

See also

- `Encapsulation.md` — control access to internal state.
- `Polymorphism.md` — when subclasses provide specialized behavior for shared interfaces.

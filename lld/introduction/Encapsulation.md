# Encapsulation

Encapsulation is an OOP technique that bundles data (attributes) and methods that operate on that data into a single unit (class) and restricts direct access to some of the object's components. It is commonly used to implement data hiding and to provide a controlled interface (getters/setters).

Why it matters

- Prevents external code from putting the object into an invalid state.
- Makes it easier to change the internal representation without breaking callers.

How to implement

- Use access modifiers (private/protected/public) to restrict direct access.
- Provide public methods (getters/setters or behavior-specific APIs) to expose only what is necessary.

Example (concept)

- A Movie class with private attributes (title, year, genre) and public getters/setters or read-only accessors.

Advantages

- Improves maintainability and modularity.
- Lets you enforce invariants and validation within setters.
- Supports safe refactoring of internal implementation.

See also

- `Abstraction.md` — focuses on exposing a simplified interface and hiding implementation details.
- `Inheritance.md` — when you want to reuse or extend behavior across classes.
  In this section, we will show how to implement encapsulation using some of the most popular object-oriented programming languages, such as Java, C#, Python, C++, and JavaScript.

# Abstraction

Abstraction is an OOP technique that simplifies complex systems by exposing only the relevant behavior and hiding implementation details. In short: show what an object does, hide how it does it.

Why it matters

- Reduces cognitive load for users of a class or module.
- Encourages modular design and separation of concerns.

Real-world examples

- TV remote volume button: you press it to increase volume without knowing how the circuit works.
- Vehicle accelerator: you press the pedal to speed up without knowing the engine details.

Programming example (concept)
Define a simple Circle class that exposes area() and perimeter() while hiding the constant pi and internal calculations. Consumers only call the public methods and don't need to know the implementation.

Advantages

- Reduces system complexity from a user's point of view.
- Makes code more maintainable, reusable, and extensible.
- Encourages cleaner APIs and better separation between interface and implementation.

Abstraction vs Encapsulation (short)

- Abstraction: Hides implementation details and exposes a simpler interface (design-level).
- Encapsulation: Bundles data and methods and restricts direct access to internal state (access-level).

See also

- `Encapsulation.md` — when you want to hide data with getters/setters.
- `Inheritance.md` — when you want to reuse/extend behavior across classes.

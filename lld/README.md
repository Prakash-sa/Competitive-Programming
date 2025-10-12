# LLD (Low-Level Design)

This folder contains concise explanations and examples of core object-oriented design concepts used in low-level design (LLD). The goal is to provide quick reference notes and small code examples to help with interviews and study.

Contents

- Introduction files:
  - `introduction/Abstraction.md` — Abstraction: exposing a simple interface and hiding implementation.
  - `introduction/Encapsulation.md` — Encapsulation: controlling access to data and implementation details.
  - `introduction/Inheritance.md` — Inheritance: modelling IS-A relationships between classes.
  - `introduction/Polymorphism.md` — Polymorphism: compile-time (overloading) and runtime (overriding) polymorphism.

Key concepts covered

- Attributes, methods, classes, and objects
- Principles of OOP: Encapsulation, Abstraction, Inheritance, Polymorphism

Quick links

- [Abstraction](introduction/Abstraction.md)
- [Encapsulation](introduction/Encapsulation.md)
- [Inheritance](introduction/Inheritance.md)
- [Polymorphism](introduction/Polymorphism.md)

How to use

- Read the files under `introduction/` for short explanations and examples.
- Use the examples as a starting point for small practice programs or interview prep.

Contributing

- If you find typos, missing examples, or want to add a short implementation, please open a pull request with a focused change.


### SOLID Principle

S – Single Responsibility Principle (SRP)
➜ One class = one reason to change
Example: separate file saving logic from data processing logic.

O – Open/Closed Principle (OCP)
➜ Classes open for extension, closed for modification
Example: strategy pattern for payment methods.

L – Liskov Substitution Principle (LSP)
➜ Subtypes must be usable as base type without breaking logic.
Example: Shape hierarchy with Rectangle and Square.

I – Interface Segregation (ISP)
➜ Prefer many small interfaces to one big one.
Example: separate “Printable” and “Savable” interfaces.

D – Dependency Inversion (DIP)
➜ Depend on abstractions, not concrete classes.
Example: inject dependencies via constructor or DI container.

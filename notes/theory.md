- LLD
    - LLD is a process of translating high-level components into working code structure. It bridges the gap between architecture and implementation.
    - It defines the classes, interfaces, methods, and their relationships that implement a specific functionality.
    - Example
        - HLD says "We need a notification service"
        - LLD says "We'll use an interface NotificationSender with concrete classes like EmailSender, SmsSender and PushNotificationSender, all managed by a NotificationManager"
    - flow
        ```
        Requirements --> HLD --> LLD --> Code Implementation
        ``` 
    - LLD is not about writing code that works, its about writing code that's modular, testable, extensible and easy to reason about as the system grows.
- Core components of LLD
    1. Classes and Objects
        - Identify main entities & their roles
        - questions
            1. what are the key classes ?
            2. what are their responsibilities ?
            3. what data do they holds (attributes) ?
            4. what operations do they perform (methods) ?
    2. Interfaces and Abstractions
        - Interfaces define contracts between components. They are critical to ensure loose coupling, allowing multiple components to interact without depending on each other's internal implementation details.
        - Ask yourself
            1. What functionality should a class expose to the outside world ?
            2. What details should remain hidden ?
            3. Which parts of the system are likely to change or have multiple variations ?
    3. Relationships Between Classes
        - Classes don't exist in isolation. LLD defines these relationships clearly and precisely.
        - Key Relationships
            1. Association
                - A general uses-a relationship
            2. Aggregation (Weak "has-a")
                - An object contains other objects, but they can exist independently. A Department has Professors. If the department is closed, the professors still exist.
            3. Composition (Strong "has-a")
                - An object is composed of other objects, and their lifecycles are tied. A House is composed of Rooms. If you demolish the house, the rooms are destroyed with it.
            4. Inheritance ("is-a")
                - A class inherits properties and behaviors from a parent. A Car is a Vehicle.
        - Cardinality
            - One-to-one
            - One-to-many
            - Many-to-many
    4. Method signatures
        - Once your classes and relationships are defined, the next step is deciding how they behave using methods. A well-designed method signature is self-documenting and intuitive.
        - Consistency, readability, and clarity in method signatures make your code intuitive and easier to maintain.
    5. Design patterns
        - LLD is also the stage where you apply proven solutions to common design problems using design patterns. These patterns provide reusable templates that bring structure, robustness, and maintainability to your code.
        - Common LLD patterns 
            1. Singleton
            2. Factory
            3. Strategy
            4. Observer
            5. Decorator
            6. Adapter
            7. Facade
    - Importance of LLD in Software Development
        - Maintainability
        - Scalability & Performance
        - Testability
        - Collaboration
        - Reusability
    - Importance of LLD interviews
        - Problem-solving
        - Object-oriented principles
        - Design principles
        - Design patterns
        - Clean code
        - Communication & trade-offs

- LLD vs. HLD
    - 

# 📘 Low Level Design (LLD) Roadmap with Go

> A hands-on problem-solving roadmap to master **LLD + Machine Coding using Go**, focusing on **clean architecture, SOLID principles, and production-grade design**.

---

## 🎯 Goal

* Learn **Object-Oriented Design (OOD)** using Go idioms
* Master **Design Patterns + SOLID**
* Build **real-world systems from scratch**
* Prepare for **Machine Coding / LLD interviews**

---

## 🧱 Prerequisites

Before starting:

* Go basics (structs, interfaces, concurrency)
* OOP Concepts (encapsulation, abstraction)
* SOLID principles
* Basic UML / class diagrams

👉 LLD focuses on **component-level design, class structure, and maintainability** ([Coding Shuttle][1])

---

# 🗺️ Learning Path

---

## 🟢 Phase 1: Beginner (Core OOD + Modeling)

Focus:

* Class design
* Relationships
* Simple state management

### Problems

* [ ] Tic-Tac-Toe
* [ ] Snake and Ladder
* [ ] Minesweeper
* [ ] Chess Game
* [ ] JSON Parser
* [ ] File System
* [ ] Logging Library (like log4j)
* [ ] Vending Machine
* [ ] ATM Machine
* [ ] Hotel Management System
* [ ] Restaurant Management System

📌 These problems help build **basic modeling and object interaction skills** ([lldcoding.com][2])

---

## 🟡 Phase 2: Intermediate (Design Patterns + Real Systems)

Focus:

* SOLID principles
* Design patterns (Strategy, Observer, Factory)
* Concurrency + scalability basics

### Problems

* [ ] Parking Lot System
* [ ] Car Rental System
* [ ] Rate Limiter
* [ ] Thread Pool
* [ ] Coupon System
* [ ] Google Calendar (DB modeling)
* [ ] Splitwise
* [ ] Movie Ticket Booking System
* [ ] Ride Sharing Service
* [ ] Web Crawler
* [ ] Food Delivery System (Zomato-like)
* [ ] Twitter / Social Feed System
* [ ] Stack Overflow

📌 These problems simulate **real-world backend systems and machine coding rounds** ([lldcoding.com][2])

---

## 🔴 Phase 3: Advanced (Scalable Systems + Distributed Thinking)

Focus:

* System boundaries
* Concurrency-heavy systems
* Trade-offs & extensibility

### Problems

* [ ] Google Drive
* [ ] AWS S3 (Object Storage)
* [ ] WhatsApp / Chat System
* [ ] Video Conferencing (Zoom-like)
* [ ] Gmail System
* [ ] Load Balancer
* [ ] NoSQL Database
* [ ] Distributed File Sharing (Dropbox)
* [ ] Cryptocurrency Exchange
* [ ] Collaborative Editor (Google Docs)

📌 These problems require **deep design thinking + extensible architecture** ([lldcoding.com][2])

---

## ⚡ Phase 4: Core Systems (Must for Backend Engineers)

Focus:

* Internals + system building

### Problems

* [ ] In-Memory Cache (LRU/LFU)
* [ ] Message Queue (Kafka-like)
* [ ] Job Scheduler / Cron System
* [ ] Distributed Lock
* [ ] Connection Pool
* [ ] Key-Value Store
* [ ] Rate Limiter (All algorithms)

📌 These are **core backend primitives frequently asked in interviews**

---

## 🧵 Phase 5: Concurrency & Multithreading

Focus:

* Thread safety
* Synchronization
* Go routines + channels

### Problems

* [ ] Thread-safe Logger
* [ ] Thread-safe Two Sum
* [ ] Producer-Consumer System
* [ ] Parallel Task Execution Engine

📌 Concurrency is critical for real-world systems and interviews

---

# 🛠️ Implementation Guidelines (Go-focused)

For each problem:

### 1. Requirement Clarification

* Functional + Non-functional

### 2. Identify Core Entities

```go
type User struct {}
type Order struct {}
type Service struct {}
```

### 3. Define Interfaces (Important in Go)

```go
type PaymentStrategy interface {
    Pay(amount float64) error
}
```

### 4. Apply Design Patterns

* Strategy → Payments
* Observer → Notifications
* Factory → Object creation

### 5. Add Concurrency (if needed)

```go
go worker.Process(job)
```

### 6. Write Clean Modules

* `models/`
* `services/`
* `repositories/`
* `controllers/`

---

# 📅 Suggested Weekly Plan

| Week  | Focus                   |
| ----- | ----------------------- |
| 1–2   | Beginner problems       |
| 3–5   | Intermediate systems    |
| 6–8   | Advanced systems        |
| 9–10  | Core backend primitives |
| 11–12 | Concurrency + revision  |

---

# 🧠 What You Should Learn From Each Problem

* Object modeling
* API design
* Design patterns usage
* Extensibility
* Trade-offs
* Code readability

---

# 🚀 Final Advice

LLD is not about “correct answer” — it’s about:

* **Clarity of thought**
* **Extensible design**
* **Clean code structure**

As industry trends show, interviews now focus on **your ability to design systems, not just code functions** ([LLD Problems][3])

---

# 📦 Bonus: How to Turn This into a GitHub Project

For each problem:

```
/lld-go
  /parking-lot
  /rate-limiter
  /splitwise
```

Each folder:

* README.md (design explanation)
* diagrams/
* code/

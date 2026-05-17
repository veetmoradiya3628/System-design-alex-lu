# <Project Name>

> Example:
> Parking Lot System / URL Shortener / Rate Limiter / Chat System

---

# 1. Problem Statement

## Objective

Describe the system in simple terms.

Example:

Design a scalable parking lot system supporting:
- Multiple parking floors
- Vehicle allocation
- Ticket generation
- Payment processing
- Real-time availability tracking

---

# 2. Requirements

## Functional Requirements

- [ ] Requirement 1
- [ ] Requirement 2
- [ ] Requirement 3
- [ ] Requirement 4

Example:

- Park vehicle
- Remove vehicle
- Generate ticket
- Calculate pricing
- Support multiple vehicle types

---

## Non Functional Requirements

- Scalability
- Extensibility
- Maintainability
- Thread Safety
- High Cohesion
- Low Coupling
- Fault Tolerance
- Testability
- Observability

---

# 3. Capacity Estimation (Optional HLD Thinking)

## Traffic Estimation

| Metric | Estimate |
|---|---|
| Daily Requests | 100K |
| Peak RPS | 2K |
| Concurrent Users | 10K |

---

## Storage Estimation

| Data | Estimate |
|---|---|
| Tickets/day | 100K |
| Logs/day | 1GB |

---

# 4. High Level Design (Alex Xu Style)

## Architecture Overview

```txt
Client
  |
API Gateway
  |
Application Service
  |
Cache
  |
Database
```

---

## Major Components

| Component | Responsibility |
|---|---|
| API Gateway | Request routing |
| Service Layer | Business logic |
| Cache | Fast retrieval |
| Database | Persistent storage |
| Queue | Async processing |

---

## Future Scalability Thoughts

- Horizontal scaling
- Distributed cache
- Event-driven architecture
- CQRS
- Sharding
- Replication
- Multi-region deployment

---

# 5. Core Domain Modeling

## Main Entities

| Entity | Responsibility |
|---|---|
| Entity1 | Responsibility |
| Entity2 | Responsibility |

---

## Relationships

```txt
User --> Order
Order --> Payment
Payment --> Invoice
```

---

# 6. API Design

## REST APIs

### Create Resource

```http
POST /resource
```

### Get Resource

```http
GET /resource/{id}
```

### Delete Resource

```http
DELETE /resource/{id}
```

---

# 7. Database Design

## Tables / Collections

### Example Table

| Column | Type |
|---|---|
| id | UUID |
| created_at | Timestamp |

---

## Indexing Strategy

- Primary index
- Composite index
- Search index

---

# 8. Low Level Design (AlgoMaster Style)

---

## Core Classes

| Class | Responsibility |
|---|---|
| Service | Business logic |
| Repository | Data access |
| Factory | Object creation |

---

## Interfaces

```cpp
class PaymentStrategy {
public:
    virtual double calculateFee() = 0;
};
```

OR

```go
type PaymentStrategy interface {
    CalculateFee() float64
}
```

---

# 9. SOLID Principles Applied

| Principle | Usage |
|---|---|
| SRP | Separate responsibilities |
| OCP | Extend without modification |
| LSP | Proper inheritance |
| ISP | Small interfaces |
| DIP | Abstraction dependency |

---

# 10. Design Patterns Used

| Pattern | Why Used |
|---|---|
| Strategy | Dynamic behavior |
| Factory | Centralized creation |
| Singleton | Shared state |
| Observer | Event notification |
| State | State transitions |

---

# 11. Concurrency Design

## Thread Safety Strategy

- Mutex/RWMutex
- Atomic operations
- Channels
- Lock-free design (if applicable)

---

## Possible Race Conditions

- Concurrent updates
- Duplicate processing
- Deadlocks

---

## Prevention

- Lock ordering
- Idempotency
- Retry strategy

---

# 12. Sequence Flow

## Example Flow

```txt
Client
  |
Controller
  |
Service
  |
Repository
  |
Database
```

---

# 13. Error Handling Strategy

| Scenario | Handling |
|---|---|
| DB Failure | Retry |
| Timeout | Circuit breaker |
| Invalid Input | Validation |

---

# 14. Logging & Observability

## Logging

- Structured logs
- Error logs
- Request tracing

---

## Metrics

- Request latency
- Error rate
- Throughput

---

## Monitoring

- Prometheus
- Grafana
- OpenTelemetry

---

# 15. Security Considerations

- Authentication
- Authorization
- Input validation
- Rate limiting
- SQL injection prevention
- Encryption

---

# 16. Scalability Improvements

## Current Bottlenecks

- Single database
- Synchronous processing
- Memory limitations

---

## Future Improvements

- Redis caching
- Kafka integration
- Microservices
- Load balancing
- Distributed locking

---

# 17. Tradeoffs

| Decision | Pros | Cons |
|---|---|---|
| SQL | Strong consistency | Scaling harder |
| Cache | Faster reads | Cache invalidation |

---

# 18. Testing Strategy

## Unit Tests

- Service logic
- Validation
- Utility functions

---

## Integration Tests

- DB integration
- API integration

---

## Load Testing

- Concurrent requests
- Throughput testing

---

## Concurrency Testing

- Race condition testing
- Deadlock testing

---

# 19. Project Structure

## Go Structure

```txt
cmd/
internal/
pkg/
api/
service/
repository/
model/
config/
tests/
```

---

## C++ Structure

```txt
src/
include/
services/
models/
patterns/
utils/
tests/
```

---

# 20. Build & Run

## Build

```bash
make build
```

---

## Run

```bash
make run
```

---

## Test

```bash
make test
```

---

# 21. Engineering Learnings

## Key Learnings

- SOLID principles
- Design pattern usage
- Thread safety handling
- Scalability thinking
- HLD → LLD mapping
- Tradeoff analysis

---

# 22. Interview Discussion Points

## Questions To Discuss

- Why this design?
- Why this pattern?
- What are bottlenecks?
- How does this scale?
- How to distribute this?
- What breaks first?
- How to improve reliability?

---

# 23. Future Roadmap

## Next Improvements

- gRPC support
- Event-driven design
- Distributed deployment
- Kubernetes deployment
- Service discovery
- Async processing

---

# 24. References

## LLD

- AlgoMaster
- Refactoring Guru

## HLD

- ByteByteGo
- System Design Primer

## Distributed Systems

- Designing Data Intensive Applications

---

# 25. Personal Notes

## Mistakes Made

- Mistake 1
- Mistake 2

---

## Improvements Learned

- Improvement 1
- Improvement 2

---

# 26. Final Engineering Reflection

## Important Takeaways

- What would I redesign?
- What became difficult?
- What scaling issue appeared?
- What pattern helped most?
- What tradeoff was hardest?
- How would Google/Uber solve this?

---
# <System / Problem Name>

> Example:
> Parking Lot System / URL Shortener / Chat System / Food Delivery App

---

# 1. Clarifying Requirements

## Functional Requirements

- [ ] Feature 1
- [ ] Feature 2
- [ ] Feature 3

Example:

- Users can create short URLs
- Users can redirect URLs
- URLs should expire optionally

---

## Non Functional Requirements

- Scalability
- Availability
- Reliability
- Extensibility
- Low Latency
- Fault Tolerance
- Security
- Maintainability

---

## Constraints

| Constraint | Value |
|---|---|
| Daily Requests | 100M |
| Peak QPS | 20K |
| Latency Goal | <100ms |

---

# 2. Interview Thinking Process

## Important Questions

```txt
- What are the core entities?
- What changes frequently?
- What needs scaling?
- What is read-heavy vs write-heavy?
- What consistency guarantees are needed?
- What becomes bottleneck first?
- What should be extensible?
```

---

# 3. High Level Design (HLD)

---

## Architecture Overview

```txt
Client
  |
Load Balancer
  |
API Gateway
  |
Application Services
  |
Cache
  |
Database
  |
Message Queue
```

---

## Core Components

| Component | Responsibility |
|---|---|
| API Gateway | Routing/Auth |
| Service Layer | Business logic |
| Cache | Fast access |
| DB | Persistent storage |
| Queue | Async communication |

---

## Data Flow

```txt
Client
  |
API
  |
Service
  |
Cache
  |
Database
```

---

## Scalability Discussion

### Horizontal Scaling

- Stateless services
- Load balancing
- Service replication

---

### Database Scaling

- Replication
- Sharding
- Partitioning

---

### Caching

- Redis
- CDN
- Local cache

---

### Async Processing

- Kafka
- RabbitMQ
- Background workers

---

# 4. Bottleneck Analysis

| Bottleneck | Possible Solution |
|---|---|
| Database load | Cache |
| High traffic | Load balancing |
| Slow processing | Async queue |
| Large reads | Replicas |

---

# 5. Tradeoff Discussion

| Choice | Pros | Cons |
|---|---|---|
| SQL | Consistency | Harder scaling |
| NoSQL | Scalability | Weak consistency |
| Sync | Simpler | Higher latency |
| Async | Better throughput | Complexity |

---

# 6. Reliability Considerations

- Retry strategy
- Idempotency
- Circuit breaker
- Failover
- Replication
- Dead-letter queues

---

# 7. Security Considerations

- Authentication
- Authorization
- Rate limiting
- Encryption
- Input validation
- Secure tokens

---

# 8. Observability

## Logs

- Structured logging
- Request tracing

---

## Metrics

- Latency
- Throughput
- Error rate

---

## Monitoring

- Prometheus
- Grafana
- OpenTelemetry

---

# 9. Low Level Design (LLD)

---

## Core Entities

| Entity | Responsibility |
|---|---|
| User | User management |
| Service | Business logic |
| Repository | Data layer |

---

## Relationships

```txt
User --> Order
Order --> Payment
Payment --> Invoice
```

---

# 10. Class Design

---

## Interfaces

```cpp
class PaymentStrategy {
public:
    virtual double calculate() = 0;
};
```

OR

```go
type PaymentStrategy interface {
    Calculate() float64
}
```

---

## Services

| Service | Responsibility |
|---|---|
| UserService | User operations |
| PaymentService | Payments |
| NotificationService | Notifications |

---

## Repository Layer

| Repository | Responsibility |
|---|---|
| UserRepository | DB access |
| OrderRepository | DB access |

---

# 11. SOLID Principles

| Principle | Application |
|---|---|
| SRP | Single responsibility |
| OCP | Open for extension |
| LSP | Proper substitution |
| ISP | Small interfaces |
| DIP | Abstraction-based design |

---

# 12. Design Patterns Used

| Pattern | Why |
|---|---|
| Strategy | Dynamic behavior |
| Factory | Object creation |
| Singleton | Shared resource |
| Observer | Event updates |
| State | State transitions |

---

# 13. Concurrency Design

## Thread Safety

- Mutex
- RWMutex
- Atomic operations
- Channels

---

## Race Conditions Considered

- Duplicate requests
- Concurrent updates
- Deadlocks

---

## Prevention Strategy

- Lock ordering
- Idempotency
- Retry mechanism

---

# 14. API Design

---

## Create Resource

```http
POST /resource
```

---

## Get Resource

```http
GET /resource/{id}
```

---

## Delete Resource

```http
DELETE /resource/{id}
```

---

# 15. Database Design

---

## Tables

### Example Table

| Column | Type |
|---|---|
| id | UUID |
| created_at | Timestamp |

---

## Indexing

- Primary index
- Secondary index
- Composite index

---

# 16. Sequence Flow

---

## Example Request Flow

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

# 17. Error Handling

| Error | Handling |
|---|---|
| Timeout | Retry |
| Invalid input | Validation |
| DB failure | Circuit breaker |

---

# 18. Testing Strategy

---

## Unit Tests

- Service logic
- Validation
- Utility functions

---

## Integration Tests

- API + DB flow

---

## Load Tests

- Concurrent requests
- Throughput testing

---

## Concurrency Tests

- Race condition testing
- Deadlock testing

---

# 19. Edge Cases

- Duplicate requests
- Invalid state transitions
- Cache inconsistency
- Network failures
- Partial failures

---

# 20. Scalability Improvements

## Future Enhancements

- Distributed caching
- Event sourcing
- CQRS
- Service discovery
- Kubernetes deployment

---

# 21. Interview Discussion Questions

```txt
- Why this DB?
- Why this pattern?
- What are bottlenecks?
- How would this scale?
- How to make highly available?
- What breaks first?
- What would you redesign?
- How to support 10x traffic?
```

---

# 22. Complexity Analysis

| Operation | Complexity |
|---|---|
| Insert | O(1) |
| Search | O(log n) |

---

# 23. Implementation Structure

---

## Go Structure

```txt
cmd/
internal/
pkg/
api/
service/
repository/
model/
tests/
```

---

## C++ Structure

```txt
src/
include/
services/
patterns/
models/
tests/
```

---

# 24. Engineering Learnings

- SOLID principles
- Design patterns
- Scalability thinking
- Distributed systems concepts
- Thread safety
- Tradeoff analysis

---

# 25. Final Reflection

## Key Takeaways

```txt
- What was hardest?
- What scales poorly?
- What design helped most?
- What tradeoff mattered most?
- How would a FAANG engineer improve this?
```

---
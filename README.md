### Template 

🚀 <Project Name>

«Short one-line description of the system
Example: Scalable URL Shortener with caching and analytics»

---

📌 1. Problem Statement

Describe the system clearly:

- What are we building?
- Who are the users?
- What problem does it solve?

Example:
Design a URL shortening service like TinyURL that converts long URLs into short, unique links and supports high read traffic.

---

🎯 2. Requirements

Functional Requirements

- Users can create short URLs
- Redirect short URL → original URL
- Track number of clicks (optional)

Non-Functional Requirements

- High availability
- Low latency (< 100ms)
- Scalable (millions of requests)
- Fault tolerant

---

📊 3. Capacity Estimation

Estimate scale (very important):

- Requests per second (RPS)
- Read vs Write ratio
- Storage requirements

Example:

- 1M requests/day → ~12 RPS
- Read-heavy system (10:1)
- Storage: 100 bytes per URL

---

🏗️ 4. High-Level Design (HLD)

Explain architecture:

- Components:
  - API Gateway
  - Application Server
  - Database
  - Cache

Add diagram (recommended):

Client → API Gateway → App Server → DB
                          ↓
                        Cache

---

⚙️ 5. Low-Level Design (LLD)

Data Model

Example:

Table: urls
- id (PK)
- short_code (unique)
- long_url
- created_at

APIs

Create Short URL

POST /shorten
{
  "url": "https://example.com"
}

Redirect

GET /:shortCode

---

🔑 6. Key Design Decisions

Explain WHY:

- Why Base62 encoding?
- Why Redis cache?
- Why Postgres?

---

⚡ 7. Optimization Techniques

- Caching (Redis)
- DB indexing
- Connection pooling
- Async processing (queues)

---

🧪 8. Failure Scenarios

Think like a real engineer:

- DB goes down → fallback?
- Cache miss → DB hit
- Duplicate requests → idempotency

---

📈 9. Scaling Strategy

Horizontal Scaling

- Add more app servers

Database Scaling

- Read replicas
- Sharding

Caching Strategy

- Cache-aside

---

🔁 10. Tradeoffs

Document real thinking:

Approach| Pros| Cons
Cache| Fast| Stale data
DB only| Simple| Slow

---

🛠️ 11. Tech Stack

- Language: Node.js / Go
- Database: PostgreSQL
- Cache: Redis
- Queue: Kafka / PubSub
- Infra: Docker, Kubernetes

---

🧑‍💻 12. Implementation Details

Folder Structure

/src
  /controllers
  /services
  /models
  /routes
  /middlewares

---

Setup Instructions

git clone <repo>
cd project
docker-compose up

---

📦 13. Features Implemented

- [x] Basic API
- [x] DB integration
- [x] Cache layer
- [ ] Rate limiting
- [ ] Analytics

---

🔍 14. Observability

- Logging added
- Metrics (optional)
- Health check endpoint

---

💥 15. Load Testing

Tools:

- k6 / JMeter

Results:

- Max RPS handled
- Bottlenecks observed

---

🧠 16. What I Learned

This is the most important section

- Tradeoffs in scaling
- Bottlenecks in DB/cache
- Real-world challenges

---

🚧 17. Future Improvements

- Add distributed caching
- Introduce message queue
- Multi-region deployment

---

📚 18. References

- System Design concepts
- Blogs / docs used

---

✅ 19. Status

🟢 In Progress / Completed / Iterating

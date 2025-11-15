# Inter-Process Communication

## Motivation
Processes/threads must exchange data and coordinate actions without corrupting shared state.

## Mechanisms
- **Shared memory:** high throughput; requires explicit synchronization.
- **Message passing:** send/receive primitives with blocking vs non-blocking semantics; supports local and distributed setups.
- **Pipes:** unnamed (parent-child) or named FIFOs for linear byte streams.
- **Sockets:** TCP/UDP endpoints, including Unix domain sockets for same host.
- **Memory-mapped files:** map files into address space to share data.

## Design Dimensions
- Naming: direct (explicit partner) vs indirect (mailboxes).
- Buffering: zero capacity (rendezvous), bounded, unbounded.
- Synchronization: blocking send/recv vs asynchronous.
- Reliability: error detection, retries, ordering guarantees.

## Producer–Consumer Sketch
Shared buffer of size `N` with semaphores `empty=N`, `full=0`, `mutex=1`. Producers `wait(empty); wait(mutex); produce; signal(mutex); signal(full);` Consumers inverse.

## Interview Prompts
- Describe how you'd implement IPC between unrelated processes on Linux (named pipes, sockets, shared memory).
- Explain how to avoid busy waiting in message passing.

## Placement Essentials
- Compare shared memory vs message passing, including latency, synchronization complexity, and failure cases.
- Discuss how POSIX message queues differ from System V queues, and when sockets are preferable.
- Highlight buffering strategies (bounded/unbounded) and backpressure for producer–consumer designs.

## Python Demo — Pipe-Based Producer/Consumer
```python
"""Use multiprocessing.Pipe to exchange data between processes."""
from multiprocessing import Process, Pipe

def producer(conn):
    for value in range(5):
        conn.send(value)
    conn.send(None)  # sentinel
    conn.close()

def consumer(conn):
    while True:
        data = conn.recv()
        if data is None:
            break
        print(f"Consumed {data}")

if __name__ == "__main__":
    parent_conn, child_conn = Pipe()
    p = Process(target=producer, args=(parent_conn,))
    c = Process(target=consumer, args=(child_conn,))
    p.start(); c.start()
    p.join(); c.join()
```

Tie this example back to OS pipes (bounded buffers within kernel) and discuss blocking semantics if the buffer fills.

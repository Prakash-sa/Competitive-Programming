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

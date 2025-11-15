# I/O Systems

## Layers
1. User-level I/O libraries (stdio, iostream).
2. Device-independent kernel code (buffer cache, spooling, generic block/char interfaces).
3. Device drivers (per-device specifics, register programming).
4. Interrupt handlers and DMA controllers.

## Techniques
- **Programmed I/O (polling):** CPU repeatedly checks device status.
- **Interrupt-driven I/O:** Device interrupts CPU when ready; handler wakes waiting processes.
- **Direct Memory Access (DMA):** Controller transfers blocks between device and memory without CPU intervention.

## Buffering & Spooling
- Single, double, or circular buffers smooth bursty traffic.
- Spooling queues entire jobs/devices (printer spool) to decouple producer/consumer speeds.

## Device Drivers
Split logic into top half (interrupt context) and bottom half (deferred work). Handle initialization, configuration, request queuing, error handling, and power management.

## Caching
I/O subsystems leverage page/buffer caches, read-ahead, and write-back policies to reduce latency.

## Interview Prompts
- Trace what happens when a program calls `read()` on a file mapped to disk.
- Compare polling vs interrupts vs DMA for high-throughput NIC design.

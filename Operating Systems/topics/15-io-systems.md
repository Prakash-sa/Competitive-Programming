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

## Placement Essentials
- Detail the journey from `read()` to interrupt completion, including DMA setup, interrupt handler, and wake-up.
- Compare polling vs interrupts vs DMA trade-offs and when each is appropriate.
- Mention modern frameworks: Linux AIO, `io_uring`, Windows IOCP.

## Python Demo — Async I/O Simulation
```python
"""Use asyncio to mimic overlapped I/O with callbacks."""
import asyncio

async def fake_device_read(name, delay):
    await asyncio.sleep(delay)
    return f"{name} data"

async def main():
    tasks = [asyncio.create_task(fake_device_read("disk", 0.2)),
             asyncio.create_task(fake_device_read("network", 0.1))]
    for task in asyncio.as_completed(tasks):
        result = await task
        print("Completed:", result)

asyncio.run(main())
```

Tie asynchronous completion back to interrupt-driven I/O and how event loops mimic kernel completion queues.

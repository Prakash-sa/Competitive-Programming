# Introduction to Operating Systems

This topic mirrors the "Introduction to OS" section in `README.md` and fleshes out each bullet so you can revise independently of the chat transcript.

## Definition
An operating system (OS) is the system software that sits between applications and hardware, virtualizing and multiplexing resources so multiple programs can run safely and efficiently.

## Core Functions
- **Process management:** create, schedule, and terminate processes; track their state via PCB.
- **Memory management:** keep track of allocation, translation, and protection; ensure isolation between programs.
- **File system management:** expose logical file/directory abstraction over physical storage.
- **I/O and device management:** coordinate access to peripherals using drivers, buffering, and interrupts.
- **Security & protection:** enforce privilege boundaries, authentication, authorization, and auditing.
- **Error detection & accounting:** detect hardware/software faults and maintain usage statistics for billing or tuning.

## OS Types
| Type | Snapshot Use Case |
| --- | --- |
| Batch | Early mainframes running offline jobs |
| Time-sharing / Multitasking | Interactive systems sharing CPU among many users |
| Distributed | Networked nodes cooperating (cluster OS) |
| Network | Manages networking hardware + services |
| Mobile / Embedded | Phones, IoT devices |
| Real-time | Deterministic deadlines (industrial control, avionics) |

## Kernel Styles
- **Monolithic:** entire OS (scheduling, VFS, drivers) compiled into one binary; best raw performance, larger trusted base.
- **Microkernel:** minimalist kernel + user-space services communicating via IPC; better modularity and fault isolation.
- **Hybrid/Modular:** Windows/macOS mix microkernel messaging with loadable modules; Linux uses loadable kernel modules for drivers and filesystems.

## User Mode vs Kernel Mode
- **User Mode:** regular apps execute with restricted privileges. Illegal hardware access triggers traps.
- **Kernel Mode:** OS executes privileged instructions, directly manipulates hardware, page tables, and scheduler structures.

## Boot Overview
1. Firmware/BIOS/UEFI initializes hardware.
2. Bootloader loads the kernel image.
3. Kernel sets up memory management, device drivers.
4. Init/systemd spawns user-level services and login shells.

## Quick Self-Check
- Can you draw the user–kernel boundary and label where shells, drivers, and memory managers live?
- Can you classify any OS (e.g., Android, VxWorks) by type and kernel architecture?

## Placement-Focused Notes
- Tie every OS function to a real debugging story (e.g., "I analyzed context-switch stats with `top` to explain CPU thrashing").
- Mention how cloud providers (AWS Nitro, GCP gVisor) virtualize hardware differently yet rely on the same OS abstractions.
- Be ready to contrast resource isolation provided by OS vs hypervisor vs containers.

## Python Demo — Inspecting the Host OS
```python
"""Show OS metadata that an interviewee can cite when discussing kernels and CPU utilization."""
import os
import platform
from pprint import pprint

def os_snapshot():
    return {
        "kernel_release": platform.release(),
        "kernel_version": platform.version(),
        "platform": platform.platform(),
        "architecture": platform.machine(),
        "logical_cpus": os.cpu_count(),
        "load_average": os.getloadavg() if hasattr(os, "getloadavg") else (None, None, None),
    }

if __name__ == "__main__":
    pprint(os_snapshot())
```

Discuss how `logical_cpus` relates to the scheduler's run queue, and how `load_average` reflects runnable processes versus available CPUs.

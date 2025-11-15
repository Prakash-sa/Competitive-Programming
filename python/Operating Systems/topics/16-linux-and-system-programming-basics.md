# Linux & System Programming Basics

## Essential Commands
- **Process monitoring:** `ps`, `top`, `htop`, `pidstat`.
- **Scheduling tweaks:** `nice`, `renice`, `taskset`.
- **Signals:** `kill`, `pkill`, `killall`.
- **File utilities:** `ls`, `chmod`, `chown`, `cat`, `less`, `stat`.
- **Memory/IO stats:** `free`, `vmstat`, `iostat`, `dmesg`.

## Core Syscalls
| Category | Syscalls |
| --- | --- |
| Process control | `fork`, `execve`, `waitpid`, `_exit` |
| File I/O | `open`, `read`, `write`, `close`, `lseek`, `fsync` |
| IPC | `pipe`, `dup2`, `socket`, `bind`, `listen`, `accept`, `shmget`, `mmap` |
| Synchronization | `pthread_create`, `pthread_mutex_*`, `pthread_cond_*` |

## Mini Shell Outline
1. Read line, parse tokens.
2. Handle built-ins (`cd`, `exit`).
3. For pipelines, create pipe descriptors, `fork`, and use `dup2` to redirect stdin/stdout before `execvp`.
4. Parent closes pipe ends and waits for children.

## Debugging Tools
- `strace`/`ltrace` for syscall/library tracing.
- `gdb` for debugging, `perf` for profiling.
- `/proc/<pid>/maps`, `pmap` to inspect memory layout.

## Interview Prompts
- Explain difference between `fork` and `exec` and why they're separate calls.
- Describe how you'd implement a thread-safe logging system using POSIX APIs.

## Placement Essentials
- Connect Linux commands to OS concepts: `ps` (process table), `top` (scheduler metrics), `nice` (priority adjustments).
- Explain how `fork + exec + wait` map to shell pipelines and job control.
- Discuss ELF binaries, environment variables, signals (`SIGCHLD`, `SIGTERM`), and file descriptor duplication (`dup2`).

## Python Demo — Mini Shell Fragment
```python
"""Implement a tiny shell that supports `cd` and external commands."""
import os
import shlex
import subprocess

while True:
    try:
        cmd = input("mini-sh> ")
    except EOFError:
        break
    parts = shlex.split(cmd)
    if not parts:
        continue
    if parts[0] == "cd":
        os.chdir(parts[1] if len(parts) > 1 else os.path.expanduser("~"))
        continue
    if parts[0] == "exit":
        break
    proc = subprocess.Popen(parts)
    proc.wait()
```

Explain how `subprocess.Popen` uses `fork`/`exec`, and how the shell changes directories via `chdir` in the parent (cannot delegate to child).

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

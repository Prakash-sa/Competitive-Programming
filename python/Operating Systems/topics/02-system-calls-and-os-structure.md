# System Calls & OS Structure

This file expands on the system call and OS-architecture portion of the README.

## System Calls
System calls are controlled entry points into the kernel. A typical sequence:
1. Application invokes a libc wrapper (e.g., `printf`, `open`).
2. Wrapper loads syscall number/arguments into registers.
3. `syscall`/`int 0x80`/`svc` instruction traps into kernel mode.
4. Kernel handler validates arguments, performs work, returns result through registers/errno.

### Categories
- **Process control:** `fork`, `execve`, `wait`, `exit`, `kill`.
- **File management:** `open`, `close`, `read`, `write`, `lseek`, `stat`.
- **Device management:** `ioctl`, `mmap`, `dup`.
- **Information maintenance:** `getpid`, `gettimeofday`, `uname`.
- **Communication:** `pipe`, `socket`, `send`, `recv`, `shmget`.

### Micro-Example
```c
if (fork() == 0) {
    execl("/bin/ls", "ls", "-l", NULL);
    _exit(1);
}
wait(NULL);
```

## OS Structural Models
| Model | Traits | Example |
| --- | --- | --- |
| Simple/Monolithic | All services compiled together | Early UNIX, MS-DOS |
| Layered | Strict layer dependencies | THE, some teaching OS |
| Microkernel | Minimal kernel + user-space servers communicating via message passing | Minix, QNX |
| Modular | Loadable kernel modules for drivers/filesystems | Modern Linux |
| Virtual Machines | Hypervisor exposes virtual hardware to guests | VMware, KVM |

## Interview Prompts
- Why are syscalls slower than regular function calls? (Privilege switch, pipeline flush, extra validation.)
- How do user threads interact with blocking system calls in many-to-one vs one-to-one models?

## Practice Idea
Use `strace ls` to capture real syscalls, then map them back to the categories above.

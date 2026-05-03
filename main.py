import sys
from sys import stdin, stdout

sys.setrecursionlimit(10**7)

cycle_start = -1
cycle_end = -1

def dfs(v, par, color, adj):
    global cycle_start, cycle_end

    color[v] = 1

    for u in adj[v]:
        if color[u] == 0:

            if dfs(u, v, color, adj):
                return True

        elif color[u] == 1:
            cycle_start = u
            cycle_end = v
            return True

    color[v] = 2
    return False


def main():
    global cycle_start, cycle_end

    data = stdin.read().split()
    idx = 0

    n = int(data[idx])
    idx += 1

    m = int(data[idx])
    idx += 1

    adj = [[] for _ in range(n + 1)]

    for _ in range(m):
        u = int(data[idx])
        v = int(data[idx + 1])
        idx += 2

        adj[u].append(v)

    color = [0] * (n + 1)

    for v in range(1, n + 1):
        if color[v] == 0:
            if dfs(v, -1, color, adj):
                break

    if cycle_start == -1:
        stdout.write("NO\n")
    else:
        stdout.write("YES\n")


if __name__ == "__main__":
    main()

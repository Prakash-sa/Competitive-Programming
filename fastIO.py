import sys

input = sys.stdin.readline
print = sys.stdout.write
sys.setrecursionlimit(1 << 25)

MOD = 10**9 + 7
INF = 10**18

def read():
    return sys.stdin.buffer.read()

def ints():
    return map(int, input().split())

def list_ints():
    return list(map(int, input().split()))

def write_line(value=""):
    sys.stdout.write(str(value) + "\n")

def write_lines(values):
    sys.stdout.write("\n".join(map(str, values)))
    if values:
        sys.stdout.write("\n")


def solve():
    
    pass

if __name__ == "__main__":
    solve()

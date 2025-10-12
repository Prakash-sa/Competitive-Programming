import sys

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    a = list(map(int, data[1:1+n]))

    # dp[i] = minimum cost to reach stone i
    dp = [0] * n
    if n >= 2:
        dp[1] = abs(a[1] - a[0])

    for i in range(2, n):
        cost1 = dp[i-1] + abs(a[i] - a[i-1])
        cost2 = dp[i-2] + abs(a[i] - a[i-2])
        dp[i] = min(cost1, cost2)

    print(dp[n-1])


if __name__ == '__main__':
    main()
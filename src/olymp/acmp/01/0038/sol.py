n = int(input())

a = list(map(int, input().split()))


def solve():
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for j in range(1, n + 1):
        for i in range(n):
            if i + j > n:
                continue
            if j == 1:
                dp[i][j] = a[i]
            else:
                dp[i][j] = max(a[i] - dp[i + 1][j - 1], a[i + j - 1] - dp[i][j - 1])

    res = dp[0][n]
    if res > 0:
        return 1
    elif res < 0:
        return 2
    return 0


print(solve())

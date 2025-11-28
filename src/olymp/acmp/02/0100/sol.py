n = int(input())


def solve():
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    dp[1] = 10
    dp[2] = dp[1] * 4
    for i in range(3, n + 1):
        dp[i] = dp[i - 1]
    return dp[n]


print(solve())

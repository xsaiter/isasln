def solve(n: int) -> int:
    dp = [0] * (n + 1)
    dp[1] = 0
    for i in range(2, n + 1):
        x = dp[i - 1] + 1
        if i % 3 == 0:
            x = min(x, dp[i // 3] + 1)
        if i % 2 == 0:
            x = min(x, dp[i // 2] + 1)

        dp[i] = x

    return dp[n]


n = int(input())

print(solve(n))

def solve(n):
    dp = [None] * (n + 1)
    dp[0] = 0
    dp[2] = 10
    for i in range(4, n + 2, 2):
        dp[i] = dp[i - 2] * 10
    return 0


n = int(input())
print(solve(n))

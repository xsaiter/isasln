k, n = map(int, input().split())
n += 1

dp = [0] * n

dp[0] = 1
for i in range(1, n):  
    for j in range(1, min(k, i) + 1):
        dp[i] = dp[i] + dp[i - j]

print(dp[n - 1])


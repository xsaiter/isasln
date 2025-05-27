MOD = 10**6
k = int(input())

dp = [[0] * 4 for _ in range(k + 11)]

dp[10][1] = 2

for h in range(10, k + 1):
    for s in range(1, 4):
        if dp[h][s] == 0:
            continue

        if s < 3 and h + 1 <= k:
            dp[h + 1][s + 1] = (dp[h + 1][s + 1] + dp[h][s]) % MOD

        if h + 10 <= k:
            dp[h + 10][1] = (dp[h + 10][1] + dp[h][s]) % MOD

result = sum(dp[k]) % MOD
print(result)

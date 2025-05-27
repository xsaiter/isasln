from collections import defaultdict

MOD = 10**6
k = int(input())

dp = defaultdict(lambda: [0] * 4)
dp[10][1] = 2

for h in range(10, k + 1):
    for s in range(1, 4):
        val = dp[h][s]
        if val == 0:
            continue
        if s < 3:
            dp[h + 1][s + 1] = (dp[h + 1][s + 1] + val) % MOD
        dp[h + 10][1] = (dp[h + 10][1] + val) % MOD

result = sum(dp[k]) % MOD
print(result)

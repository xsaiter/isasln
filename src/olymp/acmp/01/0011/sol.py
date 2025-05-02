import sys
 
n, k = map(int, input().split())
n += 1

dp = []

print(n)
print(k)

dp[0] = 1
for i in range(n):
    for j in range(k, i):
        dp[i] = dp[i] + dp[i - j]

print(n)


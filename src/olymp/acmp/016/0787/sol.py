n = int(input())

a = list(map(int, input().split()))


def solve():
    ans = 0
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            dp[i] = max(dp[i - 1])
    return ans


print(solve())

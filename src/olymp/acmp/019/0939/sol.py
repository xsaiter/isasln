n = int(input())
w = list(map(int, input().split()))


def solve() -> list[int]:
    s = sum(w)

    if s % 3 != 0:
        return []

    W = s // 3

    dp = [[False for _ in range(W + 1)] for _ in range(n)]

    for j in range(W + 1):
        dp[0][j] = w[0] == j

    for i in range(1, n):
        for j in range(W + 1):
            dp[i][j] = dp[i - 1][j]

            if j >= w[i]:
                dp[i][j] |= dp[i - 1][j - w[i]]

    result = []
    if not dp[n - 1][W]:
        return []

    j = W
    for i in range(n - 1, -1, -1):
        if i > 0 and dp[i][j] != dp[i - 1][j]:
            result.append(i + 1)
            j -= w[i]
        elif i == 0 and dp[i][j]:
            result.append(i + 1)
            break

    return sorted(result)


result = solve()

if result:
    print(len(result))
    print(" ".join(map(str, result)))
else:
    print(0)

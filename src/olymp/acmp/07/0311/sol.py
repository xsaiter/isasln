def solve(n):
    ans = 1
    cur = 1
    for i in range(2, n + 1):
        cur *= i
        ans += cur

    return ans


n = int(input())

print(solve(n))

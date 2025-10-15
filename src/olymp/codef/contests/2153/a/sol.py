def solve(n, b):
    s = set(b)
    a = list(s)
    a.sort()
    n = len(a)
    ans = 0
    cur = 1
    for i in range(1, n):
        if a[i] > a[i - 1]:
            cur += 1
        else:
            ans = max(ans, cur)
            cur = 1
    ans = max(ans, cur)
    return ans


t = int(input())

for _ in range(t):
    n = int(input())
    b = [int(x) for x in input().split()]
    ans = solve(n, b)
    print(ans)

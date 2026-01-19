import bisect


def solve(n, k, a, b):
    ans = 0
    a = sorted(a)
    b = sorted(b)
    c = list(a + b)
    for x in c:
        nb = n - bisect.bisect_left(b, x)
        na = n - (bisect.bisect_left(a, x))
        cnt = nb - na
        if cnt <= k:
            ans = max(ans, x * nb)

    return ans


tt = int(input())

for _ in range(tt):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = solve(n, k, a, b)
    print(ans)

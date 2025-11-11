n, k = map(int, input().split())


def solve():
    j = 1
    r = 0
    ok = False
    while not ok:
        x = j
        r = x * n + k
        ok = True
        for _ in range(n - 1):
            if r % (n - 1) > 0:
                ok = False
                break
            x = r // (n - 1)
            r = x * n + k
        j += 1
    return r


print(solve())

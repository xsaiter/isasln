import math


def dist(x, y):
    return math.sqrt(x**2 + y**2)


def solve(n, q, v):
    for x, y, x2, y2 in v:
        a = dist(x, y)
        b = dist(x2, y2)

        if a == 0:
            if b == 0:
                continue
            return False

        if b > q * a:
            return False

    return True


n, q = map(float, input().split())
n = int(n)
v = [tuple(map(int, input().split())) for _ in range(n)]

res = "Yes" if solve(n, q, v) else "No"

print(res)

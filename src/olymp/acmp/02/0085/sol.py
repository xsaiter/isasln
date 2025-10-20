import math


def gen(n):
    s = "".join(["1" for _ in range(n)])
    return int(s)


n, m = map(int, input().split())
a = gen(n)
b = gen(m)
r = math.gcd(a, b)
print(r)

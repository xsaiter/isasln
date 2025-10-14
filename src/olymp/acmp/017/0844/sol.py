import math


def solve(a, b):
    s = a * b
    x = math.sqrt(s)
    if x.is_integer():
        return int(x)
    return 0


a, b = map(int, input().split())

print(solve(a, b))

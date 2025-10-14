n = int(input())


def solve():
    if n == 0:
        return 1
    return n * n - n + 2


print(solve())

a, b, c = map(int, input().split())


def solve():
    if a < 2 or b < 6:
        return 0

    na = a // 2
    nb = b // 6
    nc = c

    return min(na, nb, nc)


print(solve())

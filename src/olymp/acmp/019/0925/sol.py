k = int(input())

n, a, b, c = map(int, input().split())


def solve():
    if k == 2:
        return min(a, b, c)
    return max(0, a + b + c - 2 * n)


print(solve())

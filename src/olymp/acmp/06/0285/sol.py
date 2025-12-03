n, m = map(int, input().split())
a = list(map(int, input().split()))


def solve():
    if m > sum(a) or m < max(a):
        return False

    a.sort(reverse=True)
    b = []

    b.append(a[0])

    for i in range(1, n):
        b.sort()

        start = b[0] - 1

        if start < 0:
            return False

        b.pop(0)

        b.append(start + a[i])

    b.sort()
    last_b = b[-1]

    if last_b >= m:
        return True
    else:
        return False


ans = solve()

print("yes" if ans else "no")

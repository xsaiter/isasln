def solve(a):
    mi = 20000
    ma = -20000
    for i in range(len(a)):
        if (i + 1) % 2 == 0:
            ma = max(ma, a[i])
        else:
            mi = min(mi, a[i])

    return mi + ma


a = list(map(int, input().split()))

print(solve(a))

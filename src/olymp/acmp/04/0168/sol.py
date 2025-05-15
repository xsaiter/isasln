def solve(n):
    t = str(n)
    s = ""
    for i in range(100000):
        s += str(i)

    pos = s.find(t)

    return pos


n = int(input())

print(solve(n))

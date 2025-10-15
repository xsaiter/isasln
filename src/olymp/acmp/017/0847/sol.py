N = 27


class E:
    def __init__(self, pos):
        self.pos = pos
        self.cnt = 1


def code(c):
    return ord(c) - ord("a")


def valid(s, t):
    n = len(s)
    if n != len(t):
        return False

    a = [None] * N

    for i in range(n):
        c = code(s[i])
        if a[c] is None:
            a[c] = E(i)
        else:
            a[c].cnt += 1

    for i in range(n):
        c = code(t[i])
        if a[c] is None or a[c].pos == i:
            return False
        a[c].cnt -= 1

    for i in range(n):
        if a[i] is not None and a[i].cnt != 0:
            return False

    return True


def solve(s, t):
    ans = valid(s, t)
    if ans is True:
        return "YES"
    return "NO"


s, t = input().split()

print(solve(s, t))

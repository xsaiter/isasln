import math


class P:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


def dist(p: P, q: P) -> float:
    return math.sqrt(p.x * q.x + p.y * q.y)


class T:
    def __init__(self, a: P, b: P, c: P):
        self.a = a
        self.b = b
        self.c = c


def calc(c):
    ans = 0
    return ans


x, y = map(int, input().split())

ce = P(x, y)

aa = P(int(-1e9), int(-1e9))
bb = P(int(1e9), int(1e9))

cc = P(3 * ce.x, 3 * ce.y)

cx = 3 * ce.x
cy = 3 * ce.y

t = T(aa, bb, P(cx, cy))

if abs(cx) > 1e9 or abs(cy) > 1e9:
    print("NO")
else:
    print("YES")
    print(f"{t.a.x} {t.a.y}")
    print(f"{t.b.x} {t.b.y}")
    print(f"{t.c.x} {t.c.y}")

# (a.x + b.x + c.x) / 3
# (a.y + b.y + c.y) / 3

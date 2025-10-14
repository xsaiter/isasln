class P:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Circle:
    def __init__(self, center, r):
        self.center = center
        self.r = r


x, y = map(int, input().split())
meet = P(x, y)

cx, cy, cr = map(int, input().split())
castle = Circle(P(cx, cy), cr)

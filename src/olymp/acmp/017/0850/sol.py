class Seg:
    def __init__(self, a, b):
        self.a = a
        self.b = b


def make_seg(x):
    def ga():
        if x % 2 == 0:
            return x // 2
        return (x + 1) // 2

    def gb():
        return x

    return Seg(ga(), gb())


a, b = map(int, input().split())
p = make_seg(a)
q = make_seg(b)

ma = min(p.b, q.b)
mi = max(p.a, q.a)

print(f"{mi} {ma}")

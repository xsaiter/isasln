class P:
    def __init__(self, x, y):
        self.x = x
        self.y = y


n = int(input())

a = [None] * n

ss = [int(num) for num in input().split()]

for i in range(n):
    a[i] = P(ss[2 * i], ss[2 * i + 1])

b = a

n, m, f, l = map(int, input().split())

a, b, c = 0, 0, 0

x = n - l
if x > min(m, f):
    a = 0
    b = m
    c = f
else:
    y = min(m, f) - x
    a = y
    b = m - y
    c = f - y

print(f"{a} {b} {c}")

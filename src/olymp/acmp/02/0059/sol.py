n, k = map(int, input().split())

a = []

while n > 0:
    r = n % k
    a.append(r)
    n = (n - r) // k

a.reverse()

s = 0
p = 1

for elt in a:
    s += elt
    p *= elt

ans = p - s
print(ans)

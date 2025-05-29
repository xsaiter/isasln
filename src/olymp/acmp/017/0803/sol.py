from decimal import Decimal, getcontext

getcontext().prec = 1000001

a, b, k = map(int, input().split())

r = Decimal(a) / Decimal(b)

s = str(r)

ans = 0

pos = s.find(".")
if pos != -1:
    i = pos + k
    if len(s) > i:
        ans = s[i]

print(ans)

def solve(n, m, a):
    r = 0
    return r


t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = [None] * n
    for i in range(n):
        a[i] = input()
    print(solve(n, m, a))

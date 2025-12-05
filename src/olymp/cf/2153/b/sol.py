def solve(x, y, z):
    return False


t = int(input())

for _ in range(t):
    x, y, z = map(int, input().split())
    ans = solve(x, y, z)
    if ans is True:
        print("YES")
    else:
        print("NO")

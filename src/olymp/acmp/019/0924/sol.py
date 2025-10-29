a: list[str] = [None] * 4

for i in range(4):
    a[i] = input()


def solve():
    for i in range(1, 4):
        for j in range(1, 4):
            if a[i][j] == a[i - 1][j] == a[i][j - 1] == a[i - 1][j - 1]:
                return False

    return True


ans = solve()

if ans:
    print("Yes")
else:
    print("No")

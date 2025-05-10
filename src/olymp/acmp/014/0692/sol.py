n = int(input())


def solve(n):
    if n == 0:
        return False
    if n == 1:
        return True
    if n == 2:
        return True

    while n != 1:
        if n % 2 > 0:
            return False
        n /= 2

    return True


print("YES" if solve(n) else "NO")

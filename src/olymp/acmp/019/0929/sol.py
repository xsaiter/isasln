def opposite_side(n):
    if n == 1:
        return 6
    elif n == 2:
        return 5
    elif n == 3:
        return 4
    elif n == 4:
        return 3
    elif n == 5:
        return 2
    elif n == 6:
        return 1
    elif n == 0:
        return 0
    else:
        raise ("Error")


def get_min(n):
    if n <= 6:
        return opposite_side(n)

    rem = n % 6
    return (n - rem) // 6 + opposite_side(rem)


def get_max(n):
    return n * 6


n = int(input())

l = get_min(n)
r = get_max(n)

print(f"{l} {r}")

s = input()


def solve():
    for c in s:
        if c == "0":
            return "NO"
    return "YES"


print(solve())

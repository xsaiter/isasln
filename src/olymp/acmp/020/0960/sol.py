def solve(s: str) -> int:
    dp_a = 0
    dp_b = 0
    dp_c = 0
    for c in s:
        if c == "a":
            dp_a += 1
        elif c == "b":
            dp_b += dp_a
        elif c == "c":
            dp_c += dp_b
    return dp_c


try:
    s = input()
    print(solve(s))
except EOFError:
    print(0)

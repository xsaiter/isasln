BAD: str = ".,:;-'\"!?"


def conv_s(s: str) -> str:
    v = []
    for c in s:
        if c in BAD:
            v.append(" ")
        else:
            v.append(c.upper())
    return "".join(v)


def read_dict(n: int) -> set[str]:
    a: list[str] = [None] * n
    for i in range(n):
        a[i] = input().upper()

    return set(a)


def read_text(m: int) -> set[str]:
    b: list[str] = [None] * m
    for i in range(m):
        b[i] = input()

    res = set()

    for i in range(m):
        parts = conv_s(b[i]).split()
        for part in parts:
            if part:
                res.add(part)

    return res


n, m = map(int, input().split())

dict: set[str] = read_dict(n)
text: set[str] = read_text(m)


def solve():
    for s in text:
        if s not in dict:
            return "Some words from the text are unknown."

    for word in dict:
        if word not in text:
            return "The usage of the vocabulary is not perfect."

    return "Everything is going to be OK."


print(solve())

import math


def norm2(se, f):
    return se * f


def norm(s):
    fi = 0
    se = 0
    factor = 0
    if "." in s:
        parts = s.split(".")
        parts[1] = parts[1].rstrip("0")
        fi, se = int(parts[0]), int(parts[1])

        if parts[1][0] == "0":
            factor = 0
            for i in range(len(parts[1])):
                if parts[1][i] == "0":
                    factor += 1
                else:
                    break
    else:
        fi = int(s)

    return (fi, se, factor)


def solve(s1, s2):
    fi, se, f = norm(s1)
    fi2, se2, f2 = norm(s2)

    if f != 0 or f2 != 0:
        ff = abs(f2 - f)
        if f2 > f:
            se *= math.pow(10, max(f, ff))
        elif f2 < f:
            se2 *= math.pow(10, max(f, ff))
        else:
            se *= math.pow(10, max(f, ff))
            se2 *= math.pow(10, max(f, ff))

    if fi == fi2:
        if se == se2:
            return "="
        elif se < se2:
            if fi < 0:
                return ">"
            return "<"
        elif fi < 0:
            return "<"
        return ">"
    elif fi < fi2:
        return "<"

    return ">"


s1 = input()
s2 = input()

print(solve(s1, s2))

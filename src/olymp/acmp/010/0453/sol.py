n = int(input())

k = 2**n


def solve():
    step = 2
    ans = [0] * step
    ans[0] = 1
    ans[1] = 2
    while True:
        for x in ans:
            if x % k == 0:
                return x
        buf = []
        for i in range(step, 0, -1):
            buf.append(ans[-i])
        step *= 2
        ans = [0] * step
        c = 0
        for j in buf:
            ans[c] = j * 10 + 1
            ans[c + 1] = j * 10 + 2
            c += 2


print(solve())

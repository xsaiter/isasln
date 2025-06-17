def cc(i):
    return chr(ord("a") + i)


def solve(n):
    s = "a"
    for i in range(1, 26):
        s = cc(i) + s + s

    return s[n - 1]


n = int(input())

ans = solve(n)

print(ans)

# a -> b aa -> c baa baa -> d cbaabaa cbaabaa -> e dcbaabaacbaabaa dcbaabaacbaabaa

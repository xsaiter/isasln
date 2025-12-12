n, m = map(int, input().split())


def conv(x):
    ans = 0
    s = str(x)
    k = len(s)
    for i in range(k):
        ans += (ord(s[i]) - ord("0")) * (3 ** (k - i - 1))
    return ans


print(conv(n) + conv(m))

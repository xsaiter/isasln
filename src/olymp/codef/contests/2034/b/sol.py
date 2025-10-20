def update_s(n, m, k, s, p, q):
    if k < m:
        d = m - k
        delta = q - p + 1 - d
        for i in range(delta):
            j = p + d + i + 1
            if j < n:
                s[j] = "1"
    elif k > m:
        beg = p + m - 1
        for i in range(beg, beg + k):
            j = i
            if j < n:
                s[j] = "1"


def solve(n, m, k, ss):
    s = list(ss)
    ans = 0
    p, q = 0, 0
    is_chunk = False
    for i in range(n):
        if is_chunk is False:
            if s[i] == "0":
                is_chunk = True
                p = i
                q = p
                if q - p + 1 == m:
                    is_chunk = False
                    update_s(n, m, k, s, p, q)
                    ans += 1
        else:
            if s[i] == "0":
                q += 1
                if q - p + 1 == m:
                    is_chunk = False
                    update_s(n, m, k, s, p, q)
                    ans += 1
            else:
                if q - p + 1 == m:
                    update_s(n, m, k, s, p, q)
                    ans += 1
                is_chunk = False

    if is_chunk is True and q - p + 1 == m:
        update_s(n, m, k, s, p, q)
        ans += 1

    return ans


t = int(input())

for _ in range(t):
    n, m, k = map(int, input().split())
    ss = input()
    ans = solve(n, m, k, ss)
    print(f"{ans}")

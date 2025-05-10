def solve(n):
    if n < 4:
        return n

    ans = 1
    rem = n % 3
    if rem == 0:
        ans = pow(3, n / 3)
    else:
        ans = pow(3, (n - rem) / 3)
        if rem == 1:
            ans = ans / 3
            ans *= 4
        elif rem == 2:
            ans *= 2

    return int(ans)


n = int(input())
print(solve(n))

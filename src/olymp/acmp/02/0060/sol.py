def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True


def solve(k):
    j = 0
    nj = 0
    n = 2
    while True:
        if is_prime(n):
            j += 1
            if is_prime(j):
                nj += 1
                if nj == k:
                    return n
        n += 1


k = int(input())
ans = solve(k)
print(ans)

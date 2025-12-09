from functools import lru_cache


@lru_cache(maxsize=None)
def solve(n):
    if n < 3:
        return 0
    if n == 3:
        return 1
    return solve((n + 1) // 2) + solve(n // 2)


n = int(input())
print(solve(n))

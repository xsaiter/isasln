def solve(n):
    if n == 0:
        return "10"
    if n == 1:
        return "1"

    digits = []

    for i in range(9, 1, -1):
        while n % i == 0:
            digits.append(i)
            n //= i

    if n > 1:
        return "-1"

    digits.sort()

    return "".join(map(str, digits))


n = int(input())
result = solve(n)
print(result)

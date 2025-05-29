def convert_to_n(s, k):
    return int(s, k)


k, m = map(int, input().split())

s = input()
n = convert_to_n(s, k)

rem = n % m
print(rem)

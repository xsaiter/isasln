class Person:
    def __init__(self, name):
        self.name = name


s = Person("aaaa")

ss = []

ss.append(s)

s.name = "bbbb"

print(s)
print(ss)

class Person:
    def __init__(self, name):
        self.name = name

    def get_age(self):        
        return 10


s = Person("aaaa")

ss = []

ss.append(s)

s.name = "bbbb"

age = s.get_age()

print(s)
print(ss)

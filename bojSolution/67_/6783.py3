from sys import stdin
def input(): return stdin.readline().rstrip()

tc = 0
sc = 0

for _ in range(int(input())):
    s = input()
    tc += s.count("t") + s.count("T")
    sc += s.count("s") + s.count("S")

print("English" if sc<tc else "French")
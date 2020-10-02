from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    d, m, y = 0, 0, 0
    s = input()
    if "." in s:
        d, m, y = map(int, s.split("."))
    else:
        m, d, y = map(int, s.split("/"))
    print("%02d.%02d.%04d"%(d,m,y), end=" ")
    print("%02d/%02d/%04d"%(m,d,y))
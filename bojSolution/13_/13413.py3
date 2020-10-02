from sys import stdin
def input(): return stdin.readline()

for _ in range(int(input())):
    l, s1, s2 = int(input()), input(), input()
    b, w = 0, 0
    for i in range(l):
        if s1[i] == s2[i]: continue
        if s1[i] == "B": b += 1
        else: w += 1
    print(max(b, w))
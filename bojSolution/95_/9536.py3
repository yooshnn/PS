from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    s=input().split()
    while 1:
        t=input().split()
        if t[1]=="does": break
        s=list(filter(lambda a: a != t[2], s))
    print(" ".join(s))
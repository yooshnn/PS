from sys import stdin
def input(): return stdin.readline().rstrip()
l=[]
for _ in range(int(input())):
    s=input()
    del l[:]
    for i in range(len(s)):
        l.append(s[i:]+s[:i])
    print(sorted(l)[0])
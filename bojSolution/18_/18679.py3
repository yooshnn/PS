from sys import stdin
def input(): return stdin.readline().rstrip()
d={}
for _ in range(int(input())):
    s=input().split()
    d[s[0]]=s[2]
for _ in range(int(input())):
    k=input()
    l=input().split()
    for i in l:
        print(d[i],end=" ")
    print()
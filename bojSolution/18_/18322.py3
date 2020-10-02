from sys import stdin
def input(): return stdin.readline().rstrip()
a,b=map(int,input().split())
s=input().split()
l=0
for i in range(a):
    if l+len(s[i])>b:
        l=0
        print()
    print(s[i],end=" ")
    l+=len(s[i])
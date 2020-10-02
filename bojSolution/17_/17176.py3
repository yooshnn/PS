from sys import stdin
def input(): return stdin.readline().rstrip()

n=int(input())
c=list(map(int,input().split()))
s=input()
h=[]

for i in c:
    if i==0:
        h.append(" ")
    elif i<27:
        h.append(chr(ord('A')+(i-1)))
    else:
        h.append(chr(ord('a')+(i-27)))

print(["n","y"][sorted(s)==sorted(h)])
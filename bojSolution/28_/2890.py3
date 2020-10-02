from sys import stdin
def input(): return stdin.readline().rstrip()
d={}
res=[0]*10

r,c=map(int,input().split())
for i in range(r):
    s=input()
    if s.count('.')!=r-2:
        for j in range(1,c):
            if s[j]!='.' and s[j]!='F':
                d[int(s[j])]=j

standing=0
while max(d.values())!=0:
    standing+=1
    m=max(d.values())
    for i in range(1,10):
        if d[i]==m:
            res[i]=standing
            d[i]=0

print(*res[1:],sep='\n')

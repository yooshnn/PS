from sys import stdin

def input():
    return stdin.readline()

N=int(input())
M=int(input())
b=set(map(int,input().split()))
z=0
a=abs(N-100)
res=a
for i in range(999901):
    temp=abs(N-i)
    if temp>=res: continue
    isvalid=True
    for elem in b:
        if str(i).find(str(elem))!=-1:
            isvalid=False
            break
    if not isvalid: continue
    res=temp
    z=len(str(i))

print(min(a,res+z))

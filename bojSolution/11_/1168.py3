from sys import stdin
def input(): return stdin.readline().rstrip()

N,M=map(int,input().split())
li=[x for x in range(1,N+1)]
res="<"
id=0

for i in range(N-1):
    id+=M-1
    if id>=len(li):
        if len(li)>0:
            id%=len(li)
        else:
            id=0
    res+=str(li.pop(id))+", "

res+=str(li[0])+">"
print(res)
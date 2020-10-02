from sys import stdin,setrecursionlimit
def input(): return stdin.readline().rstrip()

setrecursionlimit(1000000)

def dfs(max_depth,depth,ind,cursum):
    ret=0
    if depth==max_depth:
        return int(cursum==s)
    for i in range(ind+1,n):
        ret+=dfs(max_depth,depth+1,i,cursum+li[i])
    return ret

n,s=map(int,input().split())
li=list(map(int,input().split()))
res=0
for i in range(1,n+1):
    for j in range(n):
        if i+j>n: continue
        res+=dfs(i,1,j,li[j])
print(res)
from sys import stdin
def input(): return stdin.readline().rstrip()

def dfs(depth, t):
    ret=0
    if depth==N:
        if t%3==0:
            return 1
        else:
            return 0
    else:
        ret+=dfs(depth+1, int(str(t)+"0"))
        ret+=dfs(depth+1, int(str(t)+"1"))
        ret+=dfs(depth+1, int(str(t)+"2"))
    return ret

N=int(input())
C=0
C+=dfs(1,1)
C+=dfs(1,2)
print(C)
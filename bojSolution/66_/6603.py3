from sys import stdin

lottery=[0]*6

def dfs(ind,depth):
    if depth==6:
        print(*lottery)
        return
    for i in range(ind,sz):
        lottery[depth]=s[i]
        dfs(i+1,depth+1)


while True:
    s=list(map(int,stdin.readline().split()))
    if s[0]==0:
        break
    sz=s[0]
    del s[0]
    dfs(0,0)
    print()

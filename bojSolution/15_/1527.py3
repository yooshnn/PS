from sys import stdin

def solve(n):
    ret=0
    if n>=l and n<=h:
        ret+=1
    elif n>h:
        return 0
    ret+=solve(n*10+4)
    ret+=solve(n*10+7)
    return ret

l,h=map(int,stdin.readline().split())
print(solve(0))

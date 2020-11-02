import sys
input = sys.stdin.readline

def solve(m, a, b):
    x = a//(5**(m-1))
    y = b//(5**(m-1))
    if (0<x<4 and y==0) or (x==2 and y==1):
        return True
    if ((x==1 or x==3) and y==1) or (x==2 and y==2):
        return solve(m-1, a%(5**(m-1)), b%(5**(m-1)))
    return False

for _ in range(int(input())):
    m, a, b = map(int, input().split())
    print("crystal" if solve(m, a, b) else "empty")

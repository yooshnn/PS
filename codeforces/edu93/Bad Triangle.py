from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    L=int(input())
    s=list(map(int,input().split()))
    if s[0]+s[1]>s[-1]:
        print(-1)
    else:
        print(1,2,L)
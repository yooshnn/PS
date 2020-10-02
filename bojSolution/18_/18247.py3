from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    N,M=map(int,input().split())
    if N<12 or M<4:
        print(-1)
        continue
    else:
        print(11*M+4)
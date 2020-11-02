import sys
import math
input = sys.stdin.readline
sqrt = math.sqrt

def cntDevisor(n):
    ret = 0
    for i in range(1, n+1):
        if n%i == 0: ret += 1
    return ret

n, k = map(int, input().split())

for i in range(n):
    for j in range(n):
        print("*" if cntDevisor(1+i*n+j) <= k else ".", end="")
    print()

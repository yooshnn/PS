from itertools import permutations
from sys import stdin
def input(): return stdin.readline().rstrip()

n,m=map(int,input().split())
s=permutations(sorted(map(int,input().split())),m)
for i in s:
    print(*i)
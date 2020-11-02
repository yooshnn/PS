import sys
import itertools
input = sys.stdin.readline

for i in range(int(input())):
    print("Case # %d:"%(i+1))
    s = itertools.permutations(input().rstrip())
    for c in s:
        print(*c, sep="")
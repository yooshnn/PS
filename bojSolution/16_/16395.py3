import sys
import math
input = sys.stdin.readline
comb = math.comb

n, k = map(int, input().split())
print(comb(n-1, k-1))
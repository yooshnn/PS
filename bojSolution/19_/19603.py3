from sys import stdin
def input(): return int(stdin.readline().rstrip())

P = input()
N = input()
R = input()
b = N
res = 0

while N <= P:
    oldN = N
    N += b * R
    b = N-oldN
    res += 1

print(res)
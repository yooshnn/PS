from sys import stdin
def input(): return stdin.readline().rstrip()

n, t = map(int, input().split())
t %= n * 4 - 2

if t==0:
    print(2)
elif t<2*n:
    print(t)
else:
    print(2*n - (t-2*n))
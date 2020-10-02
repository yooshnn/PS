from sys import stdin
def input(): return stdin.readline().rstrip()

n = input()
s = sorted(map(int, input().split()))
f = sum(s)
r = 0

for c in s:
    r += c * (f-c)
    f -= c

print(r)
from sys import stdin
def input(): return stdin.readline().rstrip()

n = int(input())
s = sorted(map(int, input().split()))
r = 0
for c in s:
    r += c if c%2==1 else c-1
print(r if r%2==1 else r - (s[0] if s[0]%2==1 else s[0]-1))

import sys; input = sys.stdin.readline
import collections

st = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]

a, b = input().rstrip(), input().rstrip()
s = collections.deque()

for i in range(len(a)):
    s.append(st[ord(a[i])-ord('A')])
    s.append(st[ord(b[i])-ord('A')])

while len(s)>2:
    for i in range(len(s)-1):
        s.append((s[0] + s[1])%10)
        s.popleft()
    s.popleft()

print("%d%d"%(s[0], s[1]))

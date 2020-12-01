import sys
import collections
input = sys.stdin.readline
deque = collections.deque

o = []
res = []
s = deque()

N = int(input())
for _ in range(N):
    o.append(int(input()))

i, c = 0, 1
for _ in range(N*2):
    if len(s)>0 and o[i]==s[0]:
        s.popleft(); i += 1
        res.append("-")
    else:
        s.appendleft(c); c += 1
        res.append("+")

if i==N and c==N+1 and len(s)==0:
    print("\n".join(res))
else:
    print("NO")
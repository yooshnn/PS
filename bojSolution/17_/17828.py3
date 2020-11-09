import sys
import collections
input = sys.stdin.readline
deque = collections.deque

n, v = map(int, input().split())
cnt, c = 0, 0
r = deque()

while cnt<n:
    if c+(n-cnt) == v:
        r.appendleft("A")
        c += 1
    else:
        a = min(26, 1+v-(c+(n-cnt)))-1
        if a<0:
            break
        else:
            r.appendleft(chr(ord('A')+a))
            c += a+1
    cnt += 1

if c == v:
    print("".join(r))
else:
    print("!")
from collections import deque
from sys import stdin
def input(): return int(stdin.readline().rstrip())
s=deque(i+1 for i in range(input()))
while s:
    print(s.popleft(),end=" ")
    if s:
        t=s.popleft()
        s.append(t)
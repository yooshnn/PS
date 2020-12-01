import sys
import collections
input = sys.stdin.readline
deque = collections.deque

que = deque()

for _ in range(int(input())):
    s = input().split()
    if s[0]=="push":
        que.append(s[1])
    elif s[0]=="pop":
        if que: print(que.popleft())
        else: print(-1)
    elif s[0]=="size":
        print(len(que))
    elif s[0]=="empty":
        print("01"[len(que)==0])
    elif s[0]=="front":
        if que: print(que[0])
        else: print(-1)
    else:
        if que: print(que[-1])
        else: print(-1)
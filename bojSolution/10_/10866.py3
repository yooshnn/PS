import sys
import collections
input = sys.stdin.readline
deque = collections.deque

que = deque()
for TEST in range(int(input())):
    s = input().split()
    if s[0]=="push_front": que.appendleft(s[1])
    if s[0]=="push_back": que.append(s[1])
    if s[0]=="pop_front": print(que.popleft() if que else -1)
    if s[0]=="pop_back": print(que.pop() if que else -1)
    if s[0]=="size": print(len(que))
    if s[0]=="empty": print(0 if que else 1)
    if s[0]=="front": print(que[0] if que else -1)
    if s[0]=="back": print(que[-1] if que else -1)
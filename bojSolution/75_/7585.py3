from sys import stdin
from collections import deque
def input(): return stdin.readline().rstrip()

while 1:
    legal = True
    l_ = input()
    if l_ == "#": break
    l = deque(l_)
    s = deque()

    while len(l) > 0:
        t = l.popleft()
        if t=="(":
            s.append("(")
        elif t==")":
            if s.pop() != "(":
                legal = False
                break
        elif t=="{":
            s.append("{")
        elif t=="}":
            if s.pop() != "{":
                legal = False
                break
        elif t=="[":
            s.append("[")
        elif t=="]":
            if s.pop() != "[":
                legal = False
                break

    if legal and not s:
        print("Legal")
    else:
        print("Illegal")
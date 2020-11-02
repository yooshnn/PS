import sys
from collections import deque
input = sys.stdin.readline

inst = list()
stk = deque()
reg = 0

for _ in range(int(input())):
    inst.append(input().rstrip())

cmd = 0
while 1:
    if inst[cmd].split()[0] == "PUSH":
        stk.append(int(inst[cmd].split()[1]))
    elif inst[cmd].split()[0] == "STORE":
        reg = stk.pop()
    elif inst[cmd].split()[0] == "LOAD":
        stk.append(reg)
    elif inst[cmd].split()[0] == "PLUS":
        stk.append(stk.pop() + stk.pop())
    elif inst[cmd].split()[0] == "TIMES":
        stk.append(stk.pop() * stk.pop())
    elif inst[cmd].split()[0] == "IFZERO":
        if stk.pop() == 0: cmd = int(inst[cmd].split()[1]) - 1
    elif inst[cmd].split()[0] == "DONE":
        print(stk.pop())
        break
    cmd += 1

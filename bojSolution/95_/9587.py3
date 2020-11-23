import sys
import collections
input = sys.stdin.readline
deque = collections.deque

msg = dict()
par, chain = [-1 for i in range(50001)], [0 for i in range(50001)]

last, maxChain = 0, 0

for LINES in range(int(input())):
    line = input().split()
    handle = line[0][:-1]

    try: msg[handle] = msg[handle]
    except: msg[handle] = [LINES, 1] # id, conversation

    for i, c in enumerate(line):
        if i==0: continue
        if c[0]=="@":
            if c==handle: continue
            try:
                if msg[c][1]+1 > chain[LINES]:
                    chain[LINES] = msg[c][1]+1
                    par[LINES] = msg[c][0]
            except: pass
    if chain[LINES] > msg[handle][1]:
        msg[handle] = [LINES, chain[LINES]]
    if chain[LINES] > maxChain:
        maxChain = chain[LINES]
        last = LINES

res = deque()
while 1:
    res.appendleft(last+1)
    if par[last]==-1: break
    last = par[last]

print(len(res))
print(*res)
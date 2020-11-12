import sys
input = sys.stdin.readline

vote = [0 for i in range(101)]

n = int(input())
s = [*map(int, input().split())]

cMax = -1
cId = -1

for c in s:
    if c==0:
        continue
    vote[c] += 1
    
    if vote[c]>cMax:
        cMax = vote[c]
        cId = c
    elif vote[c]==cMax:
        cId = -1

print(cId if cId>0 else "skipped")

import sys; input = sys.stdin.readline

pos = 0
res = 5

n = int(input())
for c in input().rstrip():
    if c=="W":
        pos += 1
        if pos==3: break
    else:
        if pos==0:
            res = 1 if res==5 else 5
        elif pos==1:
            res = 6

print(0 if pos<2 else res)
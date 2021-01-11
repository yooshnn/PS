import sys; input = sys.stdin.readline

N = int(input())

cur = -1
x, y = -1, -1
res = []

for i in range(N):
    s = input().rstrip()
    if cur==-1:
        if s.count("*")==1:
            cur = 0
            y = i+1
            x = s.index("*")
    elif cur==0:
        armlen = s.count("*")
        res.append(x-s.index("*"))
        res.append(armlen-(res[-1]+1))
        cur = 1
        res.append(0)
    elif cur==1:
        if s.count("*")==1:
            res[-1] += 1
        else:
            cur = 2
            res.append(1)
            res.append(1)
    else:
        if s.count("*")==2:
            res[-2] += 1
            res[-1] += 1
        elif s.count("*")==1:
            if s.index("*")<x:
                res[-2]+=1
            else:
                res[-1]+=1

print(y+1, x+1)
print(*res)

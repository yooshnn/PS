import sys
input = sys.stdin.readline

res = []
twint = []
l = []

for lines in range(int(input())):
    s = input().split()
    twint.extend(s[:-1])
    l.extend(len(t) for t in s[:-1])

lp, rp = 1, 2500
found = -1
while lp+1<rp:
    mid = (lp + rp)//2
    cnt, curtwint = 0, 0
    for i in l:
        if curtwint+(curtwint!=0)+i+4+len(str(mid)+str(cnt+1))<=280:
            curtwint += i+(curtwint!=0)
        else:
            cnt += 1
            curtwint = i
    if curtwint!=0: cnt+=1
    if cnt>mid: lp = mid
    elif cnt<mid: rp = mid
    else:
        found = mid
        rp = mid

cnt, curtwint = 0, 0
temp = []
for t, i in enumerate(l):
    if curtwint+(curtwint!=0)+i+4+len(str(mid)+str(cnt+1))<=280:
        if curtwint!=0: curtwint += 1
        curtwint += i
        temp.append(twint[t])
    else:
        res.append(" ".join(temp))
        temp = [twint[t]]
        cnt += 1
        curtwint = i
if temp:
    res.append(" ".join(temp))

print(len(res))
for i, r in enumerate(res):
    print(r+" (%d/%d)"%(i+1,len(res)))

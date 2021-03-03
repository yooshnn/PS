import sys; input = sys.stdin.readline

s = input().rstrip()
lp, rp = 0, len(s)//2
s += s

res = 0
for i in range(rp):
    if s[i]=="B": res += 1

cnt = res
rp -= 1
while 1:
    if s[lp]=="B": cnt -= 1
    lp += 1
    rp += 1
    if rp>=len(s): break
    if s[rp]=="B": cnt += 1
    res = max(res, cnt)

print(res)
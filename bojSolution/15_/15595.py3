from sys import stdin
def input(): return stdin.readline()

d = {}

T = int(input())
for _ in range(T):
    s = input().split()
    if s[1] == "megalusion": continue
    if s[1] not in d: d[s[1]] = -1
    if d[s[1]] >= 0: continue
    if s[2] == "4":
        d[s[1]] *= -1
        d[s[1]] -= 1
    else:
        d[s[1]] -= 1

cc = 0
wc = 0
for key in d:
    if d[key] >= 0: cc += 1
    wc += d[key] if d[key]>=0 else 0

if cc==0: print(0)
else: print(cc/(cc+wc)*100)
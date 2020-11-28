import sys
input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
r = 0
o = 0

for c in s:
    if c==1: o += 1
    r ^= c
    #print(r)
r = (r!=0)

if o==len(s):
    r = 1-r

print(["cubelover", "koosaga"][r])
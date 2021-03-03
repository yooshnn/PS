import sys; input = sys.stdin.readline

t = set([i for i in "bcdfghjklmnpqrstvwxz"])
s = input().rstrip()

print(s[0], end="")
if len(s)==1: sys.exit(0)

print(s[1], end="")
for i in range(2, len(s)):
    if s[i] in t and s[i-2]==s[i-1]==s[i]: pass
    else: print(s[i], end="")

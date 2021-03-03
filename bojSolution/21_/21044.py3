import sys;

s = "#" + input().rstrip() + "#"
l = 0
t = 0

for c in s:
    if c=="a": t += 1
    else:
        l = max(l, t)
        t = 0

print("a"*(l+1))
import sys; input = sys.stdin.readline

s, n = input().split()
s = s.upper()
n = int(n)

for i in range(26):
    for j in range(26):
        if i==j: continue
        s = s.replace(chr(ord("A")+i) + chr(ord("A")+j), chr(ord("A")+i) + "_" + chr(ord("A")+j))

s = s.split("_")
dup = [False for i in range(26)]

for c in s:
    if dup[ord(c[0]) - ord("A")]: continue
    print(1 if len(c)>=n else 0, end="")
    dup[ord(c[0]) - ord("A")] = True
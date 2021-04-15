import sys; input = sys.stdin.readline

s = []
for w in input().split():
    if all(True if ((not('a'<=c<='z' or 'A'<=c<='Z' or '0'<=c<='9')) or c in "um") else False for c in w):
        for c in w:
            if c not in "um": continue
            if len(s)==0 or len(s[len(s)-1])==7: s.append("")
            s[len(s)-1] += "1" if c=="u" else "0"

for c in s:
    print(chr(int(c, 2)), end="")

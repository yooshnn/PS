import sys
input = sys.stdin.readline

while 1:
    res = 0
    s = input().rstrip()
    if s=="#": break

    res = 0
    for i, c in enumerate(s):
        if c==" ": continue
        res += (i+1)*(ord(c)-ord("A")+1)
    print(res)
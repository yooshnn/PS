import sys
input = sys.stdin.readline

while 1:
    res = 0
    s = input().rstrip()
    if s=="#": break

    for i, c in enumerate(s):
        if c==".":
            res += 1
        if c=="/":
            t = i-1
            while t>=0 and s[t]=="_":
                t -= 1
            res += [0, 1][t<0 or s[t]=="."]
        if c=="\\":
            t = i+1
            while t<len(s) and s[t]=="_":
                t += 1
            res += [0, 1][t>=len(s) or s[t]=="."]
        if c=="|":
            t = i-1
            while t>=0 and s[t]=="_":
                t -= 1
            res += [0, 0.5][t<0 or s[t]=="."]
            t = i+1
            while t<len(s) and s[t]=="_":
                t += 1
            res += [0, 0.5][t>=len(s) or s[t]=="."]

    print(int(100*res/(len(s))))
import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().rstrip()[::-1]
    r = [s[0]]
    for i, c in enumerate(s):
        if i==0: continue
        if c>s[i-1]: r.append(c)
        else: break
    print("The longest decreasing suffix of %s is %s"%(s[::-1],"".join(r)[::-1]))
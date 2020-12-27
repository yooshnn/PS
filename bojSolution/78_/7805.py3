import sys; input = sys.stdin.readline

while 1:
    s = input().rstrip()
    if not s: break
    s = list(s)
    t = sorted(s)

    res = 0
    #dup = [0 for x in range(len(s))]
    for i in range(len(s)):
        #if dup[i]: continue
        if s[i]!=t[i]:
            res += 1
            for j in range(len(s)):
                if s[j]==t[i]:
                    #dup[j] = 1
                    temp = s[i]
                    s[i] = t[i]
                    s[j] = temp
        #print(s)
    print(res)

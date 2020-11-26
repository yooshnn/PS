import sys
input = sys.stdin.readline

while 1:
    res = 0
    s = input().rstrip()
    if s=="*": break

    if len(s)<=2:
        print(s,"is surprising.")
    else:
        good = True
        for i in range(1, len(s)):
            dup = set()
            cnt = 0
            for j in range(len(s)-i):
                dup.add(s[j] + s[j+i])
                cnt += 1
            if cnt!=len(dup):
                good = False
        print(s,"is surprising." if good else "is NOT surprising.")
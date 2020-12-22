import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    a, b = input().rstrip(), input().rstrip()
    r = 0
    d = [0 for x in range(26)]
    for c in a:
        d[ord(c)-ord('a')] += 1
    for c in b:
        if d[ord(c)-ord('a')]:
            d[ord(c)-ord('a')] -= 1
        else:
            r += 1
    for i in d:
        if i>0:
            r += i
    print("Case #%d: %d"%(TEST+1, r))
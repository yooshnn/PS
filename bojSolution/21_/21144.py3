import sys; input = sys.stdin.readline

n = int(input())
s = input().rstrip()
c, p = 1, 0

while 1:
    try:
        if int(s[p:p+len(str(c))])!=c:
            print(c)
            break
        p += len(str(c))
        c += 1
    except:
        print(n)
        break
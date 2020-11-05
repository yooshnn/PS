import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().rstrip()
    cnt = 0
    while 1:
        if s=="6174": break
        t = "".join(sorted(s, reverse=True))
        s = str(int(t) - int("".join(t[::-1])))
        cnt += 1
        if len(s) < 1000:
            while len(s)!=4:
                s = "0"+s
    print(cnt)

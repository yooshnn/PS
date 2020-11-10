import sys
input = sys.stdin.readline
res = 0

for _ in range(int(input())):
    s = sorted([*map(int, input().split())])
    if min(s)==max(s):
        res = max(res, 50000+s[0]*5000)
    elif (s[0]==s[1] and s[1]==s[2]) or (s[1]==s[2] and s[2]==s[3]):
        res = max(res, 10000+s[1]*1000)
    elif (s[0]==s[1]) and (s[2]==s[3]):
        res = max(res, 2000+s[0]*500+s[3]*500)
    elif (s[0]==s[1]):
        res = max(res, 1000+s[0]*100)
    elif (s[1]==s[2]):
        res = max(res, 1000+s[1]*100)
    elif (s[2]==s[3]):
        res = max(res, 1000+s[2]*100)
    else:
        res = max(res, max(s)*100)

print(res)

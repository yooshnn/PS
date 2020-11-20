import sys
input = sys.stdin.readline

d = dict()
n = int(input())
for i in range(n):
    s = input().split()
    for c in s[1:]:
        d[c.upper()] = s[0]
input()
while 1:
    line = input()
    if not line: break
    for c in line.replace(",", " ").replace(".", " ").replace("!", " ").replace(";", " ").replace("?", " ").replace("(", " ").replace(")", " ").upper().split():
        try:
            print(d[c])
            break
        except:
            pass
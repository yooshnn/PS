import sys; input=sys.stdin.readline

n = int(input())
s = input().split()
r = s[0][0]
flag = True
for i in range(1, n):
    if s[i][0]!=r:
        flag = False
print(1 if flag else 0)

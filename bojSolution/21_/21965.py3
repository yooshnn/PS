import sys; input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]

if n<3:
    print("YES")
    sys.exit(0)

state = 0
for i in range(n-1):
    if state==0:
        if s[i]==s[i+1]: state = -1
        elif s[i]>s[i+1]: state = 1
    elif state==1:
        if s[i]<=s[i+1]: state = -1

if state==-1: print("NO")
else: print("YES")
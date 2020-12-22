import sys; input = sys.stdin.readline

n = int(input())
s = "@" + input().rstrip()
B, R = 1, 1

for i in range(1, n+1):
    if s[i]!=s[i-1]:
        if s[i]=="B": B+=1
        else: R+=1

print(min(B,R))
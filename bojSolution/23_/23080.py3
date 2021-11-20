import sys; input = sys.stdin.readline

k = int(input())
s = input().rstrip()

for i in range(len(s)):
    if i%k==0: print(s[i], end="")
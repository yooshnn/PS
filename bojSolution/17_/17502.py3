import sys
input = sys.stdin.readline

n = int(input())
s = list(input().rstrip())

for i in range(n//2):
    if s[i] == "?":
        s[i] = s[n-1-i]
    if s[n-1-i] == "?":
        s[n-1-i] = s[i]
print("".join(s).replace("?","c"))

import sys; input = sys.stdin.readline

s = "#" + input().rstrip()
for i in range(1, len(s)):
    if s[i]!=s[i-1]: print(s[i], end="")
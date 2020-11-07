import sys
input = sys.stdin.readline

s = input().rstrip()
res = True
for i in range(len(s)//2):
    if s[i] != s[len(s)-1-i]:
        res = False
print("YES" if res else "NO")
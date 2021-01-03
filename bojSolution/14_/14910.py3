import sys; input = sys.stdin.readline

s = [*map(int, input().split())]
good = True
for i in range(1, len(s)):
    if s[i-1]>s[i]:
        good = False
print("Good" if good else "Bad")

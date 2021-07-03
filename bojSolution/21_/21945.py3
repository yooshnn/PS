import sys; input = sys.stdin.readline

input()
s = input().split()
res = 0

for c in s:
    good = True
    for i in range(len(c)//2):
        if c[i]!=c[len(c)-1-i]:
            good = False
            break
    if good: res += int(c)

print(res)
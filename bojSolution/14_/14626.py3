import sys; input = sys.stdin.readline

s = input().rstrip()

f = 0
f0 = 0
u = 0

for i in range(len(s)):
    f = 1-f
    if s[i]=="*":
        f0 = f
        continue
    u += int(s[i])*(1 if f else 3)

for i in range(10):
    if (u+i*(1 if f0 else 3))%10 == 0:
        print(i)
        sys.exit(0)

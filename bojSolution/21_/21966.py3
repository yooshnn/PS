import sys; input = sys.stdin.readline

n = int(input())
s = input().rstrip()

n = len(s)

f = [0 for i in range(n)]


if n<=25:
    print(s)
    sys.exit(0)

for i in range(1, n):
    if s[i-1]==".": f[i] = f[i-1] + 1
    else: f[i] = f[i-1]

if all(f[i]==f[11] for i in range(11, n-11)):
    print(s[:11] + "..." + s[-11:])
else:
    print(s[:9] + "......" + s[-10:])
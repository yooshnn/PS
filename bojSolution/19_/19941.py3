import sys; input = sys.stdin.readline

n, k = map(int, input().split())
s = input().rstrip()
dup = [0 if i=="H" else 1 for i in s]
res = 0

for i, c in enumerate(s):
    if c=="H": continue
    for r in range(max(0, i-k), min(n, i+k+1)):
        if dup[r]: continue
        res += 1
        dup[r] = True
        break

print(res)

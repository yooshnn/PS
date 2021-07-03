import sys; input = sys.stdin.readline

orig = input().rstrip()
n = len(orig)
sfxset = []
sfx = []

for i in range(n):
    sfxset.append(orig[i:])
sfxset.sort()
for i in sfxset:
    sfx.append(n-len(i))

s = [-1 for i in range(n+1)]
for i in range(n):
    s[sfx[i]] = i

res = ['\0' for i in range(n)]
res[sfx[0]] = 'a'
cur = 0

for i in range(1, n):
    if s[sfx[i-1]+1] > s[sfx[i]+1]:
        cur += 1
    res[sfx[i]] = chr(ord('a')+cur)
res = "".join(res)

print(1 if res<orig else 0)
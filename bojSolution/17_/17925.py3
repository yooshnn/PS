import sys; input = sys.stdin.readline

N = int(input())
cat = ["" for _ in range(N)]
cnt = [0 for _ in range(N)]
tar = [set() for _ in range(N)]

for i in range(N):
    cat[i], _, *tars = input().split()
    for t in tars: tar[i].add(t)

while 1:
    line = input()
    if not line: break
    for c in line.rstrip().split():
        for i in range(N):
            if c in tar[i]:
                cnt[i] += 1

M = max(cnt)
res = []
for i, c in enumerate(cat):
    if cnt[i]==M: res.append(c)

print(*sorted(res), sep="\n")

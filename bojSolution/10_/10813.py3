import sys; input=sys.stdin.readline

n, m = map(int, input().split())
s = [x for x in range(1, n+1)]

for _ in range(m):
    p, q = map(int, input().split())
    p -= 1; q -= 1;
    if p==q: continue
    s[p]^=s[q]; s[q]^=s[p]; s[p]^=s[q]

print(*s)
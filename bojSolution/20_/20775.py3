import sys; input = sys.stdin.readline

def check(a, b):
    global N
    found = True
    # 0'
    for r in range(N):
        for c in range(N):
            if a[r][c]!=b[r][c]: found = False
    if found: return True
    found = True
    # 90'
    for r in range(N):
        for c in range(N):
            if a[r][c]!=b[c][N-r-1]: found = False
    if found: return True
    found = True
    # 180'
    for r in range(N):
        for c in range(N):
            if a[r][c]!=b[N-r-1][N-c-1]: found = False
    if found: return True
    found = True
    # 270'
    for r in range(N):
        for c in range(N):
            if a[r][c]!=b[N-c-1][r]: found = False
    if found: return True
    return False


N = int(input())

src, tar = [], []
tmp = []

for _ in range(N): src.append(input().rstrip())
input()
for _ in range(N): tar.append(input().rstrip())

# O
if check(src, tar):
    print("YES")
    sys.exit(0)
# H
tmp = [i[::-1] for i in tar]
if check(src, tmp):
    print("YES")
    sys.exit(0)
# V
tmp = [tar[N-i-1] for i in range(N)]
if check(src, tmp):
    print("YES")
    sys.exit(0)
# HV
tmp = [tar[N-i-1][::-1] for i in range(N)]
if check(src, tmp):
    print("YES")
    sys.exit(0)
print("NO")
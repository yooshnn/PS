import sys; input = sys.stdin.readline

n, k = int(input()), int(input())

mat = [[0 for c in range(n)] for r in range(n)]
mat[n//2][n//2] = 1
r, c = n//2-1, n//2
a, b = n//2, n//2
cur = 2

def pf(i, j):
    global mat
    try: return mat[i][j]==0
    except: return True

while 0<=r and 0<=c and r<n and c<n:
    mat[r][c] = cur
    if cur==k: a, b = r, c
    cur += 1
    if not pf(r+1, c):
        if pf(r, c+1): c += 1
        else: r -= 1
    elif not pf(r-1, c):
        if pf(r, c-1): c -= 1
        else: r += 1
    else:
        if pf(r, c+1): r += 1
        else: r -= 1

for row in mat:
    print(*row)
print(a+1, b+1)

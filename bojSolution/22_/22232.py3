import sys; input = sys.stdin.readline

N, M = map(int, input().split())
files = [input().rstrip().split(".") for i in range(N)]
ext = set([input().rstrip() for i in range(M)])

files.sort(key=lambda x : (x[0], 0 if x[1] in ext else 1, x[1]))
for f in files: print(f[0], f[1], sep=".")
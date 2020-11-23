import sys
input = sys.stdin.readline

N, K = map(int, input().split())
b = []
for r in range(N):
    b.append([*map(int, input().split())])

for i in range(N):
    for j in range(K):
        for k in range(N):
            for l in range(K):
                print(b[i][k], end=" ")
        print()
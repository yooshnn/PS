import sys
input = sys.stdin.readline

N, R, C = map(int, input().split())

for r in range(N):
    for c in range(N):
        print("v" if (r+c)%2 == (R+C)%2 else ".", end="")
    print()
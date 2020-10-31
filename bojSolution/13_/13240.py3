import sys
input = sys.stdin.readline

R, C = map(int, input().split())

for r in range(R):
    for c in range(C):
        print("*" if (r+c)%2 == 0 else ".", end="")
    print()
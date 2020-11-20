import sys
input = sys.stdin.readline

T = int(input())
for TEST in range(T):
    n, m = int(input()), int(input())
    print(*divmod(n, m), sep="\n")
    if TEST != T-1: print()
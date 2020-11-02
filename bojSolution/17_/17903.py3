import sys
input = sys.stdin.readline

m, n = map(int, input().split())
print("unsatisfactory" if m<8 else "satisfactory")
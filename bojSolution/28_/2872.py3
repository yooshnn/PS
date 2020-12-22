import sys; input = sys.stdin.readline

N = int(input())
s = [int(input()) for x in range(N)]

for i in range(N-1, -1, -1):
    if s[i]==N:
        N -= 1
print(N)
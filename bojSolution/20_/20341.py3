import sys; input = sys.stdin.readline

n = int(input())
s = [[*map(int, input().split())] for i in range(3)]
for i in range(n):
    print(sorted([s[0][i], s[1][i], s[2][i]])[1], end=" ")

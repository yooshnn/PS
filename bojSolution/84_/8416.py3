from sys import stdin
d = [[0],[1],[6,2,4,8],[1,3,9,7],[6,4],[5],[6],[1,7,9,3],[6,8,4,2],[1,9]]
a,b=map(int,stdin.readline().split())
print(d[a%10][b%len(d[a%10])])

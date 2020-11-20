import sys
input = sys.stdin.readline

data = {}

for TEST in range(int(input())):
    name, d, m, y = input().split()
    if int(d)<10: d = '0'+d
    if int(m)<10: m = '0'+m
    data[y+m+d] = name

s = sorted(data.keys())

print(data[s[-1]], data[s[0]], sep="\n")
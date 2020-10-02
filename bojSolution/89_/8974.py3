from sys import stdin
input: () = lambda: stdin.readline().strip()

li = []
for i in range(46):
    for j in range(i):
        li.append(i)

a, b = map(int, input().split())
print(sum(li[a-1:b]))
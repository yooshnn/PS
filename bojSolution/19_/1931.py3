from sys import stdin
input = stdin.readline

li = []
for _ in range(int(input())):
    a, b = map(int, input().split())
    li.append((a, b))

li = sorted(li, key=lambda t: t[0])
li = sorted(li, key=lambda t: t[1])

res = 0
latest = li[0][0]

for i in li:
    if i[0] >= latest:
        res += 1
        latest = i[1]
print(res)
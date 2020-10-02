from sys import stdin

li = []
for i in range(7):
    s = int(stdin.readline())
    if (s%2 == 1):
        li.append(s)
if li == []:
    print(-1)
else:
    print(sum(li))
    print(min(li))
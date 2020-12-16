import sys
input = sys.stdin.readline

li = []

for TEST in range(int(input())):
    a, b = input().split()
    li.append([1000000001 - int(b), a])

li.sort()
print(li[0][1])
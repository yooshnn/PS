import sys; input = sys.stdin.readline

n = int(input())
li = []

for i in range(n):
    name, kor, eng, math = input().split()
    li.append([-int(kor), int(eng), -int(math), name])

li.sort()

for i in li:
    print(i[3])
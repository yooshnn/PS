import sys; input = sys.stdin.readline

n = int(input())
li = [i for i in range(1, n+1)]

while len(li)!=1:
    temp = [li[i] for i in range(1, len(li), 2)]
    li = temp

print(li[0])
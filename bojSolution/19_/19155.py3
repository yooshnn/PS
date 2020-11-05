from sys import stdin
def input(): return stdin.readline().rstrip()

input()
p = [*map(int, input().split())]
pm = max(p)

for i in p:
    print(pm+1-i, end=" ")
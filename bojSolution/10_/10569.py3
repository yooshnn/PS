from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    v, e = map(int, input().split())
    print(2 - v + e)
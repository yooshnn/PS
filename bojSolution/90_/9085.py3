from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    input()
    print(sum(list(map(int,input().split()))))
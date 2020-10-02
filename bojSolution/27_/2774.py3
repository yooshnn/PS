from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    print(len(set(input())))
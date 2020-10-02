from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    t, s = input().split()
    print(s * int(t))
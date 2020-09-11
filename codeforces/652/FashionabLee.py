from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    if n%4 == 0:
        print("YES")
    else:
        print("NO")
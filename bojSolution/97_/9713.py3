import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    n = int(input())
    if n%2: n += 1
    print((n//2)**2)
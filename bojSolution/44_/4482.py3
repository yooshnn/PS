import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    n = int(input())
    print("%d: %d %d"%(TEST+1, n, n*(n+1)*(n+2)//6))
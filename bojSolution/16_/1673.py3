import sys
input = sys.stdin.readline

while 1:
    line = input()
    if not line: break

    n, k = map(int, line.split())
    n += (n-k)//(k-1)+1

    print(n)

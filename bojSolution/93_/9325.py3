import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    b = int(input())
    for _ in range(int(input())):
        p, q = map(int, input().split())
        b += p * q
    print(b)
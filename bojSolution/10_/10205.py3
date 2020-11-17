import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    s = input().rstrip()
    n += s.count("c") - s.count("b")
    print("Data Set %d:\n%d"%(_+1, n))
    if _!=T-1: print()
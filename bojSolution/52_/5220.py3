import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    p, q = map(int, input().split())
    if bin(p).count("1")&1==q: print("Valid")
    else: print("Corrupt")
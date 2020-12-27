import sys; input = sys.stdin.readline

def rulerFunction(n):
    return bin(n)[2:][::-1].index("1") + 1

a, b = map(int, input().split())
a, b = rulerFunction(a), rulerFunction(b)
r = 0
r ^= a
r ^= b
print("A" if r!=0 else "B", "player wins")

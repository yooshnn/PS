import sys; input = sys.stdin.readline

N = int(input())
s = input().rstrip()

t = 1
A, B = 0, 0
a, b = 0, 0

for c in s:
    if c=='A':
        a += 1
        if a>=25-(0 if t!=3 else 10):
            if a>=b+2:
                A += 1
                t += 1
                a, b = 0, 0
    if c=='B':
        b += 1
        if b>=25-(0 if t!=3 else 10):
            if b>=a+2:
                B += 1
                t += 1
                a, b = 0, 0

print(A,B)
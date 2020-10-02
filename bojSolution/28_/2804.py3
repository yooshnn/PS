from sys import stdin
input = stdin.readline

A, B = input().split()
ap, bp = -1, -1

for i in range(len(A)):
    for j in range(len(B)):
        if A[i] == B[j]:
            ap, bp = i, j
            break
    if ap != -1: break

for r in range(len(B)):
    for c in range(len(A)):
        if r == bp:
            print(A[c], end="")
        elif c == ap:
            print(B[r], end="")
        else:
            print(".", end="")
    print()
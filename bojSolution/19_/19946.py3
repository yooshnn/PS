from sys import stdin
input = stdin.readline

N = int(input())

t = [1]*66

for i in range(64):
    for j in range(65):
        t[j] *= 2
        if i==j:
            t[j] -= 1

for i in range(65):
    if t[i] == N:
        print(i+1)

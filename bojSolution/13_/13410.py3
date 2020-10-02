from sys import stdin

N, K = stdin.readline().split()
N = int(N)
K = int(K) + 1
m = 0

while K > 1:
    K -= 1
    m = max(m, int(str(N * K)[::-1]))

print(m)
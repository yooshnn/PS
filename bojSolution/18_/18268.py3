import sys
input = sys.stdin.readline

K, N = map(int, input().split())
s = set()
q = set()
res = (N * (N-1))//2

cow = [*map(int, input().split())]
for i in range(N-1):
    for j in range(i+1, N):
        s.add((cow[i], cow[j]))
for _ in range(K-1):
    cow = [*map(int, input().split())]
    for i in range(N-1):
        for j in range(i+1, N):
            if (cow[j], cow[i]) in s and (cow[i], cow[j]) not in q:
                res -= 1
                q.add((cow[i], cow[j]))
print(res)
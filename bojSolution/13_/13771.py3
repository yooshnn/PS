from sys import stdin
Q=[]
N=int(stdin.readline())
for _ in range(N):
    Q.append(float(stdin.readline()))
Q=sorted(Q)
print("%.2f"%Q[1])

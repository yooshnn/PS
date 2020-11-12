import sys
input = sys.stdin.readline

M = 10000000

seive = [1 for i in range(M+1)]

def run():
    seive[0] = seive[1] = 0
    for i in range(2, M+1):
        if seive[i]==1:
            for j in range(2*i, M+1, i):
                seive[j] = 0

n, m = map(int, input().split())
run()
if seive[n] and seive[int(str(m)+str(n))]:
    print("Yes")
else:
    print("No")

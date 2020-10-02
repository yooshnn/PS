from sys import stdin
T = int(stdin.readline())

DP = [[0 for j in range(11)] for i in range(65)]
DP[1]=[1,1,1,1,1,1,1,1,1,1]
DP[2]=[1,2,3,4,5,6,7,8,9,10] #00 / 01 11 / 02 12 22 ...

for i in range(3,65):
    for j in range(10):
        DP[i][0] = 1
        DP[i][j] += sum(DP[i-1][:j+1])
        
for _ in range(T):
    n = int(input())
    print(sum(DP[n][:]))

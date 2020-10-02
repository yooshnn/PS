from sys import stdin
def input(): return stdin.readline().rstrip()

game=[[],[],[]]
score=[0]*200

n=int(input())
for _ in range(n):
    s=list(map(int,input().split()))
    for i in range(3):
        game[i].append(s[i])

for result in game:
    for i in range(n):
        if result.count(result[i])==1:
            score[i]+=result[i]

for i in score[:n]:
    print(i)
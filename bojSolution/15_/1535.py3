import sys
input = sys.stdin.readline

res = 0
def dfs(id, hp, joy):
    global res
    hp -= L[id]
    joy += J[id]

    if hp<=0: return
    if joy>res: res = joy

    for i in range(id+1, n):
        dfs(i, hp, joy)

n = int(input())
L = [*map(int, input().split())]
J = [*map(int, input().split())]
for i in range(n):
    dfs(i, 100, 0)
print(res)
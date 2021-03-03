import sys; input = sys.stdin.readline

N, M = map(int, input().split())
u, v = [*map(int, input().split())], [*map(int, input().split())]

goal = dict()
uleft, vleft = [], []
dup = []

for i in u:
    try: goal[i] += 1
    except: goal[i] = 1

for i in v:
    try:
        if goal[i]>0: goal[i] -= 1
        else: vleft.append(i)
    except:
        vleft.append(i)

for i in goal.keys():
    for j in range(goal[i]):
        uleft.append(i)

uleft.sort(reverse=True)
vleft.sort(reverse=True)
dup = [False for i in range(len(uleft))]

for i in vleft:
    for j in range(len(uleft)):
        if i>=uleft[j] and dup[j]==False:
            dup[j] = True
            break

res = []
for i in range(len(uleft)):
    if dup[i]==False: res.append(uleft[i])

print(len(res))
print(*sorted(res))
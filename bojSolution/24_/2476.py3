from sys import stdin
def calc(d):
    if d[0]==d[2]:
        return 10000+1000*d[2]
    elif d[0]==d[1] or d[1]==d[2]:
        return 1000+100*d[1]
    else: return 100*d[2]

res=0

for _ in range(int(stdin.readline())):
    li=sorted(list(map(int,stdin.readline().split())))
    res=max(res,calc(li))

print(res)
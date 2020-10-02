from sys import stdin
N,M,K=map(int,stdin.readline().split())
li=[0.0]*(N+1)
for _ in range(M):
    s=stdin.readline().split()
    for i in range(len(s)//2):
        try:
            li[int(s[i*2])]=max(li[int(s[i*2])], float(s[i*2+1]))
        except:
            li[int(s[i*2])]=float(s[i*2+1])
li=sorted(li)[-K:]
print('%.1f'%sum(li))

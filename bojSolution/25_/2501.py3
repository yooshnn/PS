from sys import stdin
def input(): return stdin.readline().rstrip()
N,F=map(int,input().split())
c=0
for i in range(1,2+N):
    if N%i==0:
        c+=1
        if c==F:
            print(i)
            break
    if i==1+N:
        print(0)
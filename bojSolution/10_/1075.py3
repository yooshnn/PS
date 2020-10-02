from sys import stdin
def input(): return int(stdin.readline().rstrip())
N,F=input(),input()
N-=N%100
while N%F!=0:
    N+=1
N=str(N)
print(N[len(N)-2:])
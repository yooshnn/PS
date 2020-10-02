from sys import stdin
def input(): return stdin.readline().rstrip()

orig=[]
new=[]

h,w=map(int,input().split())

for i in range(h):
    orig.append(input())
for i in range(h):
    new.append(input())

flag=True
for i in range(h):
    s=""
    for j in orig[i]:
        s+=(j+j)
    if s!=new[i]:
        flag=False

print(["Not Eyfa","Eyfa"][flag])
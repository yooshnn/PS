from sys import stdin
def input(): return stdin.readline().rstrip()
x,y,z=map(int,input().split())
x+=y
c=0
while 1:
    c+=x//z
    x=x//z+x%z
    if x<z: break
print(c)
from sys import stdin
import math
def input(): return stdin.readline().rstrip()
li=[]
while 1:
    del li[:]
    n=int(input())
    if n<0:break
    for i in range(1,n//2+1):
        if (n/i)%1==0:
            li.append(i)
    if sum(li)==n:
        print(n,'=',end=" ")
        for i in range(len(li)):
            print(li[i],'+ ' if i!=len(li)-1 else '',end="")
        print()

    else:
        print(n,"is NOT perfect.")
from sys import stdin
from decimal import Decimal as D

cnt=0
while True:
    cnt+=1
    li=list(map(D,stdin.readline().split()))
    if li[0]==0 and li[1]==0 and li[2]==0:
        break
    print("Triangle #",cnt,sep="")
    for q in range(3):
        if li[q]==-1:
            if q==0 or q==1:
                if li[2]**2-li[1-q]**2>=0 and (li[2]**2-li[1-q]**2).sqrt() > 0 and (li[2]**2-li[1-q]**2).sqrt() < li[2]:
                    print(chr(ord('a')+q),"=",end="")
                    print("","%.3f"%(li[2]**2-li[1-q]**2).sqrt())
                else:
                    print("Impossible.")
            else:
                if (li[0]**2+li[1]**2).sqrt() > li[0] and (li[0]**2+li[1]**2).sqrt() > li[1]:
                    print(chr(ord('a')+q),"=",end="")
                    print("","%.3f"%(li[0]**2+li[1]**2).sqrt())
    print()

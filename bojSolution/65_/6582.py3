from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

d={}
d["P"]=D(568516183680864800311884187021)
d["U"]=D(568516183680864800311884187021)
d["I"]=D(568516183680864800311884187021)

for _ in range(int(input())):
    d["P"]=D(568516183680864800311884187021)
    d["U"]=D(568516183680864800311884187021)
    d["I"]=D(568516183680864800311884187021)

    s=input().split()
    for word in s:
        if len(word)<=2: continue
        if word[1]=="=":
            parse=""
            for cha in word[2:]:
                m_,k_,M_=False,False,False
                if cha>'9':
                    if cha=="m":
                        m_=True
                    elif cha=="k":
                        k_=True
                    elif cha=="M":
                        M_=True
                    break
                parse+=cha
            r=D(parse)
            if m_:
                r/=1000
            if k_:
                r*=1000
            if M_:
                r*=1000000
            d[word[0]]=r

    print("Problem #",_+1,sep="")
    if d["P"]==568516183680864800311884187021:
        print("P=","%.2f"%float(d["U"]*d["I"]),"W",sep="")
    elif d["U"]==568516183680864800311884187021:
        print("U=","%.2f"%float(d["P"]/d["I"]),"V",sep="")
    elif d["I"]==568516183680864800311884187021:
        print("I=","%.2f"%float(d["P"]/d["U"]),"A",sep="")
    print()
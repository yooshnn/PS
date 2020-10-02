c=0
while 1:
    c+=1
    s=input()
    if s.split()[1]=='E':break
    print("Case ",c,": ",str(eval(s)).lower(),sep="")
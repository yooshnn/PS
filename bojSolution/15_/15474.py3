a,b,c,d,e=map(int,input().split())
res1 = ((a-1)//b+1)*c
res2 = ((a-1)//d+1)*e
print(min(res1,res2))
from sys import stdin
a=1000-int(stdin.readline())
res=0

res+=a//500
a-=(a//500)*500
res+=a//100
a-=(a//100)*100
res+=a//50
a-=(a//50)*50
res+=a//10
a-=(a//10)*10
res+=a//5
a-=(a//5)*5
res+=a//1
a-=(a//1)*1
print(res)
n=int(input())
r=0
for i in range(1,1+n//2):
    if n%i==0: r+=i
print(r+n)
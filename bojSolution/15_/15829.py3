l=int(input())
s=input()
res=0
for i in range(l):
    res+=(ord(s[i])-ord('a')+1)*(31**i)
print(res%1234567891)
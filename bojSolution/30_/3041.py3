s=""
r=0
for _ in range(4):
    s+=input().rstrip()
for i in range(16):
    if s[i]=='.': continue
    d=ord(s[i])-(65+i)
    r+=abs((ord(s[i])-65)//4-i//4)+abs((ord(s[i])-65)%4-i%4)
print(r)
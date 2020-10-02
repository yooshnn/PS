f=[int(x) for x in input().split()]
f[1]-=1
s=input()
print(s[:f[1]],end="")
print(s[f[1]:f[2]][::-1],end="")
print(s[f[2]:],end="")
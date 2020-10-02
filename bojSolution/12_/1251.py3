from sys import stdin
s=stdin.readline().rstrip()
l=[]
for i in range(1,len(s)-1):
    for j in range(i+1,len(s)):
        l.append(s[0:i][::-1]+s[i:j][::-1]+s[j:][::-1])
print(sorted(l)[0])
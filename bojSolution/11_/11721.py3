s=input()
p=0
while p<len(s):
    print(s[p:min(len(s),p+10)])
    p+=10
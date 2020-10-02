from sys import stdin
a=int(stdin.readline())
s=stdin.readline()
score=0
for i in range(a):
    score+=ord(s[i])-ord("A")+1
print(score)

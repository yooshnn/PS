from sys import stdin
n=int(stdin.readline())
s=stdin.readline()
bonus=0
score=0
for i in range(1,n+1):
    if s[i-1]=='O':
        score+=i+bonus
        bonus+=1
    else:
        bonus=0
print(score)
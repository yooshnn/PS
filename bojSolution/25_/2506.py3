n=input()
li=list(map(int,input().split()))
streak=0
score=0
for i in range(int(n)):
    if li[i]==1:
        streak+=1
        score+=streak
    else:
        streak=0
print(score)
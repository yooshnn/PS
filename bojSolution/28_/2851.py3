from sys import stdin
def input(): return int(stdin.readline().rstrip())
m=[]
for _ in range(10):
    m.append(input())
s=0
for i in range(10):
    if abs(s-100)>=abs(s+m[i]-100):
        s+=m[i]
    else:
        break
print(s)
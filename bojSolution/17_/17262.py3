p=9e6;q=0
for _ in range(int(input())):s,e=map(int,input().split());q=max(q,s);p=min(e,p)
print(max(0,q-p))
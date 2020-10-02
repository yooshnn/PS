a=int(input())
b=list(map(int,input().split()))
print(sum(b) if sum(b)<a/2 else a-sum(b))
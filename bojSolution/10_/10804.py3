import sys; input=sys.stdin.readline

s = [x for x in range(1, 21)]
for i in range(10):
    p, q = map(int, input().split())
    p -= 1; q -= 1;
    for j in range((1+q-p)//2):
        t=s[p+j]; s[p+j]=s[q-j]; s[q-j]=t
print(*s)

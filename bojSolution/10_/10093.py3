import sys; input=sys.stdin.readline

a, b = map(int, input().split())
print(max(0,max(a,b)-min(a,b)-1))
for i in range(min(a,b)+1, max(a,b)):
    print(i, end=" ")

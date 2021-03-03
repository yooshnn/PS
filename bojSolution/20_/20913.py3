N = int(input())
s = [*map(int, input().split())]
for i, c in enumerate(s): print(str(100+i)+"0"*c)
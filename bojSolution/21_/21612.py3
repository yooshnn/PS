import sys; input = sys.stdin.readline

r = 5*int(input())-500
print(r+100)
if r>0: print(-1)
elif r<0: print(1)
else: print(0)
import sys; input = sys.stdin.readline

p = set()
s = input().rstrip().split()

for c in s:
    p.add(c)
   
print("yes" if len(p)==len(s) else "no")
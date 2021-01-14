import sys; input = sys.stdin.readline

a = [*map(int, input().split())]
b = [*map(int, input().split())]

good = True

for i in range(5):
    if a[i]^b[i]==0:
        good = False

print("Y" if good else "N")

import sys
input = sys.stdin.readline

n, l = map(int, input().split())
box = [*map(int, input().split())]
psum = [0 for i in range(n)]

for i in range(n):
    if i==0:
        psum[n-1] = box[n-1]
    else:
        psum[n-1-i] = psum[n-i]+box[n-1-i]

good = True
for i in range(1, n):
    if not (box[i-1]-l<psum[i]/(n-i)<box[i-1]+l):
        good = False
        break

print("stable" if good else "unstable")

import sys; input = sys.stdin.readline

lim = [0 for i in range(12)]
res = []
n, m = map(int, input().split())

while 1:
	i, j = input().split(); i = int(i)
	if i==0: break

	if lim[i]==m: continue
	lim[i] += 1

	res.append([1-(i&1),i,len(j),j])

for x in sorted(res):
	print(x[1], x[3])

N = int(input())
res = []

for i in range(N//2):
    res.append("1")
    res.append("2")

if N%2 == 1:
    res.append("3")

print(" ".join(res))
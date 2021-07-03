import sys; input = sys.stdin.readline

n = int(input())
b = bin(n)[2:][::-1]
res = 0
for i in range(len(b)):
    if b[i]=="1":
        res += 3**i
print(res)
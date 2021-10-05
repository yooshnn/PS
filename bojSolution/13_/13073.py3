ans = [(0, 0, 0)]
p = 1
for i in range(1, 10001):
    ans.append((ans[-1][0] + i, ans[-1][1] + p, ans[-1][2] + p + 1))
    p += 2

for TEST in range(int(input())):
    print(*ans[int(input())])
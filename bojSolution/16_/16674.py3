import sys; input = sys.stdin.readline

cnt = [0 for i in range(10)]
s = input().rstrip()

for c in s:
    cnt[ord(c)-ord('0')] += 1

res = 0
if all(cnt[int(i)]==0 for i in "345679"):
    res = 1
    if all(cnt[int(i)]!=0 for i in "0128"): res = 2
    if res==2 and cnt[0]==cnt[1] and cnt[0]==cnt[2] and cnt[0]==cnt[8]: res = 8

print(res)
k = int(input())
me, friend = input(), input()
s, r = 0, 0
for i, m in enumerate(me):
    s += 1 if m == friend[i] else 0

if k <= s:
    print(k + len(me) - s)
else:
    print(s + len(me) - k)
from sys import stdin
def input(): return stdin.readline().rstrip()

r = 0
a, b, c, x, y = map(int, input().split())
t = min(x, y)
T = max(x, y)

if a + b >= c * 2:
    r += t * c * 2
    if x > y:
        r += min((T - t)*(c * 2), (T - t)*a)
    else:
        r += min((T - t)*(c * 2), (T - t)*b)
else:
    r = x * a + y * b

print(r)
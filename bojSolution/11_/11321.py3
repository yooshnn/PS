import sys; input = sys.stdin.readline
import collections

while 1:
    s = input().rstrip()
    if s=="0": break
    s = [*map(int, s.split("+"))]
    suffix = [collections.deque() for x in range(10)]
    for i in range(len(s)):
        suffix[s[i]%10].append(s[i])
    res = [str(i) for i in suffix[0]]
    left = []
    for i in range(1, 6):
        while suffix[i] and suffix[10-i]:
            res.append(str(suffix[i].pop()))
            if suffix[10-i]: res.append(str(suffix[10-i].pop()))
        while suffix[i]:
            left.append(str(suffix[i].pop()))
        while suffix[10-i]:
            left.append(str(suffix[10-i].pop()))
    res.extend(left)
    print("+".join(res))

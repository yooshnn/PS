import sys; input = sys.stdin.readline

a = [0 for _ in range(26)]
s, t = input().rstrip(), input().rstrip()

for c in s: a[ord(c)-ord('a')] += 1
for c in t: a[ord(c)-ord('a')] -= 1

print("YES" if all(a[i]>=0 for i in range(26)) else "NO")
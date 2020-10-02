s = [input().rstrip() for x in range(int(input()))]
for c in s:
    if c[::-1]in s:print(len(c),c[len(c)//2]);break
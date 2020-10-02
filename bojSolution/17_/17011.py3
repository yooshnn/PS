from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s = input()
    cnt = 0
    pre = s[0]
    for i in range(len(s)):
        if s[i] == pre:
            cnt += 1
        else:
            print(cnt, pre, end=" ")
            pre = s[i]
            cnt = 1
    print(cnt, pre, end=" ")
    print()
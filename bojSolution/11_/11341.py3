import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().split()
    for c in s:
        res = ""
        if c[0] in "aiueoy":
            res = c+"yay"
        else:
            e, g = 0, 0
            for i in range(len(c)):
                e = i
                if c[i] in "aiueoy":
                    g = 1
                    break
            if g: res = c[e:]+c[:e]+"ay"
            else: res = c+"ay"
        print(res, end=" ")
    print()

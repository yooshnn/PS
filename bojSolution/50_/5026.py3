import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s=input().rstrip()
    if s=="P=NP":
        print("skipped")
        continue
    print(eval(s))

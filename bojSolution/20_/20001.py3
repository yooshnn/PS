from sys import stdin
input = stdin.readline

q = 0
while 1:
    s = input().rstrip()
    if s == "고무오리 디버깅 끝": break;
    if s == "문제":
        q += 1
    elif s == "고무오리":
        q += 2 if q == 0 else -1
print("고무오리야 사랑해" if q == 0 else "힝구")
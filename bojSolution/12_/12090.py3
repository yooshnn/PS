import sys
input = sys.stdin.readline

s = input().rstrip()
for c in s:
    print("ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ"[(ord(c)-44032)//(21*28)], end="")
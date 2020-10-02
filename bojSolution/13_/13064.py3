from sys import stdin
T=int(stdin.readline())

def isgood(str):
    if len(str) != 8:
        return False
    if ord(str[0]) < 49 or ord(str[0]) >57:
        return False
    if str[0] != str[1]:
        return False
    if ord(str[2]) < 49 or ord(str[2]) >57:
        return False
    if ord(str[3]) < 49 or ord(str[3]) >57:
        return False
    if ord(str[4]) < 65 or ord(str[4]) >90:
        return False
    if ord(str[5]) < 49 or ord(str[5]) >57:
        return False
    if ord(str[6]) < 49 or ord(str[6]) >57:
        return False
    if ord(str[7]) < 49 or ord(str[7]) >57:
        return False
    return True

for _ in range(T):
    c=stdin.readline()[:-1]
    if isgood(c):
        print(c)

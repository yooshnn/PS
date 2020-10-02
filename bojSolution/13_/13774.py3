from sys import stdin

def ispal(str):
    for q in range(len(str)//2):
        if str[q]!=str[len(str)-1-q]:
            return False
    return True

while True:
    s=stdin.readline()[:-1]
    if s=="#":
        break
    found = False
    for i in range(len(s)):
        if i==0:
            if ispal(s[1:]):
                print(s[1:])
                found = True
                break
        elif i==len(s)-1:
            if ispal(s[:len(s)-1]):
                print(s[:len(s)-1])
                found = True
                break
        else:
            if ispal(s[:i]+s[i+1:]):
                print(s[:i]+s[i+1:])
                found = True
                break
    if not found:
        print("not possible")

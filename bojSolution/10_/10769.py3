from sys import stdin
def input(): return stdin.readline().rstrip()

s=input()
happy=s.count(":-)")
sad=s.count(":-(")

if happy==0 and sad==0:
    print("none")
elif happy==sad:
    print("unsure")
elif happy>sad:
    print("happy")
else:
    print("sad")
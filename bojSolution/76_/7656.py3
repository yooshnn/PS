import sys
import re
input = sys.stdin.readline

q = []
s = re.split('([?.])+', input())

for i in range(0, len(s)-1, 2):
    t = s[i].strip()
    if len(t)<7: continue
    if s[i+1]=="?" and t[:7]=="What is":
        tt = " ".join(t.split()[2:])
        if (tt == ""): print("Forty-two is.")
        else: print("Forty-two is ", tt, ".", sep="")

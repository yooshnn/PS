from sys import stdin
def input(): stdin.readline()
s=""
for line in stdin:
    s+=line
li=[]
for i in range(26):
    li.append(s.count(chr(97+i)))
for i in range(26):
    if li[i]==max(li):
        print(chr(97+i),end="")
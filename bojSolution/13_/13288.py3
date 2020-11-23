import sys
input = sys.stdin.readline

d=["@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\/[]","[]\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"]
s = input().rstrip()
for c in s:
    if c.isalpha(): print(d[ord(c.lower())-ord("a")], end="")
    else: print(c, end="")
from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    line=stdin.readline()
    if not line: break
    low,upp,num,bln=0,0,0,0
    for i in line:
        if ord(i)>=ord('a') and ord(i)<=ord('z'):
            low+=1
        if ord(i)>=ord('A') and ord(i)<=ord('Z'):
            upp+=1
        if ord(i)>=ord('0') and ord(i)<=ord('9'):
            num+=1
        if i==' ':
            bln+=1
    print(low,upp,num,bln)
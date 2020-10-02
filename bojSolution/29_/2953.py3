from sys import stdin
no=0
scr=0
for i in range(5):
    s = [int(x) for x in stdin.readline().split()]
    if sum(s)>scr:
        scr = sum(s)
        no = i+1
print(no,scr)

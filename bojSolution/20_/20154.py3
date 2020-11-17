import sys
input = sys.stdin.readline

dat = [3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1]
li = [[], []]
call = 0

for c in input().rstrip():
    li[0].append(dat[ord(c)-ord('A')])

while 1:
    call = 1-call
    for i in range(0, len(li[1-call]), 2):
        li[call].append(li[1-call][i] + (li[1-call][i+1] if i+1<len(li[1-call]) else 0))
    li[1-call].clear()
    if len(li[call])==1:
        print(["You're the winner?", "I'm a winner!"][li[call][0]%2])
        break
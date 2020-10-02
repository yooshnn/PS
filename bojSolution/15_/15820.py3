from sys import stdin

s1, s2 = map(int, stdin.readline().split())

status = 0

for _ in range(s1):
    sol, ans = map(int, stdin.readline().split())
    if sol != ans:
        status = 1

for _ in range(s2):
    sol, ans = map(int, stdin.readline().split())
    if sol != ans:
        if status==0:
            status = 2
        else:
            status = 1

if status==0:
    print("Accepted")
elif status==1:
    print("Wrong Answer")
else:
    print("Why Wrong!!!")

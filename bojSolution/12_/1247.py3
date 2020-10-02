from sys import stdin

def run():
    N=int(stdin.readline())
    res=0
    for _ in range(N):
        res+=int(stdin.readline())
    if res<0:
        print("-")
    elif res>0:
        print("+")
    else:
        print("0")

run()
run()
run()
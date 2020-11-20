import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    q = input().split()
    q[0] = q[0].replace("t", "1").replace("f", "0").replace("!", "1-")
    print(TEST+1, ": ", "Good brain" if ["f","t"][eval(q[0])] == q[2] else "Bad brain", sep="")

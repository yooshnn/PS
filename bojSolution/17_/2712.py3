import sys
input = sys.stdin.readline

for _ in range(int(input())):
    i, j = input().split(); i = float(i)
    if j=="kg":
        print("%.4f"%(i*2.2046), "lb")
    if j=="lb":
        print("%.4f"%(i*0.4536), "kg")
    if j=="l":
        print("%.4f"%(i*0.2642), "g")
    if j=="g":
        print("%.4f"%(i*3.7854), "l")
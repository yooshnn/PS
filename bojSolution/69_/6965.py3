n = int(input())
temp = []
for i in range(n):
    temp = input().split()
    for uj in range(len(temp)):
        if len(temp[uj]) == 4:
            temp[uj] = "****"
    print(" ".join(temp))
    print()
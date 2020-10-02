N=int(input())
b=int(input())
if N>=6:
    print("Love is open door")
else:
    for _ in range(N-1):
        b=1-b
        print(b)
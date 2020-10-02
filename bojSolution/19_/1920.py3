N = int(input())
A = sorted(list(map(int,input().split())))
M = int(input())
B = list(map(int,input().split()))

def s(arr, num):
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (low + high) // 2;

        if arr[mid] == num:
            return True;
        elif arr[mid] > num:
            high = mid - 1;
        else:
            low = mid + 1;
    
    return False;

for i in B:
    if s(A,i):
        print(1)
    else:
        print(0)
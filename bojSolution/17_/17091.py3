import sys
input = sys.stdin.readline

num = ["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","half"]
h, m = int(input()), int(input())

if m == 0:
    print(num[h-1],"o' clock")
elif m <= 30:
    if m == 1:
        print("one minute past",num[h-1])
    elif m == 30:
        print("half past",num[h-1])
    else:
        print(num[m-1],"minutes past" if m!=15 else "past",num[h-1])
else:
    if m == 59:
        print("one minute to",num[h%12])
    else:
        print(num[60-m-1],"minutes to" if m!=45 else "to",num[h%12])

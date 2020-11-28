import sys
input = sys.stdin.readline

for i in range(100, 500):
    for j in range(100, 1000):
        if str(i)[-1] == str(j)[0]:
            if int(str(j)[1:]) == 0: continue
            if i in [111,222,333,444,555,666,777,888,999]: continue
            if i/j==int(str(i)[:2])/int(str(j)[1:]):
                print(i,"/",j,"=",str(i)[:2],"/",int(str(j)[1:]))

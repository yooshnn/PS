from sys import stdin

k,l=stdin.readline().split()
k = int(k)
l = int(l)
dic = {}

for i in range(l):
    no = stdin.readline()[:8]
    dic[no] = i

dic = sorted(dic.items(),key=lambda kv: kv[1])

for i in range(k):
    try:
        print(dic[i][0])
    except:
        print("",end="")
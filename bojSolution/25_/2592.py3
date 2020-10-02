from collections import Counter
li=[]
for _ in range(10):
    li.append(int(input()))
cnt=Counter(li)
print(sum(li)//10)
print(cnt.most_common(1)[0][0])
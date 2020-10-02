from sys import stdin
s=stdin.readline()[:-1]
flag=True
if len(s)==1:
    print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!")
else:
    d=int(s[1])-int(s[0])
    for i in range(2,len(s)):
        if int(s[i])-int(s[i-1])!=d:
            flag=False
    if flag==True:
        print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!")
    else:
        print("흥칫뿡!! <(￣ ﹌ ￣)>")

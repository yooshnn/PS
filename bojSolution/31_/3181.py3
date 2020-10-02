x=['i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili']
s=input().split()
r=s[0][0].upper()
if len(s)>1:
    for i in s[1:]:
        if i not in x:
            r+=i[0].upper()
print(r)
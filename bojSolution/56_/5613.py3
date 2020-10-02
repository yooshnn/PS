s=int(input())
o=""
while True:
    z=str(input())
    if z=="=": break
    if z.isdigit(): s=eval(str(s)+o+z)
    else: o=z if z!="/" else "//"
print(s)

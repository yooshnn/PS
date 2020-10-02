s = input()
t = input()
f = 0

def fun(z):
    global f
    if len(s) == len(z):
        if s == z:
            f = 1
        return
    if z[0]=='A' and z[-1]=='B':
        return
    
    if z[-1]=='A':
        fun(z[:-1])
    if z[0]=='B':
        fun(z[1:][::-1])

fun(t)

if f==0:
    print(0)
else:
    print(1)
c = [None]*3
d = {'black':0,'brown':1,'red':2,'orange':3,'yellow':4,'green':5,'blue':6,'violet':7,'grey':8,'white':9}

c[0] = input()
c[1] = input()
c[2] = input()

print ((d[c[0]]*10+d[c[1]])*(pow(10,d[c[2]])))
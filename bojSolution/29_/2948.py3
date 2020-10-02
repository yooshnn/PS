q=['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
d,m=map(int,input().split())
p={1:4,2:0,3:0,4:3,5:5,6:1,7:3,8:6,9:2,10:4,11:0,12:2}
print(q[(p[m]+(d-1))%7])
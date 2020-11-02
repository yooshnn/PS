import sys
input = sys.stdin.readline

Re, Pt, Cc, Ea, Tb, Cm, Ex, T = 0, 0, 0, 0, 0, 0, 0, 0

while 1:
    s = input()
    if not s: break
    Re += s.count("Re")
    Pt += s.count("Pt")
    Cc += s.count("Cc")
    Ea += s.count("Ea")
    Tb += s.count("Tb")
    Cm += s.count("Cm")
    Ex += s.count("Ex")
    T += len(s.split())

print("Re",Re,"%.2f"%(Re/T))
print("Pt",Pt,"%.2f"%(Pt/T))
print("Cc",Cc,"%.2f"%(Cc/T))
print("Ea",Ea,"%.2f"%(Ea/T))
print("Tb",Tb,"%.2f"%(Tb/T))
print("Cm",Cm,"%.2f"%(Cm/T))
print("Ex",Ex,"%.2f"%(Ex/T))
print("Total",T,"1.00")
n = str(bin(int(input())))[2:]
print("01"[n[0]=="1" and n.count("1")==1])
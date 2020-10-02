s = input()
if s[0] != "0":
    print(s)
elif s[1] == "x":
    print(int(s, 16))
else:
    print(int(s, 8))